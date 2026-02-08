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
#include "esp_heap_caps.h"

esp_chip_info_t g_chip_info;

static void psram_test(void);
static void show_chip_info(void);

static void psram_test(void)
{
    size_t size = 1024 * 10; // 10KB確保

    // PSRAM領域からメモリを確保する（8bitアクセス可能なPSRAM）
    void* psram_ptr = heap_caps_malloc(size, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (psram_ptr == NULL) {
        printf("PSRAM malloc failed\n");
    } else {
        printf("PSRAM malloc succeeded: %p\n", psram_ptr);
        // メモリ使用例
        memset(psram_ptr, 0, size);

        // 確保したメモリを解放
        heap_caps_free(psram_ptr);
    }
}

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
    psram_test();
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
        psram_test();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}