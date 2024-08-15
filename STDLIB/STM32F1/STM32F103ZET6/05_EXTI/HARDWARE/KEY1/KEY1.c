#include "stm32f10x.h"

#include "key1.h"
#include "delay.h"

void KEY_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE, ENABLE); //ʹ��GPIOA��GPIOEʱ��
		
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_0; 							//�˿ںţ�PA0
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; 					//Ƶ�ʣ�50MHz
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IPD; 						//ģʽ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);									//��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3 | GPIO_Pin_4; 				//�˿ںţ�PE3��PE4
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; 					//Ƶ�ʣ�50MHz
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IPU; 						//ģʽ����������
	GPIO_Init(GPIOE, &GPIO_InitStructure);									//��ʼ��GPIO
}

u8 KEY_scan(u8 mode)
{
	static u8 key_up = 1;	//��̬������Ĭ��Ϊ1������û����
	if ( 1 == mode )		//�ж�ģʽ��1֧����������0��֧��������
	{
		key_up = 1;				//������ģʽ��key_up��Ϊ1�������߱�������һ�ΰ���״̬�Ĺ���
	}
	if ( key_up && (0 == KEY0 || 0 == KEY1 || 1 == WK_UP) )
	{
		delay_ms(10);			//����	
		if ( 0 == KEY0 )		//KEY0������
		{
			key_up = 0;			//��¼����״̬��0������
			return KEY0_PRESS;
		}
		else if ( 0 == KEY1 )	//KEY0������
		{
			key_up = 0;			//��¼����״̬��0������
			return KEY1_PRESS;
		}
		else if ( 1 == WK_UP )	//WK_UP������
		{
			key_up = 0;			//��¼����״̬��0������
			return WK_UP_PRESS;
		}
	}
	else if ( (1 == KEY0) && (1 == KEY1) && (0 == WK_UP) )	//���û�а�������
	{
		key_up = 1;				//��¼����״̬��1������
	}
	return 0;
}


