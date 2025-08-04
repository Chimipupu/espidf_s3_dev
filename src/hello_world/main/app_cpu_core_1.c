/**
 * @file app_cpu_core_1.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief ESP32 S3のCPU Core1のアプリヘッダ
 * @version 0.1
 * @date 2025-08-05
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */
#include "app_cpu_core_1.h"

esp_chip_info_t g_chip_info;

static void show_chip_info(void);

static void show_chip_info(void)
{
    esp_chip_info(&g_chip_info);

    printf("This is %s chip with %d CPU core(s)\n"
            "%s\n%s\n%s\n%s\n",
            CONFIG_IDF_TARGET,
            g_chip_info.cores,
            (g_chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
            (g_chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
            (g_chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
            (g_chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    unsigned major_rev = g_chip_info.revision / 100;
    unsigned minor_rev = g_chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
}

/**
 * @brief CPU Core1のアプリメイン初期化関数
 * 
 */
void app_core_1_main_init(void)
{
    show_chip_info();
}

/**
 * @brief CPU Core1のアプリメイン関数
 * 
 */
void app_core_1_main(void)
{
    app_core_1_main_init();

    while(1)
    {
        printf("[DEBUG] ESP-IDF Develop\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}