#include "platform_hw.h"
#include "iprintf.h"
#include "array.h"

#include <stdlib.h>

int main(void)
{
   HAL_Init();

   platformHW_Init();

   iprintf("\r\nStarting... | Built "__DATE__":"__TIME__")\r\n");

   array_Init();

   // drop to lowest power (RTC alive)
   HAL_PWR_EnterSTANDBYMode();

   while(true) {
      //TODO software
   }

   return 0;
}

