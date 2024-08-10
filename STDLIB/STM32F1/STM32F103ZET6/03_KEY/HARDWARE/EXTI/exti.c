#include "key1.h"
#include "delay.h"
#include "exti.h"
#include "led1.h"


void MYEXTI_Init(void)
{
	EXTI_InitTypeDef 	EXTI_InitStruct;	//�����ⲿ�жϳ�ʼ���ṹ�����
	NVIC_InitTypeDef 	NVIC_InitStruct;	//�����ж�������ʼ���ṹ�����
	
	KEY_init();
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 				//ʹ��GPIOEʱ��
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);			//ӳ���ж���
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);			//ӳ���ж���
	
	EXTI_InitStruct.EXTI_Line		= EXTI_Line3 | EXTI_Line4;			//�ж��ߣ�3��4
	EXTI_InitStruct.EXTI_LineCmd	= ENABLE;							//ʹ���ж�
	EXTI_InitStruct.EXTI_Mode		= EXTI_Mode_Interrupt;				//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger	= EXTI_Trigger_Falling;				//�½��ش���
	EXTI_Init(&EXTI_InitStruct);										//�����жϳ�ʼ������
	
	NVIC_InitStruct.NVIC_IRQChannel						= EXTI3_IRQn;	//�ж�ͨ����EXTI3_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//ʹ���жϣ�ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//�ж���ռ���ȼ���1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//�ж���Ӧ���ȼ���1
	NVIC_Init(&NVIC_InitStruct);										//�����жϳ�ʼ������
	
	NVIC_InitStruct.NVIC_IRQChannel						= EXTI4_IRQn;	//�ж�ͨ����EXTI4_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//ʹ���жϣ�ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//�ж���ռ���ȼ���1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//�ж���Ӧ���ȼ���1
	NVIC_Init(&NVIC_InitStruct);										//�����жϳ�ʼ������
	
}

void EXTI3_IRQHandler()
{
	delay_ms(10);
	if ( 0 == KEY1 )
	{
		LED1 = !LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI4_IRQHandler()
{
	delay_ms(10);
	if ( 0 == KEY0 )
	{		
		LED0 = !LED0;		
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}




