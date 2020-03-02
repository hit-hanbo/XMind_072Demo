#include "gpio.h"

/*
 *	 GPIO Initialize function
 *   @ Brief : Initialize GPIO PC0/PC6 as LED driver
 *   @ param : none
 *   @ retval: none
 *
 */

void LYF_KEY_GPIO_Init(void)
{
	  GPIO_InitTypeDef  GPIO_Init_Struct;
	  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOCEN, ENABLE);
	  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIODEN, ENABLE);
	  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOAEN, ENABLE);
	  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOBEN, ENABLE);

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

	  GPIO_Init_Struct.GPIO_Pin =PWM_LED1_PIN ;
	  GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	  GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_Init(PWM_LED1_PORT, &GPIO_Init_Struct);

  	GPIO_Init_Struct.GPIO_Pin =PWM_LED2_PIN ;
	  GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	  GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_Init(PWM_LED2_PORT, &GPIO_Init_Struct);

	  GPIO_Init_Struct.GPIO_Pin =GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15 ;
	  GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_Init(GPIOC, &GPIO_Init_Struct);

	  GPIO_Init_Struct.GPIO_Pin =GPIO_Pin_2 ;
	  GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_Init(GPIOD, &GPIO_Init_Struct);
}

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


void LYF_LED_GPIO_Init(void)
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

