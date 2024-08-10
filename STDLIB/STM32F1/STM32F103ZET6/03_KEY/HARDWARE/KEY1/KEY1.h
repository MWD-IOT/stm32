#ifndef __KEY1_H_
#define __KEY1_H_

#include "sys.h" 

#define KEY0  		GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)//��ȡ����0
#define KEY1  		GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)//��ȡ����1
#define WK_UP  		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)//��ȡ����WK_UP

#define KEY0_PRESS  1
#define KEY1_PRESS	2
#define WK_UP_PRESS	3

void KEY_init(void);
u8 KEY_scan(u8 mode);

#endif 


