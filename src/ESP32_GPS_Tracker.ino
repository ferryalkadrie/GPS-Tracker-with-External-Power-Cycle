#include <HardwareSerial.h>
#include <esp_task_wdt.h>

// --- Hardware Pin Configuration ---
#define SIM800_RX 16
#define SIM800_TX 17
#define GPS_RX 13       
#define GPS_TX 14       
#define SIM800_RST 25
#define RELAY_PIN 18

// --- System Constants ---
#define WDT_TIMEOUT 8 
String apiKey = "A6G5KQN36UBMB4E9";

HardwareSerial sim800(1);    
HardwareSerial gpsSerial(2);  

String nmeaLine = "";
float latitude = 0.0;
float longitude = 0.0;
bool gpsDataValid = false;
unsigned long lastSendTime = 0;
unsigned long lastCheckTime = 0;
unsigned long lastHardReset = 0;
unsigned long lastRelayOnTime = 0;
bool relayActive = false;

float nmeaToDecimal(String raw, String dir) {
  if (raw.length() < 6) return 0.0;
  float val = raw.toFloat();
  int degrees = (int)(val / 100);
  float minutes = val - (degrees * 100);
  float decimal = degrees + minutes / 60.0;
  if (dir == "S" || dir == "W") decimal = -decimal;
  return decimal;
}

// --- NMEA Parsing Engine (Community Edition) ---
void parseNMEA(String nmea) {
  if (nmea.startsWith("$GPGGA")) {
    String parts[15];
    int index = 0;
    for (int i = 0; i < 15; i++) {
      int commaIndex = nmea.indexOf(',', index);
      if (commaIndex == -1) {
        parts[i] = nmea.substring(index);
        break;
      } else {
        parts[i] = nmea.substring(index, commaIndex);
        index = commaIndex + 1;
      }
    }

    if (parts[2].length() > 0 && parts[4].length() > 0) { 
      latitude = nmeaToDecimal(parts[2], parts[3]); 
      longitude = nmeaToDecimal(parts[4], parts[5]); 
      gpsDataValid = true; 
    } else { 
      gpsDataValid = false; 
    } 
  }
}

void sendToThingSpeak(float lat, float lon) {
  Serial.println("Transmitting telemetry data...");
  sendAT("AT", 500);
  sendAT("AT+CIPSHUT", 1000);
  sendAT+CIPMUX=0", 1000);
  sendAT("AT+CSTT=\"internet\"", 2000); 
  sendAT("AT+CIICR", 3000);
  sendAT("AT+CIFSR", 2000);
  sendAT("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"", 6000);
  sendAT("AT+CIPSEND", 2000);

  String str = "GET /update?api_key=" + apiKey +
               "&field1=" + String(lat, 6) +
               "&field2=" + String(lon, 6) +
               " HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n";

  sim800.print(str);
  sim800.write(26); 
  delayWithWDT(5000);
  sendAT("AT+CIPSHUT", 1000);
}

void sendAT(const char* cmd, unsigned long ms) {
  sim800.println(cmd);
  delayWithWDT(ms);
}

void delayWithWDT(unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    esp_task_wdt_reset();
    delay(10);
  }
}

void checkModem() {
  sim800.println("AT");
  delayWithWDT(500);
  if (sim800.available()) {
    String reply = sim800.readString();
    if (reply.indexOf("OK") == -1) resetSIM800();
  } else {
    resetSIM800();
  }
}

void resetSIM800() {
  digitalWrite(SIM800_RST, HIGH);
  delayWithWDT(1000);
  digitalWrite(SIM800_RST, LOW);
  delayWithWDT(5000);
}

void setup() {
  Serial.begin(115200);
  sim800.begin(9600, SERIAL_8N1, SIM800_RX, SIM800_TX);
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX); 

  pinMode(SIM800_RST, OUTPUT);
  digitalWrite(SIM800_RST, HIGH);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  esp_task_wdt_init(WDT_TIMEOUT, true);
  esp_task_wdt_add(NULL);
}

void loop() {
  esp_task_wdt_reset();

  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    if (c == '\n') {
      parseNMEA(nmeaLine);
      nmeaLine = "";
    } else if (c != '\r') {
      nmeaLine += c;
    }
  }

  if (gpsDataValid && millis() - lastSendTime > 120000UL) {
    lastSendTime = millis();
    sendToThingSpeak(latitude, longitude);
  }

  if (millis() - lastCheckTime > 120000UL) {
    lastCheckTime = millis();
    checkModem();
  }

  if (millis() - lastHardReset > 7200000UL) {
    lastHardReset = millis();
    resetSIM800();
  }

  // --- Base Time-Based Power Cycle (Community Edition Failsafe) ---
  if (!relayActive && millis() - lastRelayOnTime > 3600000UL) {
    digitalWrite(RELAY_PIN, HIGH);
    relayActive = true;
    lastRelayOnTime = millis();
  }

  if (relayActive && millis() - lastRelayOnTime > 10000UL) {
    digitalWrite(RELAY_PIN, LOW);
    relayActive = false;
  }

  while (sim800.available()) {
    Serial.write(sim800.read());
  }
}
