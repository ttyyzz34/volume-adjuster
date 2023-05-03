#include "key.h"

int8_t key = 0;
uint32_t status_value;
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	//taskENTER_CRITICAL();
//	switch(GPIO_Pin)
//	{
//		case KEY_A_Pin:
//			if(HAL_GPIO_ReadPin(KEY_B_GPIO_Port, KEY_B_Pin) == GPIO_PIN_SET)
//			{
//				key = 1;
//			}
//			else
//			{
//				key = 5;
//			}
//			break;
//		case KEY_B_Pin:
//			if(HAL_GPIO_ReadPin(KEY_A_GPIO_Port, KEY_A_Pin) == GPIO_PIN_SET)
//			{
//				key = -1;
//			}
//			else
//			{
//				key = 5;
//			}
//			break;
//		case KEY_Pin:
//			key = 0;
//			break;
//		default:
//			break;
//	}
//	//taskEXIT_CRITICAL();

//}
