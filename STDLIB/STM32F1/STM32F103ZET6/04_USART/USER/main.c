#include "stm32f10x.h"

#include "myusart.h"




int main(void)
{
	//�����ж�������
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//��ʼ��USART
	my_usart1_init();
	
  while (1)
  {

	  
		
  }
  
}





