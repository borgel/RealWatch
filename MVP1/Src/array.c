#include "array.h"
#include "iprintf.h"

#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"

#include <stdint.h>

enum Mode {
   M_HiZ,
   M_Out,
   M_In
};
enum State {
   S_Out,
   S_In,
};

//TODO move to util?
#define ARRAY_SIZE(array) \
       (sizeof(array) / sizeof(array[0]))

static uint16_t PinsSmall[] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10};
static uint16_t PinsLarge[] = {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7};

static void resetAllPins(void);

static void setPinModestate(uint16_t pin, enum Mode, enum State);

void array_Init(void) {
   // init all GPIOs to HiZ
   resetAllPins();
}

// FIXME does this API make sense?
void array_SetHour(uint8_t const hour) {
   // reset all pins?
   // reconfigure pins

   GPIO_InitTypeDef GPIO_InitStruct = {0};

   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pin = PinsSmall[0];
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   HAL_GPIO_WritePin(GPIOA, PinsSmall[0], GPIO_PIN_SET);

   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pin = PinsSmall[1];
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   HAL_GPIO_WritePin(GPIOA, PinsSmall[1], GPIO_PIN_RESET);
}

}

static void resetAllPins(void) {
   __HAL_RCC_GPIOA_CLK_ENABLE();

   GPIO_InitTypeDef GPIO_InitStruct = {0};
   GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

   for(int i = 0; i < ARRAY_SIZE(PinsSmall); i++) {
      GPIO_InitStruct.Pin = PinsSmall[i];
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
   }
   for(int i = 0; i < ARRAY_SIZE(PinsLarge); i++) {
      GPIO_InitStruct.Pin = PinsLarge[i];
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
   }
}

