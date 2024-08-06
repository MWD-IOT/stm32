#include "stm32f10x.h"

#include "myusart.h"

void my_usart1_init(void)
{
	//声明相关变量
	GPIO_InitTypeDef 	GPIO_InitStruct;					//声明GPIO初始化结构体变量
	USART_InitTypeDef 	USART_InitStruct;					//声明USART初始化结构体变量
	NVIC_InitTypeDef 	NVIC_InitStruct;					//声明中断初始化结构体变量
	
	//使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能GPIO时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//使能USART1时钟
	
	//初始化GPIO
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF_PP;			//复用推挽输出模式
	GPIO_InitStruct.GPIO_Pin 	= GPIO_Pin_9;				//PA9
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Speed_50MHz;			//50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruct);						//调用GPIO初始化函数
	
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_IN_FLOATING;	//浮空输入模式
	GPIO_InitStruct.GPIO_Pin 	= GPIO_Pin_10;				//PA10
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Speed_50MHz;			//50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruct);						//调用GPIO初始化函数
	
	
	//初始化USART
	USART_InitStruct.USART_BaudRate 			= 9600;								//波特率：9600
	USART_InitStruct.USART_WordLength 			= USART_WordLength_8b;				//字长：8位
	USART_InitStruct.USART_StopBits 			= USART_StopBits_1;					//停止位：1位
	USART_InitStruct.USART_Parity 				= USART_Parity_No;					//奇偶校验：无
	USART_InitStruct.USART_HardwareFlowControl 	= USART_HardwareFlowControl_None;	//硬件流：无
	USART_InitStruct.USART_Mode 				= USART_Mode_Rx | USART_Mode_Tx;	//收、发模式
	USART_Init(USART1, &USART_InitStruct);											//调用USART初始化函数
	
	//使能USART
	USART_Cmd(USART1, ENABLE);	//使能USART
	
	//初始化串USART中断
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);	//使能USART中断
	
	NVIC_InitStruct.NVIC_IRQChannel						= USART1_IRQn;	//中断通道：USART1_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		//使能中断：ENABLE
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			//中断抢占优先级：1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			//中断响应优先级
	NVIC_Init(&NVIC_InitStruct);										//调用中断初始化函数
	
	
	
}

//中断服务函数
void USART1_IRQHandler(void)
{
	u8 recv;
	if ( USART_GetITStatus(USART1, USART_IT_RXNE) ) 
	{
		recv = USART_ReceiveData(USART1);
		USART_SendData(USART1, recv);
	}
}



