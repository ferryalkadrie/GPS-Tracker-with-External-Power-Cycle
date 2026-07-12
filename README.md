# 📡 GPS Tracker with External Power Cycle (Community Edition)

A self-recovering, low-power GPS tracking system utilizing an ESP32 architecture combined with hardware-level failsafe recovery mechanisms.

<!-- 🚀 DISISIPKAN DI SINI (Tepat di bawah judul/deskripsi utama) -->
## 🌊 Real-World Marine Deployment (S2 Academic Research)
This system was successfully trusted and deployed as the core tracking hardware for a Master's Degree (S2) academic research project. 

- **Operational Environment:** Open sea and river estuaries (Muara Laut).
- **Power Constraints:** Powered solely by a single 18650 Li-ion battery.
- **Performance Metrics:** Exceeded the target benchmark of **24+ hours of continuous tracking** in harsh marine environments.
- **Success Criteria:** Successfully maintained low-power cycles and reliably transmitted localized telemetry data back to the server upon reaching the estuary network coverage.

---

## 🛠️ Core Features
- **Dual-MCU Hardware Failsafe:** External hardware-level power recycling to prevent system lockups in remote areas.
- **Advanced Deep Sleep:** Optimized for extreme battery longevity on a single cell.
- **Robust Telemetry:** Built-in re-connection logic for cellular data networks.

## 💎 Production Edition
This repository contains the *Community Edition*. For full commercial features, including multi-sensor arrays, cellular roaming stability enhancements, and industrial housing schematics, please contact the author.

# 🚀 ESP32 Low-Power GPS Tracker

<p align="center">

