# ESP-01 Deep Sleep Modification

## Overview

The ESP-01 (ESP8266) is used as an independent low-power controller responsible for performing hardware power cycles on the ESP32.

To enable automatic wake-up from Deep Sleep, a simple hardware modification is required.

---

# Why is the Modification Needed?

The standard ESP-01 module does not connect GPIO16 to the RESET pin.

On the ESP8266, GPIO16 is responsible for generating the wake-up signal after Deep Sleep.

Without this connection, the ESP-01 cannot wake automatically.

---

# Required Modification

Connect:

GPIO16  ─────────►  RST

This can be done using:

- Small jumper wire
- 0 Ω resistor
- Thin enamel wire

---

# Wiring

```
GPIO16
   │
   │
   ▼
RST
```

---

# Deep Sleep Flow

```
ESP-01 Boot
      │
      ▼
Power Cycle ESP32
      │
      ▼
ESP.deepSleep()
      │
      ▼
GPIO16 goes HIGH
      │
      ▼
RST Triggered
      │
      ▼
ESP-01 Boots Again
```

---

# Firmware Example

```cpp
ESP.deepSleep(DEEP_SLEEP_TIME_US);
```

Example:

```cpp
const uint64_t DEEP_SLEEP_TIME_US =
150 * 60 * 1000000ULL;
```

This example puts the ESP-01 into Deep Sleep for **150 minutes (2 hours 30 minutes)** before automatically waking up.

---

# Advantages

- Ultra-low power consumption
- Automatic wake-up
- No external timer required
- Reliable long-term operation
- Independent power-cycle controller

---

# Notes

The ESP-01 remains active only during the power-cycle sequence.

After the ESP32 has been restarted, the ESP-01 immediately returns to Deep Sleep to minimize battery consumption.

---

## Next Document

Continue reading:

**docs/04_Power_Cycle.md**
