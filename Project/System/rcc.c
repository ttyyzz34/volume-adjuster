#include "rcc.h"


void SystemClock_Config(void)
{
    RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);                              //使能外部高速晶振(HSE)
    while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);     //等待外部高速时钟使能就绪
    FLASH_SetLatency(FLASH_Latency_2);                      //设置代码延时值:2延时周期
    while (READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY) != FLASH_Latency_2);



	RCC_PLLCmd(DISABLE);										//关闭PLL
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_27);		//配置PLL,8*27=216MHz
	RCC_PLLCmd(ENABLE);                                         //使能PLL

	while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);        //等待PLL就绪

	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);                  //选择PLL作为系统时钟

	RCC_HCLKConfig(RCC_SYSCLK_Div1);    //配置AHB时钟
	RCC_PCLK1Config(RCC_HCLK_Div2);	    //配置APB1时钟
	RCC_PCLK2Config(RCC_HCLK_Div1);	    //配置APB2时钟

	RCC_LSICmd(ENABLE);                                                 //使能内部低速时钟
	while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);				//等待LSI就绪
	RCC_HSICmd(ENABLE);                                                 //使能内部高速时钟
	while (RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);                //等待HSI就绪
}
