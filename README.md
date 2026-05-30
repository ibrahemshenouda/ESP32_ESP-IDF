# ESP32 ESP-IDF Mastery Repository

Welcome to the **ESP32 ESP-IDF Mastery Repository**! This repository serves as a comprehensive collection of embedded IoT projects, tutorials, and standalone source code designed to master the official **Espressif IoT Development Framework (ESP-IDF)**.

## 🗂 Repository Architecture

This repository is meticulously organized into two primary structures:

1.  **`00_IDF_Full_Project/`**: 
    *   This directory contains **complete, fully-structured ESP-IDF CMake projects**.
    *   Each sub-project here includes a `CMakeLists.txt`, an `sdkconfig` file, and a proper `main/` component directory. 
    *   These projects are ready to be compiled, flashed, and monitored immediately out of the box using the ESP-IDF toolchain.
2.  **`01_GPIO/` & `02_NVS/` (Standalone Examples)**:
    *   These root-level directories contain raw, standalone `.c` source files.
    *   They are heavily commented to serve as educational snippets for specific peripherals and subsystems (like GPIO and Non-Volatile Storage).
    *   *Note: To run these, they must be copied into the `main/` folder of a structured ESP-IDF project (like the ones in `00_IDF_Full_Project`).*

---

## 🚀 Getting Started & Prerequisites

To successfully build and flash any project in this repository, you **must** have the ESP-IDF toolchain installed.

### 1. Hardware Requirements
*   An ESP32 Development Board (ESP32-WROOM, ESP32-WROVER, ESP32-S3, etc.)
*   A Micro-USB or USB-C cable capable of data transfer.

### 2. Software Requirements
*   **ESP-IDF v4.4 or v5.x**: Follow the official [Espressif Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) to install the toolchain for Windows, macOS, or Linux.
*   **Espressif IDE or VS Code**: While you can use the command line, using VS Code with the official Espressif Extension provides an excellent development experience.

---

## 🛠️ General Build & Flash Workflow

For any project inside `00_IDF_Full_Project/`, follow this standard workflow in your terminal:

```bash
# 1. Export ESP-IDF tools (Linux/macOS)
. $HOME/esp/esp-idf/export.sh

# 2. Navigate to the target project directory
cd 00_IDF_Full_Project/01_GPIO

# 3. Set the target chip (e.g., esp32, esp32s2, esp32s3, esp32c3)
idf.py set-target esp32

# 4. (Optional) Configure the project via menuconfig
idf.py menuconfig

# 5. Build, Flash, and Monitor the serial output (replace /dev/ttyUSB0 with your port)
idf.py -p /dev/ttyUSB0 flash monitor
```

> [!TIP]
> **Exiting the Monitor:** To exit the `idf.py monitor` terminal, press `Ctrl + ]`.
