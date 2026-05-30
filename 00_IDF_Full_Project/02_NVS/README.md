# 💾 Full Project: NVS Wi-Fi Credentials

This directory is a **complete, buildable ESP-IDF project**. It contains everything required by the CMake build system to compile and flash an NVS (Non-Volatile Storage) demonstration to an ESP32.

The application demonstrates how to robustly initialize the flash memory partition, gracefully handle version mismatches or corruption by erasing the flash, and securely read and write Wi-Fi credentials (`wifi_ssid` and `wifi_pass`) across system reboots.

## 📂 Project Architecture

*   **`CMakeLists.txt`**: The project-level CMake file. It sets the project name and includes the ESP-IDF build system.
*   **`sdkconfig`**: The auto-generated project configuration file (modified via `idf.py menuconfig`). This configuration automatically allocates the default NVS partition table in flash.
*   **`main/CMakeLists.txt`**: Registers the `main.c` file as a component source.
*   **`main/main.c`**: The application code containing the `app_main()` entry point and the NVS API logic.

## 🚀 How to Build and Flash

Ensure you have activated your ESP-IDF environment (e.g., by running `. $HOME/esp/esp-idf/export.sh`).

1.  **Navigate to the project directory:**
    ```bash
    cd /home/ibrahimshnouda/GitHub/ESP32_ESP-IDF/00_IDF_Full_Project/02_NVS
    ```

2.  **Set the Target:**
    Ensure the build system compiles for the correct architecture.
    ```bash
    idf.py set-target esp32
    ```

3.  **Compile the Project:**
    ```bash
    idf.py build
    ```

4.  **Flash and Monitor:**
    Connect your ESP32. Replace `/dev/ttyUSB0` with your actual serial port (e.g., `COM3` on Windows).
    ```bash
    idf.py -p /dev/ttyUSB0 flash monitor
    ```
    *Upon opening the monitor, you should see logs from `ESP_LOGI` printing the retrieved SSID and Password.*
    *To exit the monitor, press `Ctrl + ]`.*
