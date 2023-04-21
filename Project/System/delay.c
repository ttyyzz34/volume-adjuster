#include "delay.h"

extern u32 delay_time;

void SysTick_Delay_Init(void)
{
	while(SysTick_Config(SystemCoreClock/1000000) == 1);	//1us
}


void delay_us(u32 Delay_time)
{
	delay_time = Delay_time;
	while(delay_time);
}

void delay_ms(u32 Delay_time)
{
	delay_us(Delay_time*1000);
}

void delay_s(u16 Delay_time)
{
	delay_ms(Delay_time*1000);
}
