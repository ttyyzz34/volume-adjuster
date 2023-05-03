/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
<<<<<<< HEAD
<<<<<<< HEAD
extern PCD_HandleTypeDef hpcd_USB_FS;
extern TIM_HandleTypeDef htim1;
=======
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  HAL_RCC_NMI_IRQHandler();
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
	while(1)
	{
	}
  /* USER CODE END NonMaskableInt_IRQn 1 */
=======
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

=======
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END NonMaskableInt_IRQn 0 */
    HAL_RCC_NMI_IRQHandler();
    /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
    while (1)
        {
        }
    /* USER CODE END NonMaskableInt_IRQn 1 */
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while(1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
		//��ȡ������Ϣ
		uint32_t hfsr = SCB->HFSR;
		uint32_t mmfar = SCB->MMFAR;
		uint32_t bfar = SCB->BFAR;
		printf("error\n");
		printf("hfsr:0x%x\r mmfar:0x%x\r bfar:0x%x \n", hfsr, mmfar, bfar);
		printf(" ");
		break;

    /* USER CODE END W1_HardFault_IRQn 0 */
  }
=======
    /* USER CODE BEGIN HardFault_IRQn 0 */

=======
    /* USER CODE BEGIN HardFault_IRQn 0 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END HardFault_IRQn 0 */
    while (1)
        {
            /* USER CODE BEGIN W1_HardFault_IRQn 0 */
            /* USER CODE END W1_HardFault_IRQn 0 */
        }
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
=======
    /* USER CODE BEGIN MemoryManagement_IRQn 0 */

=======
    /* USER CODE BEGIN MemoryManagement_IRQn 0 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END MemoryManagement_IRQn 0 */
    while (1)
        {
            /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
            /* USER CODE END W1_MemoryManagement_IRQn 0 */
        }
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
=======
    /* USER CODE BEGIN BusFault_IRQn 0 */

=======
    /* USER CODE BEGIN BusFault_IRQn 0 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END BusFault_IRQn 0 */
    while (1)
        {
            /* USER CODE BEGIN W1_BusFault_IRQn 0 */
            /* USER CODE END W1_BusFault_IRQn 0 */
        }
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
=======
    /* USER CODE BEGIN UsageFault_IRQn 0 */

=======
    /* USER CODE BEGIN UsageFault_IRQn 0 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END UsageFault_IRQn 0 */
    while (1)
        {
            /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
            /* USER CODE END W1_UsageFault_IRQn 0 */
        }
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler (void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
=======
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

=======
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

>>>>>>> parent of 360faad (0502)
    /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler (void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */

    /* USER CODE END SysTick_IRQn 0 */
    HAL_IncTick();
#if (INCLUDE_xTaskGetSchedulerState == 1 )
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
        {
#endif /* INCLUDE_xTaskGetSchedulerState */
            xPortSysTickHandler();
#if (INCLUDE_xTaskGetSchedulerState == 1 )
        }
#endif /* INCLUDE_xTaskGetSchedulerState */
    /* USER CODE BEGIN SysTick_IRQn 1 */

    /* USER CODE END SysTick_IRQn 1 */
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
<<<<<<< HEAD
<<<<<<< HEAD
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USB_LP_CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 0 */

  /* USER CODE END USB_LP_CAN1_RX0_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_FS);
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 1 */

  /* USER CODE END USB_LP_CAN1_RX0_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_IRQn 0 */

  /* USER CODE END TIM1_UP_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_IRQn 1 */

  /* USER CODE END TIM1_UP_IRQn 1 */
=======
=======
>>>>>>> parent of 360faad (0502)
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler (void)
{
    /* USER CODE BEGIN EXTI15_10_IRQn 0 */

    /* USER CODE END EXTI15_10_IRQn 0 */
    HAL_GPIO_EXTI_IRQHandler (KEY_A_Pin);
    HAL_GPIO_EXTI_IRQHandler (KEY_B_Pin);
    HAL_GPIO_EXTI_IRQHandler (KEY_Pin);
    /* USER CODE BEGIN EXTI15_10_IRQn 1 */

    /* USER CODE END EXTI15_10_IRQn 1 */
<<<<<<< HEAD
>>>>>>> parent of 360faad (0502)
=======
>>>>>>> parent of 360faad (0502)
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
