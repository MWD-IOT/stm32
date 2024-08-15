#include "stm32f10x.h"
#include "stm32f10x_iwdg.h"

#include "iwdg.h"



void MYIWDG_Init(u8 prer, u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);	//����д
	IWDG_SetPrescaler(prer);						//����Ԥ��Ƶϵ��
	IWDG_SetReload(rlr);							//���õ�����ֵ
	IWDG_Enable();									//ʹ�ܿ��Ź�
}


