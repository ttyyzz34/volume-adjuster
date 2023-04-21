#include "usart1.h"


void USART1_Init(unsigned int Bound)
{

    Usart1_Pin_Init();
    // ���ô��ڵĹ�������
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = Bound;											// ���ò�����
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;							// ���� �������ֳ�
    USART_InitStructure.USART_StopBits = USART_StopBits_1;								// ����ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No ;								// ����У��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		// ����Ӳ��������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						// ���ù���ģʽ���շ�һ��
    USART_Init(USART1, &USART_InitStructure);											// ��ɴ��ڵĳ�ʼ������

	// �����ж����ȼ�����

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  			/* Ƕ�������жϿ�������ѡ�� */

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			/* ����USARTΪ�ж�Դ */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  	/* �������ȼ�*/
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  		/* �����ȼ� */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  			/* ʹ���ж� */
    NVIC_Init(&NVIC_InitStructure);  							/* ��ʼ������NVIC */

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);				/* ʹ�ܴ��ڽ����ж�*/
    USART_Cmd(USART1, ENABLE);	  								/* ʹ�ܴ���*/
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



///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (unsigned char) ch);    						/* ����һ���ֽ����ݵ����� */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);    	/* �ȴ�������� */
    return (ch);
}

///�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
    /* �ȴ������������� */
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

    return (int)USART_ReceiveData(USART1);
}

//�������´�����Բ���ѡuse MicroLIB
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
