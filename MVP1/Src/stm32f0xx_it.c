/*
 * The root of all ISRs for the entire program live in this file.
 */
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "stm32f0xx_it.h"
#include "stm32f0xx_hal_tim.h"
#include "stm32f0xx_hal_tim_ex.h"

#include "platform_hw.h"

#include "main.h"
#include "iprintf.h"

extern I2C_HandleTypeDef hi2c1;

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
   HAL_IncTick();
   HAL_SYSTICK_IRQHandler();
}

