#include "led.h"
#include "delay.h"

void Delay(__IO u32 nCount);
#define SOFT_DELAY Delay(0x0FFFFF);

void LED_blink(void)
{
    if ((GPIOB->ODR & LED_Pin) == (uint32_t)Bit_RESET)
    {
        GPIOB->BSRR = LED_Pin;
    }
    else
    {
        GPIOB->BRR = LED_Pin;
    }
    SOFT_DELAY
}


void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
