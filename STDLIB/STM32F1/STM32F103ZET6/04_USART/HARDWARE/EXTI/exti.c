#include "key1.h"
#include "delay.h"
#include "exti.h"
#include "led1.h"


void MYEXTI_Init(void)
{
	EXTI_InitTypeDef 	EXTI_InitStruct;	//声明外部中断初始化结构体变量
	NVIC_InitTypeDef 	NVIC_InitStruct;	//声明中断向量初始化结构体变量
	
	KEY_init();
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 				//使能GPIOE时钟
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);			//映射中断线
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);			//映射中断线
	
	EXTI_InitStruct.EXTI_Line		= EXTI_Line3 | EXTI_Line4;			//中断线：3、4
	EXTI_InitStruct.EXTI_LineCmd	= ENABLE;							//使能中断
	EXTI_InitStruct.EXTI_Mode		= EXTI_Mode_Interrupt;				//中断模式
	EXTI_InitStruct.EXTI_Trigger	= EXTI_Trigger_Falling;				//下降沿触发
	EXTI_Init(&EXTI_InitStruct);										//调用中断初始化函数
	
	NVIC_InitStruct.NVIC_IRQChannel						= EXTI3_IRQn;	//中断通道：EXTI3_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//使能中断：ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//中断抢占优先级：1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//中断响应优先级：1
	NVIC_Init(&NVIC_InitStruct);										//调用中断初始化函数
	
	NVIC_InitStruct.NVIC_IRQChannel						= EXTI4_IRQn;	//中断通道：EXTI4_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//使能中断：ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//中断抢占优先级：1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//中断响应优先级：1
	NVIC_Init(&NVIC_InitStruct);										//调用中断初始化函数
	
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




