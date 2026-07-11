# ESP32 Firmware Documentation

## Overview

The ESP32 is the primary controller responsible for GPS acquisition, GSM communication, data processing, and cloud connectivity.

It continuously collects GPS coordinates, monitors the GSM modem, uploads telemetry to ThingSpeak, and cooperates with the external ESP-01 power controller for long-term autonomous operation.

---

# Main Responsibilities

The ESP32 firmware performs the following tasks:

- Initialize all hardware peripherals
- Read GPS data from the Neo-6M module
- Parse NMEA sentences
- Monitor GPS status
- Communicate with the SIM800L GSM module
- Upload GPS coordinates to ThingSpeak
- Monitor modem health
- Perform hardware reset of SIM800L when necessary
- Enter Deep Sleep when configured

---

# Hardware Interfaces

| Peripheral | Interface | ESP32 GPIO |
|------------|-----------|-----------:|
| GPS Neo-6M | UART2 | GPIO4 / GPIO5 |
| SIM800L | UART1 | GPIO16 / GPIO17 |
| SIM800L Reset | Digital Output | GPIO25 |

---

# Firmware Workflow

```
System Boot
      │
      ▼
Initialize UART
      │
      ▼
Initialize GPS
      │
      ▼
Initialize SIM800L
      │
      ▼
Acquire GPS Fix
      │
      ▼
Parse Coordinates
      │
      ▼
Upload to ThingSpeak
      │
      ▼
Monitor SIM800L
      │
      ▼
Wait for Next Cycle
```

---

# GPS Processing

The ESP32 receives NMEA sentences from the GPS module through UART2.

The firmware extracts:

- Latitude
- Longitude
- GPS validity

Only valid GPS coordinates are transmitted to the cloud.

---

# GSM Communication

The SIM800L module communicates using AT commands over UART1.

Typical sequence:

1. Initialize modem
2. Configure APN
3. Establish TCP connection
4. Send HTTP GET request
5. Close connection

---

# ThingSpeak Upload

The firmware uploads the following information:

| Field | Description |
|--------|-------------|
| Field 1 | Latitude |
| Field 2 | Longitude |

The upload interval can be adjusted according to application requirements.

---

# Watchdog

The firmware periodically resets the ESP32 watchdog timer to prevent unexpected system hangs.

If the application becomes unresponsive, the watchdog automatically restarts the ESP32.

---

# SIM800L Monitoring

The firmware periodically sends:

AT

If the modem does not respond correctly, a hardware reset is performed using GPIO25.

This improves GSM communication reliability during long-term deployments.

---

# Error Recovery

Recovery mechanisms include:

- GPS validation
- GSM communication retry
- SIM800L hardware reset
- External hardware power cycle (ESP-01)

These multiple recovery layers improve overall system robustness.

---

# Next Document

Continue reading:

**docs/06_ESP01_Firmware.md**
