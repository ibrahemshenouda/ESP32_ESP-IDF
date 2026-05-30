# NVS Full Project (Wi-Fi Credentials)

This is a fully structured, buildable ESP-IDF project demonstrating the use of the Non-Volatile Storage (NVS) driver. It shows how to safely store key-value pairs (like Wi-Fi SSIDs and passwords) into the ESP32's flash memory and retrieve them upon reboot.

## Project Structure
*   **`main/`**: Contains the main application code interfacing with the `nvs_flash` API.
*   **`CMakeLists.txt`**: The CMake build configuration for this specific project.
*   **`sdkconfig`**: The project configuration file.

## Build and Flash
```bash
idf.py set-target esp32
idf.py build
idf.py -p (PORT) flash monitor
```
