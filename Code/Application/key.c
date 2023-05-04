#include "key.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	int8_t key = 3;
	switch(GPIO_Pin)
	{
		case KEY_A_Pin:
			if(HAL_GPIO_ReadPin(KEY_B_GPIO_Port, KEY_B_Pin) == GPIO_PIN_SET)
			{
				key = 1;
			}
			break;
		case KEY_B_Pin:
			if(HAL_GPIO_ReadPin(KEY_A_GPIO_Port, KEY_A_Pin) == GPIO_PIN_SET)
			{
				key = -1;
			}
			break;
		case KEY_Pin:
			key = 0;
			break;
		default:break;
	}
	if(key != 3)//消除没用的干扰
	{
		osMessageQueuePut(KeyQueueHandle, &key, 0, 0);
	}
}