![OS](https://img.shields.io/badge/MCU-ESP32-blue?style=for-the-badge)
![Controller](https://img.shields.io/badge/Power%20Controller-ESP01-orange?style=for-the-badge)
![GPS](https://img.shields.io/badge/GPS-NEO--6M-green?style=for-the-badge)
![GSM](https://img.shields.io/badge/GSM-SIM800L-red?style=for-the-badge)
![Power](https://img.shields.io/badge/Power-AO3400-yellow?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blueviolet?style=for-the-badge)

</p>

<p align="center">

# 📡 Low Power GPS Tracker with External Power Cycle

### ESP32 • ESP-01 • SIM800L • GPS Neo-6M • AO3400 MOSFET

A modular low-power GPS tracking system featuring an external hardware power-cycle controller for maximum reliability and extended battery life.

</p>
## 📷 Prototype

<p align="center">
  <img src="images/prototype.jpg" width="700">
</p>

**Prototype Version 1**

ESP32 + ESP-01 + SIM800L + GPS Neo-6M + AO3400 MOSFET

Prototype of the complete hardware integration featuring an external power-cycle controller for long-term autonomous GPS tracking.

---

# 📖 About

This project converts a standard ESP32 GPS tracker into a highly reliable low-power embedded system by combining:

- ESP32 as the main controller
- ESP-01 as an independent power-cycle controller
- SIM800L for GSM communication
- GPS Neo-6M for positioning
- AO3400 MOSFET as an electronic power switch

Unlike conventional GPS trackers that rely solely on ESP32 Deep Sleep, this project completely removes power from the ESP32 after each transmission cycle.

The result is:

- Lower standby current
- Better battery efficiency
- Automatic recovery from crashes
- Higher long-term stability
- Reduced risk of firmware lockup

---

# ✨ Main Features

- 📍 GPS Tracking (NEO-6M)
- 📶 GSM Communication (SIM800L)
- ⚡ External Power Cycle
- 🔋 Ultra Low Power Design
- 💤 ESP32 Deep Sleep
- 🤖 ESP-01 Hardware Watchdog
- 🔄 Automatic System Recovery
- 🌐 thinghttp telegram bot 
- 📡 thingspeak Ready
- 💾 EEPROM Data Storage
- 🔧 Modular Source Code
- 📱 Remote Monitoring

---

# 🎯 Project Goals

The main objectives of this project are:

- Build an ultra low-power GPS tracker.
- Increase system reliability using hardware power cycling.
- Prevent permanent system hangs.
- Reduce battery consumption.
- Create a modular firmware architecture.
- Make the project easy to replicate.
- Provide complete open-source documentation.

---

# 🏆 Key Advantages

Compared with conventional ESP32 GPS trackers, this project offers several improvements.

| Feature | Conventional Tracker | This Project |
|----------|----------------------|--------------|
| ESP32 Deep Sleep | ✅ | ✅ |
| External Power Cycle | ❌ | ✅ |
| Independent Controller | ❌ | ✅ |
| Automatic Recovery | ❌ | ✅ |
| Battery Friendly | ⭐⭐ | ⭐⭐⭐⭐⭐ |
| Long-Term Stability | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

---

# 📂 Repository Structure

```
ESP32-LowPower-GPS-Tracker
│
├── firmware
│   ├── ESP32
│   └── ESP01
│
├── docs
│
├── hardware
│
├── images
│
├── LICENSE
│
├── .gitignore
│
└── README.md
```

---

# 📸 Project Preview

> *(Add your prototype photos here later.)*

```
images/

prototype.jpg

esp32_board.jpg

esp01_controller.jpg

wiring.jpg

block_diagram.png
```

---

➡️ Continue to **PART 1B** for the System Overview, Hardware Overview, and Working Principle.
---

# 🏗️ System Overview

This project is designed around a **dual-microcontroller architecture**.

Unlike conventional GPS trackers that rely solely on ESP32, this design separates the responsibilities into two independent controllers.

### ESP32

Responsible for:

- Reading GPS coordinates
- Managing GSM communication
- Processing sensor data
- Uploading data to the server
- Managing EEPROM storage
- Entering Deep Sleep

### ESP-01 (ESP8266)

Responsible for:

- Powering the ESP32 ON
- Powering the ESP32 OFF
- Hardware watchdog
- Deep Sleep timing
- Automatic power recovery
- Battery saving

This separation allows the ESP32 to be completely disconnected from the power supply whenever it is not required.

---

# ⚙️ System Workflow

```
Battery
   │
   ▼
ESP-01 Wakeup
   │
   ▼
AO3400 MOSFET ON
   │
   ▼
ESP32 Boot
   │
   ▼
Initialize Hardware
   │
   ├── GPS
   ├── SIM800L
   └── Sensors
   │
   ▼
Acquire GPS Fix
   │
   ▼
Transmit Data
   │
   ▼
Save Required Data
   │
   ▼
ESP32 Deep Sleep
   │
   ▼
ESP-01 Cuts Power
   │
   ▼
ESP-01 Deep Sleep
   │
   ▼
Repeat Cycle
```

---

# 🧩 Hardware Components

| Component | Description |
|-----------|-------------|
| ESP32 DevKit | Main controller |
| ESP-01 (ESP8266) | External power controller |
| GPS Neo-6M | GNSS receiver |
| SIM800L | GSM/GPRS communication |
| AO3400 MOSFET | Electronic power switch |
| TP4056 | Battery charging module |
| Li-Ion Battery | Main power source |
| Buck/Boost Converter | Voltage regulation |
| LEDs (Optional) | Status indicator |

---

# 🔌 Main Hardware Functions

## ESP32

The ESP32 performs all high-level operations, including:

- GPS acquisition
- GSM communication
- HTTP requests
- MQTT communication (optional)
- EEPROM storage
- Sensor management
- Deep Sleep

---

## ESP-01

The ESP-01 operates independently from the ESP32.

Its responsibilities include:

- Turning the ESP32 ON
- Turning the ESP32 OFF
- Executing timed wake-up cycles
- Recovering from ESP32 crashes
- Minimizing battery consumption

Even if the ESP32 becomes unresponsive, the ESP-01 can still restore normal operation by cycling the power.

---

## AO3400 MOSFET

The AO3400 acts as an electronic switch.

Instead of using a relay, the ESP-01 controls the MOSFET gate directly.

Advantages include:

- Silent operation
- Low power consumption
- Fast switching
- Compact size
- Long operational life

---

# 🔋 Power Management Strategy

Power consumption is reduced using two methods.

### ESP32

- Deep Sleep
- Peripheral shutdown
- CPU sleep modes

### ESP-01

- Deep Sleep
- Timed wake-up
- External power switching

Because the ESP32 is physically disconnected from the battery after each cycle, standby current is significantly reduced compared to traditional Deep Sleep implementations.

---

# 📡 Communication Flow

```
GPS Neo-6M
      │
      ▼
    ESP32
      │
      ▼
   SIM800L
      │
      ▼
 GSM Network
      │
      ▼
 HTTP Server / MQTT Broker
```

---

# 🛡️ Reliability

This architecture improves reliability through:

- Hardware power reset
- Independent watchdog controller
- Automatic crash recovery
- Reduced memory fragmentation
- Lower thermal stress
- Improved battery efficiency

The system is designed for long-term autonomous operation without requiring manual intervention.

---

➡️ Continue to **PART 1C** for Wiring Overview, Firmware Structure, Folder Explanation, and Project Features in detail.
---

# 🔌 Wiring Overview

The following table shows the logical connection between each module.

| Module | Connected To | Interface |
|---------|--------------|-----------|
| GPS Neo-6M | ESP32 | UART |
| SIM800L | ESP32 | UART |
| ESP-01 | AO3400 Gate | GPIO |
| AO3400 | ESP32 Power Rail | Power Switching |
| Battery | TP4056 | Charging |
| TP4056 | Voltage Regulator | Power Supply |
| Voltage Regulator | ESP32 & ESP-01 | System Power |

> **Note**
>
> The detailed pin mapping is available in the `docs/Wiring.md` documentation.

---

# 📂 Firmware Structure

The firmware is divided into two independent programs.

## ESP32 Firmware

Responsible for:

- GPS initialization
- NMEA parsing
- GSM communication
- HTTP request
- MQTT (optional)
- EEPROM management
- Deep Sleep
- Sensor processing

Location:

```
firmware/
└── ESP32/
```

---

## ESP-01 Firmware

Responsible for:

- Deep Sleep timer
- Wake-up scheduling
- AO3400 control
- ESP32 Power Cycle
- Automatic Recovery

Location:

```
firmware/
└── ESP01/
```

---

# 📁 Repository Layout

```
ESP32-LowPower-GPS-Tracker
│
├── docs/
│   ├── Wiring.md
│   ├── ESP01_Modification.md
│   ├── PowerCycle.md
│   ├── Hardware.md
│   ├── BOM.md
│   └── Troubleshooting.md
│
├── firmware/
│   ├── ESP32/
│   └── ESP01/
│
├── hardware/
│   ├── schematic/
│   └── pcb/
│
├── images/
│
├── LICENSE
├── .gitignore
└── README.md
```

---

# 📦 Bill of Materials (BOM)

| Component | Qty |
|-----------|----:|
| ESP32 DevKit | 1 |
| ESP-01 | 1 |
| GPS Neo-6M | 1 |
| SIM800L | 1 |
| AO3400 MOSFET | 1 |
| TP4056 Charger | 1 |
| Voltage Regulator | 1 |
| Li-Ion Battery | 1 |
| Power Switch | 1 |
| PCB / Perfboard | 1 |

A complete component list is available in:

```
docs/BOM.md
```

---

# 💡 Design Philosophy

This project follows several important design principles:

- Modular firmware
- Low power consumption
- Hardware reliability
- Easy maintenance
- Open-source documentation
- Long-term autonomous operation

Every module has a dedicated responsibility, making future upgrades easier without affecting the entire system.

---

# 📈 Typical Operating Cycle

```
Power ON
    │
    ▼
ESP32 Boot
    │
    ▼
GPS Initialization
    │
    ▼
GPS Fix
    │
    ▼
SIM800L Connection
    │
    ▼
Upload Data
    │
    ▼
Store Required Information
    │
    ▼
ESP32 Deep Sleep
    │
    ▼
ESP-01 Removes Power
    │
    ▼
ESP-01 Deep Sleep
    │
    ▼
Wake-Up Timer
    │
    └───────────────┐
                    ▼
               Repeat Cycle
```

---

# 🌍 Possible Applications

This project can be adapted for:

- Vehicle GPS Tracker
- Motorcycle Tracker
- Wildlife Monitoring
- Livestock Tracking
- Portable Telemetry System
- Remote Environmental Monitoring
- Fleet Management
- IoT Data Logger
- Battery-Powered Monitoring Devices

---

# 🚀 Why External Power Cycling?

Although the ESP32 provides Deep Sleep functionality, certain situations may still require a complete hardware restart.

Examples include:

- Firmware deadlock
- GSM module not responding
- GPS initialization failure
- Memory fragmentation after long operation
- Unexpected peripheral lock-up

The ESP-01 ensures the ESP32 always starts from a clean power-on state, improving long-term reliability for unattended deployments.

---

➡️ Continue to **PART 1D** for Installation Guide, Flashing Instructions, Documentation Links, License, Contributing, Acknowledgments, and the final project overview.
---

# 📂 Repository Structure

The project is organized into separate directories to keep the firmware, documentation, hardware files, and images well structured.

```text
ESP32-LowPower-GPS-Tracker/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── firmware/
│   ├── ESP32/
│   │   └── ESP32_GPS_Tracker.ino
│   │
│   └── ESP01/
│       └── ESP01_PowerCycle.ino
│
├── docs/
│   ├── Wiring.md
│   ├── System_Architecture.md
│   ├── ESP01_Modification.md
│   ├── PowerCycle.md
│   ├── BOM.md
│   └── Troubleshooting.md
│
├── hardware/
│   ├── schematic/
│   └── pcb/
│
└── images/
    ├── block_diagram.png
    ├── wiring.png
    ├── prototype.jpg
    └── esp01_mod.jpg
```

---

# 📦 Firmware Overview

The project consists of two independent firmware programs.

## ESP32 Firmware

The ESP32 is responsible for the main application.

### Functions

- Read GPS data
- Parse NMEA sentences
- Communicate with SIM800L
- Upload location data
- Manage watchdog
- Store runtime data
- Enter Deep Sleep

---

## ESP-01 Firmware

The ESP-01 works as an independent power controller.

### Functions

- Wake on timer
- Control AO3400 MOSFET
- Perform hardware power cycle
- Enter Deep Sleep
- Automatically recover the ESP32

---

# 📚 Documentation

Additional technical documentation is available inside the **docs** directory.

| File | Description |
|------|-------------|
| Wiring.md | Hardware wiring guide |
| System_Architecture.md | Overall system architecture |
| ESP01_Modification.md | ESP-01 GPIO16 modification |
| PowerCycle.md | External power cycle explanation |
| BOM.md | Bill of Materials |
| Troubleshooting.md | Common problems and solutions |

---

# 📦 Bill of Materials (BOM)

| Component | Quantity |
|-----------|---------:|
| ESP32 DevKit | 1 |
| ESP-01 (ESP8266) | 1 |
| SIM800L | 1 |
| GPS Neo-6M | 1 |
| AO3400 MOSFET | 1 |
| TP4056 Charger | 1 |
| Voltage Regulator | 1 |
| Li-Ion Battery | 1 |
| PCB / Perfboard | 1 |

---

# 🎯 Design Principles

The system is designed with the following goals:

- Low power consumption
- High reliability
- Automatic hardware recovery
- Modular firmware
- Easy maintenance
- Open-source documentation
- Long-term autonomous operation

The separation between the ESP32 and the ESP-01 allows the system to recover from unexpected failures while minimizing battery consumption.

---

➡️ Continue to **PART 1D** for the complete wiring diagram, hardware connections, and power cycle implementation.
---

# 🔌 Hardware Wiring

The following section describes the hardware connections used in this project.

---

# ESP32 Pin Mapping

| ESP32 GPIO | Connected Device | Function |
|------------|------------------|----------|
| GPIO16 | SIM800L TXD | UART RX |
| GPIO17 | SIM800L RXD | UART TX |
| GPIO4 | GPS Neo-6M TX | UART RX |
| GPIO5 | GPS Neo-6M RX | UART TX |
| GPIO25 | SIM800L RST | Hardware Reset |

---

# ESP-01 Pin Mapping

| ESP-01 Pin | Connected Device | Function |
|------------|------------------|----------|
| GPIO2 | AO3400 Gate | Power Cycle Control |
| GPIO16 | RST | Deep Sleep Wake-up |
| VCC | 3.3V |
| GND | Common Ground |

> **Note**
>
> GPIO16 on the ESP-01 is modified and connected to the RST pin, allowing the ESP-01 to wake automatically from Deep Sleep.

---

# GPS Neo-6M Wiring

| GPS Module | ESP32 |
|------------|-------|
| TX | GPIO4 |
| RX | GPIO5 |
| VCC | 3.3V / 5V |
| GND | GND |

---

# SIM800L Wiring

| SIM800L | ESP32 |
|----------|-------|
| TXD | GPIO16 |
| RXD | GPIO17 |
| RST | GPIO25 |
| VCC | External Power Supply |
| GND | Common Ground |

> **Important**
>
> The SIM800L should be powered using a stable external power supply capable of delivering peak currents greater than 2 A.

---

# AO3400 MOSFET Wiring

The AO3400 is used as a **low-side electronic power switch**.

| AO3400 Pin | Connected To |
|-------------|--------------|
| Gate | ESP-01 GPIO2 |
| Drain | ESP32 Ground |
| Source | System Ground |

The ESP-01 controls the AO3400 to temporarily disconnect the ESP32 ground, forcing a complete hardware restart.

---

# Hardware Block Diagram

```text
                Li-Ion Battery
                       │
                       ▼
                    TP4056
                       │
                       ▼
              Voltage Regulator
                       │
          +------------+------------+
          |                         |
          |                         |
       ESP-01                   SIM800L
          |                         ▲
GPIO2     |                         │
          ▼                         │
     AO3400 MOSFET                  │
          │                         │
          ▼                         │
        ESP32 ◄─────────────────────┘
          ▲
          │
      GPS Neo-6M
```

---

# Why External Power Cycle?

Unlike conventional ESP32 projects that rely solely on Deep Sleep, this project performs an additional hardware power cycle using an independent ESP-01 controller.

During long-term testing, the system occasionally entered a non-responsive state after extended operation involving GPS communication, GSM communication, and continuous serial processing.

To improve long-term reliability, the ESP-01 temporarily disconnects the ESP32 ground using the AO3400 MOSFET for approximately **2–3 seconds**, forcing a complete hardware restart before normal operation resumes.

This approach provides several benefits:

- Automatic recovery from unexpected lock-ups
- Improved long-term stability
- Reduced maintenance
- Reliable unattended operation
- Better battery management

---

# Design Notes

This project uses a **low-side switching architecture**, where the AO3400 disconnects the ESP32 ground for a short duration.

The objective is **not long-term power isolation**, but a clean hardware reboot that restores normal operation without user intervention.

After the restart sequence is complete, the ESP-01 returns to Deep Sleep and wakes again according to the configured timer.

---

➡️ Continue to **PART 2 – System Architecture**
# 🏗️ System Architecture

## Overview

Sistem ini dirancang menggunakan konsep **Low-Power IoT Gateway**, di mana seluruh proses dikendalikan oleh dua mikrokontroler yang memiliki tugas berbeda.

- **ESP32** bertugas menjalankan aplikasi utama seperti GPS, komunikasi GSM, pemrosesan data, dan pengiriman telemetri.
- **ESP-01 (ESP8266)** bertindak sebagai pengendali daya (*Power Cycle Controller*) yang menghidupkan dan mematikan ESP32 menggunakan MOSFET AO3400 untuk menghemat konsumsi energi dan meningkatkan keandalan sistem.

Pendekatan ini memungkinkan perangkat bekerja dalam waktu lama menggunakan sumber daya baterai sekaligus mampu melakukan pemulihan otomatis (*automatic recovery*) apabila ESP32 mengalami kegagalan.

---

# 📡 Hardware Architecture

```
                  GPS NEO-6M
                       │
                 UART Communication
                       │
                       ▼
                +---------------+
                |     ESP32     |
                | Main Controller|
                +---------------+
                 │           │
                 │           │
         UART    │           │ GPIO
                 ▼           ▼
            SIM800L      Status LED
                 │
                 │
          HTTP / MQTT
                 │
                 ▼
              Internet


          +-------------------+
          |   ESP-01          |
          | Power Controller  |
          +-------------------+
                   │
                   │
                   ▼
             AO3400 MOSFET
                   │
             Power ESP32 ON/OFF
```

---

# ⚙️ System Components

| Component | Function |
|-----------|----------|
| ESP32 | Main processing unit |
| ESP-01 | External Power Cycle Controller |
| GPS NEO-6M | GPS Positioning |
| SIM800L | GSM Communication |
| AO3400 | Electronic Power Switch |
| Battery | Main Power Supply |

---

# 🔄 Operating Sequence

## Step 1

ESP-01 keluar dari Deep Sleep.

↓

## Step 2

ESP-01 mengaktifkan MOSFET AO3400.

↓

## Step 3

ESP32 memperoleh catu daya dan mulai melakukan booting.

↓

## Step 4

ESP32 menginisialisasi seluruh periferal.

- GPS
- SIM800L
- EEPROM
- Sensor

↓

## Step 5

ESP32 menunggu GPS memperoleh koordinat.

↓

## Step 6

Koordinat dikirim melalui jaringan GSM.

↓

## Step 7

ESP32 menyimpan data yang diperlukan.

↓

## Step 8

ESP32 masuk ke Deep Sleep.

↓

## Step 9

ESP-01 memutus daya ESP32.

↓

## Step 10

ESP-01 kembali masuk Deep Sleep.

↓

## Siklus diulang kembali.

---

# 🔋 Power Management

Sistem menggunakan dua tingkat penghematan daya.

### ESP32

Menggunakan fitur:

- Deep Sleep
- Peripheral Shutdown
- CPU Sleep

### ESP-01

Menggunakan:

- Deep Sleep
- External Wakeup
- Hardware Power Switching

Dengan metode ini konsumsi daya saat perangkat tidak bekerja dapat ditekan secara signifikan dibandingkan jika ESP32 tetap diberi catu daya sepanjang waktu.

---

# 🛡️ Automatic Recovery

ESP-01 bekerja secara independen dari ESP32.

Jika terjadi kondisi seperti:

- ESP32 Hang
- Crash
- Watchdog Reset Berulang
- SIM800L Tidak Merespons
- GPS Tidak Stabil

ESP-01 tetap dapat memutus suplai daya dan menghidupkan ulang ESP32 sehingga sistem dapat kembali beroperasi tanpa intervensi pengguna.

---

# 📊 Functional Block

```
Battery
   │
   ▼
ESP-01
   │
   ▼
AO3400 MOSFET
   │
   ▼
ESP32
   │
   ├──── GPS NEO-6M
   │
   ├──── SIM800L
   │
   └──── Sensors
            │
            ▼
        HTTP / MQTT
            │
            ▼
        Server / Cloud
```

---

# 🎯 Design Goals

- Low Power Consumption
- Automatic Recovery
- Stable Long-Term Operation
- Easy Maintenance
- Modular Architecture
- Battery Friendly
- Reliable Remote Monitoring
- Easy Firmware Update

---

# 📌 Notes

Seluruh firmware dibagi menjadi dua bagian:

- **ESP32 Firmware** → Mengelola GPS, GSM, sensor, dan komunikasi data.
- **ESP-01 Firmware** → Mengelola timer, Deep Sleep, serta Power Cycle menggunakan MOSFET AO3400.

Pemisahan fungsi ini membuat sistem lebih stabil, lebih hemat energi, dan lebih mudah dikembangkan di masa mendatang.
