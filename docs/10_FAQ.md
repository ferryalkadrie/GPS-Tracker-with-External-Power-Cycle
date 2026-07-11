# Frequently Asked Questions (FAQ)

## Why use an ESP-01?

The ESP-01 independently manages the hardware power cycle, allowing automatic recovery even if the ESP32 becomes unresponsive.

---

## Why use an AO3400 MOSFET?

The AO3400 provides an electronic method for temporarily disconnecting the ESP32 ground, enabling a complete hardware restart.

---

## Why not only use the ESP32 watchdog?

A watchdog can recover from many software failures, but an external controller adds another layer of resilience for long-term unattended operation.

---

## Can another GSM module be used?

Yes.

The firmware can be adapted for other AT command compatible GSM modules.

---

## Can another GPS module be used?

Yes.

Any UART-based GPS receiver that outputs standard NMEA sentences can be integrated with minor firmware changes.

---

## Is this project open source?

Yes.

The project is intended for educational, research, and personal development purposes.

---

# License

Please refer to the LICENSE file included in this repository for licensing information.
