#include "led.h"

void led_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}



void water_lamp_down(void)
{
	static int16_t pwm = 0;
	//向下流水
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

void water_lamp_up(void)
{
	static int16_t pwm = 0;
	//向上流水
	pwm = set_pwm(pwm);
	TIM4->CCR4 = pwm;
	pwm = set_pwm(pwm);
	TIM4->CCR2 = pwm;
	pwm = set_pwm(pwm);

	TIM4->CCR1 = pwm;
	pwm = set_pwm(pwm);
	TIM1->CCR1 = pwm;
	
	pwm = set_pwm(pwm);
	TIM3->CCR4 = pwm;
	pwm = set_pwm(pwm);
	TIM3->CCR2 = pwm;
	pwm = set_pwm(pwm);
	TIM3->CCR1 = pwm;
	pwm = set_pwm(pwm);

	TIM2->CCR4 = pwm;
	pwm = set_pwm(pwm);
	TIM2->CCR2 = pwm;
	pwm = set_pwm(pwm);
	TIM2->CCR1 = pwm;

}
//函数作用：设置PWM形成流水的效果，必须是10个挡位，不然不行。
int16_t set_pwm(int16_t pwm)
{
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
/*End of file.*/
