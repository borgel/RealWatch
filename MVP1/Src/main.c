#include "platform_hw.h"
#include "iprintf.h"

#include <stdlib.h>

int main(void)
{
   HAL_Init();

   platformHW_Init();

   iprintf("\r\nStarting... | Built "__DATE__":"__TIME__")\r\n");

   while(true) {
      //TODO software
   }

   return 0;
}

