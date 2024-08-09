#include "stm32f10x.h"

#include "led1.h"
#include "key1.h"
#include "delay.h"

int main(void)
{
	u8 key_sta = 0;
	
	delay_init();
	LED_init();
	KEY_init();

  while (1)
  {
	key_sta = KEY_scan(1);
	if ( KEY0_PRESS == key_sta )		 							//按键0按下
	{
		GPIO_WriteBit(GPIOE, GPIO_Pin_5, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_5)));	//翻转IO电平
		//GPIO_ResetBits(GPIOE, GPIO_Pin_5);			//PE5亮	
	}
	else if ( KEY1_PRESS == key_sta )							//按键1按下
	{
		GPIO_WriteBit(GPIOB, GPIO_Pin_5, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5)));		//翻转IO电平
		//GPIO_ResetBits(GPIOB, GPIO_Pin_5);				//PB5亮
	}
	else;
		
  }
  
}





