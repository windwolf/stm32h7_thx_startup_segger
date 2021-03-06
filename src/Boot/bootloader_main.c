#include "stm32h7xx_hal.h"
#include "dcmi.h"
#include "dma.h"
#include "i2c.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

#include "bootloader_qspi.h"
#include "app_main.h"
#include "unit_test.h"

//#include "../cmbBackTrace/cm_backtrace.h"

extern void MPU_Config(void);
extern void SystemClock_Config();

int main(void)
{
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* Enable I-Cache--------------------------------------------------------*/
    SCB_EnableICache();

    /* Enable D-Cache---------------------------------------------------------*/
    SCB_EnableDCache();
    HAL_MPU_Disable();
    MPU_Config();
    /* MCU Configuration--------------------------------------------------------*/
#ifdef UNITTEST
    test_before_hal_init();
#endif
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();
    //cm_backtrace_init("startup", "1.0", "0.1");
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */
    MX_QUADSPI_Init();
    bootloader_qspi_startup();
    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_DMA_Init();
    //MX_MDMA_Init();
    MX_USART1_UART_Init();
    MX_DCMI_Init();
    MX_I2C1_Init();
    MX_SDMMC1_SD_Init();
    MX_SPI1_Init();
    MX_SPI4_Init();
    MX_TIM1_Init();
    MX_USB_OTG_FS_PCD_Init();
    MX_UART4_Init();
    /* USER CODE BEGIN 2 */
#ifdef UNITTEST
    test_after_hal_init();
#endif
    appMain();
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}