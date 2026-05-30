#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs.h"
#include "nvs_flash.h"

static const char *TAG = "nvs_demo";

void app_main(void)
{
    // nvs initialization
    esp_err_t err = nvs_flash_init();
    // if nvs_flash_init() returned version error
    if (err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        /*nvs_flash_erase(): erase nvs partation and return the status of formating
        ESP_ERROR_CHECK:   checking error if found in erase function*/
        ESP_ERROR_CHECK(nvs_flash_erase());
        // try again to init nvs
        err = nvs_flash_init();
    }
    // checking any error if found in init function
    ESP_ERROR_CHECK(err);

    /*creating the handle in RAM to point to namespace will open or create*/
    nvs_handle_t nvs_handle;
    /*this handle in namespace with name= system, to read and write data, in this handle*/
    err = nvs_open("system", NVS_READWRITE, &nvs_handle);
    /*checking errors*/
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to open NVS");
        return;
    }
    /*creating array to read data in*/
    char ssid[33] = {0};
    char pass[64] = {0};
    /*defining the size of array*/
    size_t ssid_len = sizeof(ssid);
    size_t pass_len = sizeof(pass);

    /*from handle: nvs_handle the data of key: ssid, and store in ssid array, and be aware of array size*/
    err = nvs_get_str(nvs_handle, "wifi_ssid", ssid, &ssid_len);
    /*if this key "wifi_ssid" not found */
    if (err == ESP_ERR_NVS_NOT_FOUND)
    {
        ESP_LOGE(TAG, "Setting defualt wifi credintials");
        /*create key and value for ssid and ssid_pass*/
        nvs_set_str(nvs_handle, "wifi_ssid", "Ibrahim");
        nvs_set_str(nvs_handle, "wifi_pass", "12345678");
        nvs_commit(nvs_handle);
    }
    /*from handel points to namespace, read wifi_ssid and set its value in ssid , and be aware of array length*/
    nvs_get_str(nvs_handle, "wifi_ssid", ssid, &ssid_len);
    ESP_LOGI(TAG, "wifi_ssid: %s", ssid);
    nvs_get_str(nvs_handle, "wifi_pass", pass, &pass_len);
    ESP_LOGI(TAG, "wifi_pass: %s", pass);

    nvs_close(nvs_handle);

    while (1)
    {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}