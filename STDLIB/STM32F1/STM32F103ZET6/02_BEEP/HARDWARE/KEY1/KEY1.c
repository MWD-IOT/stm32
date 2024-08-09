#include "stm32f10x.h"

#include "key1.h"
#include "delay.h"

void KEY_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE, ENABLE); //使能GPIOA、GPIOE时钟
		
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_0; 							//端口号：PA0
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; 					//频率：50MHz
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IPD; 						//模式：下拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);									//初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3 | GPIO_Pin_4; 				//端口号：PE3、PE4
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; 					//频率：50MHz
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IPU; 						//模式：上拉输入
	GPIO_Init(GPIOE, &GPIO_InitStructure);									//初始化GPIO
}

u8 KEY_scan(u8 mode)
{
	static u8 key_up = 1;	//静态变量，默认为1代表按键没按下
	if ( 1 == mode )		//判断模式，1支持连续按，0不支持连续按
	{
		key_up = 1;				//连续按模式，key_up恒为1，即不具备记忆上一次按键状态的功能
	}
	if ( key_up && (0 == KEY0 || 0 == KEY1 || 1 == WK_UP) )
	{
		delay_ms(10);			//消抖	
		if ( 0 == KEY0 )		//KEY0被按下
		{
			key_up = 0;			//记录按键状态，0代表按下
			return KEY0_PRESS;
		}
		else if ( 0 == KEY1 )	//KEY0被按下
		{
			key_up = 0;			//记录按键状态，0代表按下
			return KEY1_PRESS;
		}
		else if ( 1 == WK_UP )	//WK_UP被按下
		{
			key_up = 0;			//记录按键状态，0代表按下
			return WK_UP_PRESS;
		}
	}
	else if ( (1 == KEY0) && (1 == KEY1) && (0 == WK_UP) )	//如果没有按键按下
	{
		key_up = 1;				//记录按键状态，1代表按下
	}
	return 0;
}


