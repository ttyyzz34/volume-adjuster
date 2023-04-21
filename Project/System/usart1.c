#include "usart1.h"


void USART1_Init(unsigned int Bound)
{

    Usart1_Pin_Init();
    // 配置串口的工作参数
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = Bound;											// 配置波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;							// 配置 针数据字长
    USART_InitStructure.USART_StopBits = USART_StopBits_1;								// 配置停止位
    USART_InitStructure.USART_Parity = USART_Parity_No ;								// 配置校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		// 配置硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						// 配置工作模式，收发一起
    USART_Init(USART1, &USART_InitStructure);											// 完成串口的初始化配置

	// 串口中断优先级配置

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  			/* 嵌套向量中断控制器组选择 */

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			/* 配置USART为中断源 */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  	/* 抢断优先级*/
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  		/* 子优先级 */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  			/* 使能中断 */
    NVIC_Init(&NVIC_InitStructure);  							/* 初始化配置NVIC */

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);				/* 使能串口接收中断*/
    USART_Cmd(USART1, ENABLE);	  								/* 使能串口*/
}


void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
       switch (USART_ReceiveData(USART1))
	   {
		   case '1':printf("2\r\n");break;
	   }
    }
}



///重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (unsigned char) ch);    						/* 发送一个字节数据到串口 */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);    	/* 等待发送完毕 */
    return (ch);
}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
    /* 等待串口输入数据 */
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

    return (int)USART_ReceiveData(USART1);
}

//加入以下代码可以不勾选use MicroLIB
#pragma import(__use_no_semihosting)
struct __FILE
{
    int handle;
};

FILE __stdout;

void _sys_exit(int x)
{
    x = x;
}
