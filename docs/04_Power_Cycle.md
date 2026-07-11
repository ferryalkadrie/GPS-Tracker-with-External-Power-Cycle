# External Power Cycle System

## Overview

One of the key features of this project is the implementation of an **external hardware power-cycle controller**.

Instead of relying solely on software watchdogs or Deep Sleep, the ESP32 is periodically restarted by an independent ESP-01 controller.

This approach significantly improves long-term reliability for unattended GPS tracking applications.

---

# Why External Power Cycle?

During long-term testing, embedded systems may occasionally become unresponsive due to unexpected software or communication issues.

Possible causes include:

- GPS communication timeout
- GSM network instability
- Serial communication errors
- Memory fragmentation
- Unexpected firmware lock-up

A software reset is not always sufficient to recover from these conditions.

An external hardware reset provides a clean restart of the entire ESP32 system.

---

# System Components

| Device | Function |
|---------|----------|
| ESP32 | Main GPS tracker |
| ESP-01 | Independent power controller |
| AO3400 | Electronic power switch |
| SIM800L | GSM communication |
| GPS Neo-6M | GPS receiver |

---

# Working Principle

1. ESP32 starts normally.
2. GPS data is acquired.
3. SIM800L sends location data.
4. ESP32 enters Deep Sleep.
5. ESP-01 disconnects the ESP32 ground using the AO3400 MOSFET.
6. ESP32 remains powered off for approximately **2–3 seconds**.
7. ESP-01 reconnects the ESP32 ground.
8. ESP32 performs a fresh power-on boot.
9. ESP-01 enters Deep Sleep until the next scheduled cycle.

---

# Power Cycle Flow

```text
ESP-01 Wake
      │
      ▼
GPIO2 HIGH
      │
      ▼
ESP32 Powered
      │
      ▼
GPS Reading
      │
      ▼
Send Data
      │
      ▼
ESP32 Sleep
      │
      ▼
GPIO2 LOW
      │
      ▼
AO3400 Disconnects Ground
      │
      ▼
Wait 2–3 Seconds
      │
      ▼
GPIO2 HIGH
      │
      ▼
ESP32 Reboots
      │
      ▼
ESP-01 Deep Sleep
```

---

# Why Use an ESP-01?

The ESP-01 operates independently from the ESP32.

Even if the ESP32 firmware becomes unresponsive, the ESP-01 continues running and can still perform the scheduled hardware power cycle.

This separation increases the overall reliability of the system.

---

# Advantages

- Automatic hardware recovery
- Independent watchdog controller
- Improved long-term stability
- Reduced maintenance
- Low power consumption
- Fully autonomous operation

---

# Design Considerations

The AO3400 MOSFET is configured as a **low-side switch**, temporarily disconnecting the ESP32 ground.

This design is intended for short-duration hardware resets rather than long-term power isolation.

---

# Future Improvements

Possible enhancements include:

- RTC-based scheduling
- Battery voltage monitoring
- Solar charging support
- OTA firmware updates
- MQTT integration
- Home Assistant integration

---

## Next Document

Continue reading:

**docs/05_ESP32_Firmware.md**
