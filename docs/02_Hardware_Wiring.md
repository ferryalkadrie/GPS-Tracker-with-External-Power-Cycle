# 🔌 Hardware Wiring

## Overview

This document describes the complete hardware wiring used in the ESP32 Low-Power GPS Tracker.

The system consists of five primary modules:

- ESP32 Development Board
- ESP-01 (ESP8266)
- SIM800L GSM Module
- GPS Neo-6M
- AO3400 N-Channel MOSFET

The ESP32 is responsible for GPS processing and GSM communication, while the ESP-01 independently manages the hardware power cycle to improve long-term reliability.

---

# Hardware Architecture

```
                Li-Ion Battery
                      │
                      ▼
                  TP4056 Charger
                      │
                      ▼
              Voltage Regulator
                      │
          +-----------+-----------+
          │                       │
          │                       │
      ESP-01                  SIM800L
          │                       ▲
GPIO2     │                       │
          ▼                       │
     AO3400 MOSFET                │
          │                       │
          ▼                       │
        ESP32 ◄───────────────────┘
          ▲
          │
      GPS Neo-6M
```

---

# ESP32 Pin Mapping

| GPIO | Connected Device | Function |
|------|------------------|----------|
| GPIO16 | SIM800L TXD | UART RX |
| GPIO17 | SIM800L RXD | UART TX |
| GPIO4 | GPS Neo-6M TX | UART RX |
| GPIO5 | GPS Neo-6M RX | UART TX |
| GPIO25 | SIM800L RESET | Hardware Reset |

---

# ESP-01 Pin Mapping

| Pin | Connected Device | Function |
|-----|------------------|----------|
| GPIO2 | AO3400 Gate | Power Cycle Control |
| GPIO16 | RST | Deep Sleep Wake-up |
| VCC | 3.3V | Power Supply |
| GND | Common Ground |

> GPIO16 is modified and connected to the RST pin to enable automatic wake-up from Deep Sleep.

---

# GPS Neo-6M Wiring

| GPS Pin | ESP32 |
|----------|-------|
| TX | GPIO4 |
| RX | GPIO5 |
| VCC | 3.3V / 5V |
| GND | GND |

---

# SIM800L Wiring

| SIM800L Pin | ESP32 |
|-------------|-------|
| TXD | GPIO16 |
| RXD | GPIO17 |
| RST | GPIO25 |
| VCC | External Power Supply |
| GND | Common Ground |

> A stable power supply capable of delivering more than 2 A peak current is strongly recommended.

---

# AO3400 Wiring

The AO3400 is configured as a **low-side switch**.

| AO3400 Pin | Connected To |
|-------------|--------------|
| Gate | ESP-01 GPIO2 |
| Drain | ESP32 Ground |
| Source | System Ground |

The ESP-01 temporarily disconnects the ESP32 ground for approximately 2–3 seconds to perform a complete hardware restart.

---

# UART Configuration

## UART1

| Device | ESP32 |
|---------|-------|
| SIM800L | GPIO16 / GPIO17 |

---

## UART2

| Device | ESP32 |
|---------|-------|
| GPS Neo-6M | GPIO4 / GPIO5 |

---

# Power Distribution

```
Battery
   │
   ▼
TP4056 Charger
   │
   ▼
Voltage Regulator
   │
   ├──────────── ESP-01
   │
   ├──────────── SIM800L
   │
   └──── AO3400 ───► ESP32
```

---

# Design Notes

This project intentionally separates the power controller from the main controller.

The ESP-01 remains active while the ESP32 can be fully restarted through the AO3400 MOSFET.

Advantages of this architecture include:

- Automatic hardware recovery
- Reduced maintenance
- Improved long-term reliability
- Better battery efficiency
- Independent watchdog functionality

---

# Next Document

Continue reading:

**docs/03_ESP01_Modification.md**

This document explains the GPIO16 modification required to enable Deep Sleep wake-up on the ESP-01.
