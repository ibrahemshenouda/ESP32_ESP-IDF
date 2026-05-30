# GPIO Full Project (Blink LED)

This is a fully structured, buildable ESP-IDF project demonstrating basic GPIO operations. It configures a specific GPIO pin as an output and repeatedly toggles its state with a delay, creating a blinking LED effect.

## Project Structure
*   **`main/main.c`**: Contains the application entry point (`app_main`) and the GPIO configuration logic.
*   **`CMakeLists.txt`**: The CMake build configuration for this specific project.
*   **`sdkconfig`**: The project configuration file.

## Build and Flash
```bash
idf.py set-target esp32
idf.py build
idf.py -p (PORT) flash monitor
```
