/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
#include "led.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LEDTask */
osThreadId_t LEDTaskHandle;
const osThreadAttr_t LEDTask_attributes = {
	.name = "LEDTask",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityLow,
};
/* Definitions for KeyTask */
osThreadId_t KeyTaskHandle;
const osThreadAttr_t KeyTask_attributes = {
	.name = "KeyTask",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityLow2,
};
/* Definitions for WaterlampTask */
osThreadId_t WaterlampTaskHandle;
const osThreadAttr_t WaterlampTask_attributes = {
	.name = "WaterlampTask",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for KeyQueue */
osMessageQueueId_t KeyQueueHandle;
const osMessageQueueAttr_t KeyQueue_attributes = {
	.name = "KeyQueue"
};
/* Definitions for KeyBinarySem */
osSemaphoreId_t KeyBinarySemHandle;
const osSemaphoreAttr_t KeyBinarySem_attributes = {
	.name = "KeyBinarySem"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LED_Task(void *argument);
void Key_Task(void *argument);
void Waterlamp_Task(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* Create the semaphores(s) */
	/* creation of KeyBinarySem */
	KeyBinarySemHandle = osSemaphoreNew(1, 1, &KeyBinarySem_attributes);

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* Create the queue(s) */
	/* creation of KeyQueue */
	KeyQueueHandle = osMessageQueueNew(16, sizeof(uint16_t), &KeyQueue_attributes);

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of LEDTask */
	LEDTaskHandle = osThreadNew(LED_Task, NULL, &LEDTask_attributes);

	/* creation of KeyTask */
	KeyTaskHandle = osThreadNew(Key_Task, NULL, &KeyTask_attributes);

	/* creation of WaterlampTask */
	WaterlampTaskHandle = osThreadNew(Waterlamp_Task, NULL, &WaterlampTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_LED_Task */
/**
  * @brief  Function implementing the LEDTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LED_Task */
void LED_Task(void *argument)
{
	/* init code for USB_DEVICE */
	MX_USB_DEVICE_Init();
	/* USER CODE BEGIN LED_Task */
	/* Infinite loop */
	for(;;)
	{
		led_Toggle();
		osDelay(500);
	}
	/* USER CODE END LED_Task */
}

/* USER CODE BEGIN Header_Key_Task */
/**
* @brief Function implementing the KeyTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Key_Task */
void Key_Task(void *argument)
{
	/* USER CODE BEGIN Key_Task */
	int8_t key = 0;
	/* Infinite loop */
	for(;;)
	{
		if(osMessageQueueGet(KeyQueueHandle, &key, 0, osWaitForever) == osOK)
		{
			printf("%d\n", key);
		}
	}
	/* USER CODE END Key_Task */
}

/* USER CODE BEGIN Header_Waterlamp_Task */
/**
* @brief Function implementing the WaterlampTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Waterlamp_Task */
void Waterlamp_Task(void *argument)
{
	/* USER CODE BEGIN Waterlamp_Task */
	/* Infinite loop */
	for(;;)
	{
		water_lamp();
		osDelay(100);
	}
	/* USER CODE END Waterlamp_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

