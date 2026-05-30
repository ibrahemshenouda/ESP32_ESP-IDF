# ESP-IDF Full Projects

This directory contains fully structured ESP-IDF CMake projects. Unlike the standalone source files in the parent directory, these folders include the complete build system (`CMakeLists.txt`), configuration files (`sdkconfig`), and standard ESP-IDF directory layout (`main/`).

## Projects included:
*   **`01_GPIO`**: A complete project demonstrating basic GPIO operations (e.g., LED blinking).
*   **`02_NVS`**: A complete project demonstrating how to use the Non-Volatile Storage (NVS) library to store and retrieve data across reboots.

## How to build and flash
1. Navigate to the specific project directory.
2. Set up your ESP-IDF environment (e.g., `. $HOME/esp/esp-idf/export.sh`).
3. Set the target (if not already set): `idf.py set-target esp32`
4. Build the project: `idf.py build`
5. Flash and monitor: `idf.py -p /dev/ttyUSB0 flash monitor` (replace with your actual port).
