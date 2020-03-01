#include "gpio.h"

/*
 *	 GPIO Initialize function
 *   @ Brief : Initialize GPIO PC0/PC6 as LED driver
 *   @ param : none
 *   @ retval: none
 *
 */

void LYF_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_Init_Struct;
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOCEN, ENABLE);


	/*
	 *    LEDs Pin configure
	 */
	GPIO_Init_Struct.GPIO_Pin = SYS_LED_PIN;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(SYS_LED_PORT, &GPIO_Init_Struct);

	GPIO_Init_Struct.GPIO_Pin = USR_LED_PIN;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(USR_LED_PORT, &GPIO_Init_Struct);

}
