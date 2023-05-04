#ifndef __LED_H
#define __LED_H

#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"

void led_Toggle(void);
void water_lamp(void);

//私有成员函数
static uint16_t set_pwm(uint16_t pwm);

#endif  /*End of file.*/
