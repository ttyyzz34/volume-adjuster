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
#include "led.h"
#include "tim.h"
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
osThreadId LEDTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LED_Task (void const* argument);

void MX_FREERTOS_Init (void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
<<<<<<< HEAD
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );
=======
void vApplicationGetIdleTaskMemory (StaticTask_t** ppxIdleTaskTCBBuffer, StackType_t** ppxIdleTaskStackBuffer, uint32_t* pulIdleTaskStackSize);
>>>>>>> parent of 360faad (0502)

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory (StaticTask_t** ppxIdleTaskTCBBuffer, StackType_t** ppxIdleTaskStackBuffer, uint32_t* pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
    /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
<<<<<<< HEAD
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of KeyQueue */
  osMessageQDef(KeyQueue, 2, uint16_t);
  KeyQueueHandle = osMessageCreate(osMessageQ(KeyQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of DefaultTask */
  osThreadDef(DefaultTask, Default_Task, osPriorityIdle, 0, 256);
  DefaultTaskHandle = osThreadCreate(osThread(DefaultTask), NULL);

  /* definition and creation of LedTask */
  osThreadDef(LedTask, Led_Task, osPriorityLow, 0, 256);
  LedTaskHandle = osThreadCreate(osThread(LedTask), NULL);

  /* definition and creation of KeyTask */
  osThreadDef(KeyTask, Key_Task, osPriorityLow, 0, 1024);
  KeyTaskHandle = osThreadCreate(osThread(KeyTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */
=======
void MX_FREERTOS_Init (void)
{
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* definition and creation of LEDTask */
    osThreadDef (LEDTask, LED_Task, osPriorityNormal, 0, 128);
    LEDTaskHandle = osThreadCreate (osThread (LEDTask), NULL);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */
>>>>>>> parent of 360faad (0502)

}

/* USER CODE BEGIN Header_LED_Task */
/**
  * @brief  Function implementing the LEDTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LED_Task */
void LED_Task (void const* argument)
{
<<<<<<< HEAD
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN Default_Task */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END Default_Task */
}

/* USER CODE BEGIN Header_Led_Task */
/**
* @brief Function implementing the LedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Led_Task */
void Led_Task(void const * argument)
{
  /* USER CODE BEGIN Led_Task */
	/* Infinite loop */
	for(;;)
=======
    /* USER CODE BEGIN LED_Task */
    /* Infinite loop */
    for (;;)
>>>>>>> parent of 360faad (0502)
	{
		led_Toggle();
		osDelay(500);
		__HAL_TIM_SET_COMPARE (&htim1, TIM_CHANNEL_1, 900);
		__HAL_TIM_SET_COMPARE (&htim2, TIM_CHANNEL_1, 900);
		__HAL_TIM_SET_COMPARE (&htim2, TIM_CHANNEL_2, 990);
		__HAL_TIM_SET_COMPARE (&htim2, TIM_CHANNEL_4, 999);
		osDelay(1000);
		TIM1->CCR1 = 0;
	}
<<<<<<< HEAD
  /* USER CODE END Led_Task */
}

/* USER CODE BEGIN Header_Key_Task */
/**
* @brief Function implementing the KeyTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Key_Task */
void Key_Task(void const * argument)
{
  /* USER CODE BEGIN Key_Task */
	int8_t key = 0;
	/* Infinite loop */
	for(;;)
	{
//		if(osMessageQueueGet(KeyQueueHandle, &key, NULL, osWaitForever) == osOK)
//		{
//			printf("%d\n", key);
//		}
	}
  /* USER CODE END Key_Task */
=======
    /* USER CODE END LED_Task */
>>>>>>> parent of 360faad (0502)
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

