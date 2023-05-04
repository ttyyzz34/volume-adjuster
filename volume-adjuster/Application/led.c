#include "led.h"

void led_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

/*End of file.*/

void water_lamp(void)
{
	static uint16_t pwm = 0;
	pwm = set_pwm(pwm);
	TIM2->CCR1 = pwm;
	pwm = set_pwm(pwm);
	TIM2->CCR2 = pwm;
	pwm = set_pwm(pwm);
	TIM2->CCR4 = pwm;
	
	pwm = set_pwm(pwm);
	TIM3->CCR1 = pwm;
	pwm = set_pwm(pwm);
	TIM3->CCR2 = pwm;
	pwm = set_pwm(pwm);
	TIM3->CCR4 = pwm;
	
	pwm = set_pwm(pwm);
	TIM1->CCR1 = pwm;
	
	pwm = set_pwm(pwm);
	TIM4->CCR1 = pwm;
	pwm = set_pwm(pwm);
	TIM4->CCR2 = pwm;
	pwm = set_pwm(pwm);
	TIM4->CCR4 = pwm;
}

uint16_t set_pwm(uint16_t pwm)
{
	//有个逻辑错误，必须是100，现在没法改，不知道错哪了
	if(pwm > 999)
	{
		pwm = 0;
	}
	else
	{
		pwm += 100;
	}
	return pwm;
}
