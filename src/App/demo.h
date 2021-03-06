//
// Created by windwolf on 2021/4/26.
//

#ifndef STARTUP_DEMO_H
#define STARTUP_DEMO_H

// #include <common/shared.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "tx_api.h"
#include "stdint.h"
#include "stdio.h"
#include "stm32h7xx_hal_uart.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_hal_qspi.h"

#define DEMO_STACK_SIZE 4096
#define DEMO_BYTE_POOL_SIZE 50000
#define DEMO_BLOCK_POOL_SIZE 100
#define DEMO_QUEUE_SIZE 100

#define CONVERT_REFERENCE(var, type) (*((type *)&var))

    void thread_0_entry(ULONG thread_input);

    void thread_1_entry(ULONG thread_input);

    void fx_application_define();

    void thread_2_entry(ULONG thread_input);
#ifdef __cplusplus
}
#endif

#endif //STARTUP_DEMO_H
