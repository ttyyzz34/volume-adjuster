#ifndef __LED_H
#define __LED_H

#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"

void led_Toggle(void);
void water_lamp_down(void);
void water_lamp_up(void);

//˽�г�Ա����
static int16_t set_pwm(int16_t pwm);


#endif  /*End of file.*/
