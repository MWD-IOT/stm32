#include "stm32f10x.h"
#include "stm32f10x_iwdg.h"

#include "iwdg.h"



void MYIWDG_Init(u8 prer, u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);	//允许写
	IWDG_SetPrescaler(prer);						//设置预分频系数
	IWDG_SetReload(rlr);							//设置倒计数值
	IWDG_Enable();									//使能看门狗
}


