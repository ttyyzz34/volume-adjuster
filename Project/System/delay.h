#ifndef __TIMER_H_
#define __TIMER_H_
//-------------------------------------------------
#include "stm32f10x.h"

//-------------------------------------------------

//-------------------------------------------------

void SysTick_Delay_Init(void);
void delay_us(u32 Delay_time);
void delay_ms(u32 Delay_time);
void delay_s(u16 Delay_time);

//-------------------------------------------------
#endif
