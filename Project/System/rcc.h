#ifndef __RCC_H
#define __RCC_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#define RCC_PLLMul_27                   ((uint32_t)0x10280000)

void SystemClock_Config(void);

#endif /*__RCC_H*/
