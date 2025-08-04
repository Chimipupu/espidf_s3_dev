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
#ifndef APP_CPU_CORE_1_H
#define APP_CPU_CORE_1_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

extern esp_chip_info_t g_chip_info;

// S/Wリセット
static inline void _SW_RESET(void)
{
    esp_restart();
}

void app_core_1_main_init(void);
void app_core_1_main(void);

#endif // APP_CPU_CORE_1H