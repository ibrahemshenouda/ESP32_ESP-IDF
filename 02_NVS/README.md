# ESP32 NVS Standalone Examples

This directory contains standalone C source files demonstrating the use of the Non-Volatile Storage (NVS) library on the ESP32 using the ESP-IDF.

## Contents
*   **`Write_Read_Wifi_Pass.c`**: An example demonstrating how to initialize the default NVS partition, write Wi-Fi credentials (SSID and password) to flash memory, and read them back. This is crucial for retaining configuration data across device power cycles.

*Note: These are raw source files. To compile and flash them to an ESP32, you will need to place them within the `main` folder of a properly structured ESP-IDF project (see `00_IDF_Full_Project/02_NVS`).*
