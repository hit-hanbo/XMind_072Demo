#include "stm32f0xx.h"
#include "gpio.h"

/*uint16_t KEY1_Check(void);*/
uint16_t KEY2_Check(void);

int main(void)
{
    uint16_t i;
    gpio_keyline_init();
    gpio_keyROW_init();
    gpio_led_init();
    while (1)
    {
        i =KEY2_Check();
	}
}



/*
 * 功能：矩阵键盘扫描   2*4  V1.0
 * 时间：2020.02.29-----wpc
 */
/*uint16_t KEY1_Check(void)
{
	uint16_t ReadValue,KEY=0;
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
    ReadValue = GPIO_ReadInputData(GPIOA);
    ReadValue = ReadValue&0X3C;
    if(ReadValue!=0X3C)
    {
		    if(ReadValue==0X38)
		    {
                KEY=1;
		    }
		    else if(ReadValue==0X34)
		    {
		        KEY=2;
		    }
		    else if(ReadValue==0X2c)
		    {
		        KEY=3;
		    }
	        else if(ReadValue==0X1c)
		    {
		        KEY=4;
		    }
	}
	else
	{
    		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
    		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET);
			ReadValue = GPIO_ReadInputData(GPIOA);
			ReadValue = ReadValue&0X3C;
			if(ReadValue==0X38)
		    {
                KEY=4*1+1;
		    }
		    else if(ReadValue==0X34)
		    {
		        KEY=4*1+2;
		    }
		    else if(ReadValue==0X2c)
		    {
		        KEY=4*1+3;
		    }
	        else if(ReadValue==0X1c)
		    {
		        KEY=4*1+4;
		    }
	}
    return KEY;
}*/



/*
 * 功能：矩阵键盘扫描  4*4  V2.0
 * 时间：2020.02.29-----wpc
 */
uint16_t KEY2_Check(void)
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
