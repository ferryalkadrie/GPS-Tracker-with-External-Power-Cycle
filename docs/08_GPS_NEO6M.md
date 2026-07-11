# GPS Neo-6M Module

## Overview

The GPS Neo-6M provides real-time geographic coordinates for the tracking system.

---

# Features

- GPS Positioning
- NMEA Output
- UART Interface
- Low Power Operation

---

# ESP32 Connection

| GPS | ESP32 |
|------|-------|
| TX | GPIO4 |
| RX | GPIO5 |
| VCC | 3.3V / 5V |
| GND | GND |

---

# Parsed Data

The firmware extracts:

- Latitude
- Longitude

Only valid GPS data is uploaded.

---

# NMEA Sentences

The firmware currently parses:

- GPGGA

Additional NMEA sentences can be added in future firmware versions.

---

## Next Document

Continue reading:

**docs/09_Troubleshooting.md**
