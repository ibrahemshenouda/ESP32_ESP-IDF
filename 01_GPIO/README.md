# 💡 ESP32 GPIO Standalone Example

This directory contains standalone C source files focused on mastering General Purpose Input/Output (GPIO) functionality on the ESP32 using the official ESP-IDF `driver/gpio.h` library.

## 📄 File: `blink_led.c`

This file provides a foundational example of configuring a digital pin as an output and driving it High and Low to blink an LED. It utilizes FreeRTOS tasks to create a non-blocking delay.

### 🛠️ Core APIs Demonstrated

| API Function | Description |
| :--- | :--- |
| `gpio_reset_pin(gpio_num_t gpio_num)` | Resets the pin to its default state, disabling any pull-ups/pull-downs and setting it to an isolated state. |
| `gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode)` | Configures the GPIO pin's direction (e.g., `GPIO_MODE_OUTPUT` or `GPIO_MODE_INPUT`). |
| `gpio_set_level(gpio_num_t gpio_num, uint32_t level)` | Sets the digital output level of the pin (`1` for HIGH, `0` for LOW). |
| `vTaskDelay(TickType_t xTicksToDelay)` | A FreeRTOS function that puts the current task to sleep for a specified number of RTOS ticks, allowing the scheduler to run other tasks. |

### 🔍 Code Analysis

```c
#define LED_GPIO_PIN GPIO_NUM_2 // Commonly the internal blue LED on ESP32 dev boards

void app_main(void)
{
    // 1. Reset and Configure
    gpio_reset_pin(LED_GPIO_PIN);
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);

    // 2. Infinite Loop (Superloop)
    while (1)
    {
        gpio_set_level(LED_GPIO_PIN, 1); // Turn ON
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1000ms
        
        gpio_set_level(LED_GPIO_PIN, 0); // Turn OFF
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1000ms
    }
}
```

> [!WARNING]
> **Standalone File Notice:** This `.c` file cannot be compiled on its own. To run it, you must replace the `main.c` file inside a full ESP-IDF project (such as `00_IDF_Full_Project/01_GPIO/main/main.c`) with this code.
