# ESP-01 Firmware Documentation

## Overview

The ESP-01 (ESP8266) functions as an independent low-power controller responsible for managing the external hardware power cycle of the ESP32.

Unlike the main controller, the ESP-01 does not process GPS or GSM data. Its only responsibility is ensuring the ESP32 can recover automatically from unexpected failures.

---

# Main Responsibilities

The ESP-01 firmware performs the following tasks:

- Wake from Deep Sleep
- Enable ESP32 power
- Wait for startup stabilization
- Perform scheduled hardware power cycle
- Return to Deep Sleep
- Minimize battery consumption

---

# Hardware Connections

| ESP-01 Pin | Connected Device | Function |
|------------|------------------|----------|
| GPIO2 | AO3400 Gate | Controls ESP32 Ground |
| GPIO16 | RST | Deep Sleep Wake-up |
| VCC | 3.3V | Power |
| GND | Common Ground |

---

# Working Principle

1. ESP-01 wakes from Deep Sleep.
2. GPIO2 is driven HIGH, allowing the ESP32 to operate.
3. After the scheduled interval, GPIO2 is driven LOW.
4. The AO3400 disconnects the ESP32 ground for approximately **2–3 seconds**.
5. GPIO2 returns HIGH.
6. The ESP32 performs a clean hardware boot.
7. ESP-01 immediately returns to Deep Sleep.

---

# Deep Sleep

Deep Sleep significantly reduces power consumption while maintaining the scheduled wake-up capability.

Example:

```cpp
ESP.deepSleep(DEEP_SLEEP_TIME_US);
```

---

# Wake-Up Method

The ESP-01 requires a hardware modification:

```
GPIO16
   │
   ▼
RST
```

This connection allows the ESP8266 to wake automatically after the Deep Sleep timer expires.

---

# Advantages

- Independent controller
- Extremely low power consumption
- Reliable hardware recovery
- Automatic restart scheduling
- No RTC module required

---

# Power Consumption

Most of the time, the ESP-01 remains in Deep Sleep.

It only wakes briefly to execute the power-cycle sequence before returning to sleep.

This minimizes total battery usage.

---

# Design Philosophy

Separating the power controller from the main controller improves overall system reliability.

Even if the ESP32 firmware becomes unresponsive, the ESP-01 continues operating and is able to restore the system automatically.

---

# Next Document

Continue reading:

**docs/07_SIM800L.md**
