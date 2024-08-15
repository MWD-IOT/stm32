#include "stm32f10x.h"

#include "exti.h"
#include "led1.h"
#include "key1.h"
#include "delay.h"
#include "usart.h"


int main(void)
{
	delay_init();
	uart_init(9600);
	LED_Init();
	MYEXTI_Init();
	
	//配置中断向量组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
  while (1)
  {
	delay_ms(1000);
  }
  
}





