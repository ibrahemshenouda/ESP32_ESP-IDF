# 💡 Full Project: GPIO Blink LED

This directory is a **complete, buildable ESP-IDF project**. It contains everything required by the CMake build system to compile and flash a GPIO demonstration to an ESP32.

The application configures `GPIO_NUM_2` (the standard internal blue LED on most ESP32 development boards) as an output and utilizes a FreeRTOS `vTaskDelay` loop to blink the LED on and off every 1000 milliseconds.

## 📂 Project Architecture

*   **`CMakeLists.txt`**: The project-level CMake file. It sets the project name and includes the ESP-IDF build system.
*   **`sdkconfig`**: The auto-generated project configuration file (modified via `idf.py menuconfig`).
*   **`main/CMakeLists.txt`**: Registers the `main.c` file as a component source.
*   **`main/main.c`**: The application code containing the `app_main()` entry point and the GPIO logic.

## 🚀 How to Build and Flash

Ensure you have activated your ESP-IDF environment (e.g., by running `. $HOME/esp/esp-idf/export.sh`).

1.  **Navigate to the project directory:**
    ```bash
    cd /home/ibrahimshnouda/GitHub/ESP32_ESP-IDF/00_IDF_Full_Project/01_GPIO
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
    *To exit the monitor, press `Ctrl + ]`.*
