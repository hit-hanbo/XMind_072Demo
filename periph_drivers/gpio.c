#include "gpio.h"

/*
 * Matrix key initialize function
 */

void wpc_gpio_keyline_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=line1|line2|line3|line4;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_Level_3;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}


void wpc_gpio_keyrow_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin=row1|row2|row3|row4;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_Level_3;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

/*
 * 功能：矩阵键盘扫描  4*4  V2.0
 * 时间：2020.02.29-----wpc
 */
uint16_t wpc_keyscan(void)
{
	uint16_t a,ReadValue,KEY=0;
	for(a=0;a<4;a++)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_All, Bit_RESET);
		GPIOA->ODR = ~(1 << a);
		ReadValue = GPIO_ReadInputData(GPIOA);
		ReadValue &= 0xF0;
		if(ReadValue != 0XF0)
		{
		    if(ReadValue == 0XE0)
		    {
		    	 KEY = 4*a+1;
		    }
		    else if(ReadValue == 0XD0)
		    {
		        KEY = 4*a+2;
		    }
	        else if(ReadValue == 0XB0)
		    {
		        KEY = 4*a+3;
		    }
	        else if(ReadValue == 0X70)
		    {
			    KEY = 4*a+4;
		    }
		}
	}
	return KEY;
}



