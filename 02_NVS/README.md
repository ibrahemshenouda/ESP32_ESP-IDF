# 💾 ESP32 NVS Standalone Example

This directory contains standalone C source files focused on mastering the **Non-Volatile Storage (NVS)** library on the ESP32. NVS is critical for IoT applications as it allows you to save configuration data (like Wi-Fi credentials, calibration data, and tokens) in flash memory, ensuring the data persists across power cycles and reboots.

## 📄 File: `Write_Read_Wifi_Pass.c`

This script demonstrates a robust workflow for initializing the NVS partition, checking for existing Wi-Fi credentials (SSID and Password), and writing default values if none exist.

### 🛠️ Core APIs Demonstrated

| API Function | Description |
| :--- | :--- |
| `nvs_flash_init()` | Initializes the default NVS partition. This is a mandatory first step. |
| `nvs_flash_erase()` | Erases the NVS partition. Crucial for recovering from a corrupted or upgraded NVS structure (`ESP_ERR_NVS_NEW_VERSION_FOUND`). |
| `nvs_open(const char* name, nvs_open_mode_t open_mode, nvs_handle_t *out_handle)` | Opens an NVS namespace (e.g., "system") and provides a handle for read/write operations. |
| `nvs_get_str(...)` | Reads a string value associated with a specific key. |
| `nvs_set_str(...)` | Writes a string value to a specific key (held in RAM until committed). |
| `nvs_commit(nvs_handle_t handle)` | **Critical:** Pushes any pending changes from `nvs_set_*` to the physical flash memory. |
| `nvs_close(nvs_handle_t handle)` | Closes the handle and frees up resources. |

### 🔍 Code Workflow Analysis

1.  **Robust Initialization:** The code attempts `nvs_flash_init()`. If it detects a version mismatch or no free pages, it forcefully erases the partition with `nvs_flash_erase()` and retries initialization.
2.  **Namespace Management:** It opens a namespace called `"system"` in `NVS_READWRITE` mode.
3.  **Read/Write Logic:**
    *   It attempts to fetch the key `"wifi_ssid"`.
    *   If the key returns `ESP_ERR_NVS_NOT_FOUND`, the code knows the device is unprovisioned. It uses `nvs_set_str` to write default credentials ("Ibrahim" / "12345678") and calls `nvs_commit()` to save them.
    *   It then logs the retrieved SSID and Password using `ESP_LOGI`.

> [!WARNING]
> **Standalone File Notice:** This `.c` file cannot be compiled on its own. To run it, you must replace the `main.c` file inside a full ESP-IDF project (such as `00_IDF_Full_Project/02_NVS/main/main.c`) with this code.
