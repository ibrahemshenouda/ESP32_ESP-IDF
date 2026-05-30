# 🏗️ ESP-IDF Full Projects

This directory serves as the root container for all fully structured, compile-ready ESP-IDF projects. 

Unlike the standalone raw `.c` files found in the root of the repository, every folder within this directory is a complete, self-contained CMake project that conforms to the strict architectural requirements of the ESP-IDF build system.

## 📂 Project Structure Breakdown

Every project in this directory (e.g., `01_GPIO`, `02_NVS`) follows this standard ESP-IDF component-based architecture:

```text
Project_Name/
├── CMakeLists.txt        # Top-level project build file. Defines the project name.
├── sdkconfig             # (Generated) Project configuration file, modified via menuconfig.
└── main/                 # The main component directory containing the application logic.
    ├── CMakeLists.txt    # Component-level build file. Registers source files.
    └── main.c            # The actual C source code containing app_main().
```

## 🛠️ Included Projects

### 1. `01_GPIO`
A complete project demonstrating how to manipulate General Purpose Input/Output (GPIO) pins. It includes the build files necessary to flash the Blink LED example directly to the board.

### 2. `02_NVS`
A complete project showcasing the Non-Volatile Storage (NVS) driver. It demonstrates how to initialize the flash partition and persistently store/read data (like Wi-Fi credentials) across power cycles.

---

## ⚙️ Compilation & Flashing Instructions

To compile any project in this folder, navigate into its specific directory and run the standard ESP-IDF commands:

> [!IMPORTANT]
> Make sure your ESP-IDF environment variables are exported before running these commands!

```bash
# Example: Building the GPIO project
cd 01_GPIO

# 1. Set the target (crucial for building the correct HAL)
idf.py set-target esp32

# 2. Compile the source code, bootloader, and partition table
idf.py build

# 3. Flash to the device and open the serial monitor (adjust the port as needed)
idf.py -p /dev/ttyUSB0 flash monitor
```
