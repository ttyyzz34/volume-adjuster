#include "stm32f10x.h"
#include "led.h"
#include "gpio.h"
#include "delay.h"
#include "rcc.h"
#include "usart1.h"

int main(void)
{
	SystemClock_Config();
	USART1_Init(115200);
	LED_Pin_Init();
	printf("init ok");

	while(1)
	{
		LED_blink();
	}
}


