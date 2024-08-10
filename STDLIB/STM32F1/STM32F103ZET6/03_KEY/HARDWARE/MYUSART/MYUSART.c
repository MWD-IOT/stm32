#include "stm32f10x.h"

#include "myusart.h"

void my_usart1_init(void)
{
	//������ر���
	GPIO_InitTypeDef 	GPIO_InitStruct;					//����GPIO��ʼ���ṹ�����
	USART_InitTypeDef 	USART_InitStruct;					//����USART��ʼ���ṹ�����
	NVIC_InitTypeDef 	NVIC_InitStruct;					//�����жϳ�ʼ���ṹ�����
	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIOʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//ʹ��USART1ʱ��
	
	//��ʼ��GPIO
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF_PP;			//�����������ģʽ
	GPIO_InitStruct.GPIO_Pin 	= GPIO_Pin_9;				//PA9
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Speed_50MHz;			//50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruct);						//����GPIO��ʼ������
	
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_IN_FLOATING;	//��������ģʽ
	GPIO_InitStruct.GPIO_Pin 	= GPIO_Pin_10;				//PA10
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Speed_50MHz;			//50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruct);						//����GPIO��ʼ������
	
	
	//��ʼ��USART
	USART_InitStruct.USART_BaudRate 			= 9600;								//�����ʣ�9600
	USART_InitStruct.USART_WordLength 			= USART_WordLength_8b;				//�ֳ���8λ
	USART_InitStruct.USART_StopBits 			= USART_StopBits_1;					//ֹͣλ��1λ
	USART_InitStruct.USART_Parity 				= USART_Parity_No;					//��żУ�飺��
	USART_InitStruct.USART_HardwareFlowControl 	= USART_HardwareFlowControl_None;	//Ӳ��������
	USART_InitStruct.USART_Mode 				= USART_Mode_Rx | USART_Mode_Tx;	//�ա���ģʽ
	USART_Init(USART1, &USART_InitStruct);											//����USART��ʼ������
	
	//ʹ��USART
	USART_Cmd(USART1, ENABLE);	//ʹ��USART
	
	//��ʼ����USART�ж�
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);	//ʹ��USART�ж�
	
	NVIC_InitStruct.NVIC_IRQChannel						= USART1_IRQn;	//�ж�ͨ����USART1_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//ʹ���жϣ�ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//�ж���ռ���ȼ���1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//�ж���Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStruct);										//�����жϳ�ʼ������
	
	
	
}

//�жϷ�����
void USART1_IRQHandler(void)
{
	u8 recv;
	if ( USART_GetITStatus(USART1, USART_IT_RXNE) ) 
	{
		recv = USART_ReceiveData(USART1);
		USART_SendData(USART1, recv);
	}
}



