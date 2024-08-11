#include "stm32f10x.h"

#include "myusart.h"




int main(void)
{
	//配置中断向量组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//初始化USART
	my_usart1_init();
	
  while (1)
  {

	  
		
  }
  
}





