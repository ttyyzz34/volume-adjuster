#ifndef __LED_H
#define __LED_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "gpio.h"
#include "FreeRTOS.h"

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
#define LED_Pin     GPIO_Pin_2

void LED_blink(void);

#endif
