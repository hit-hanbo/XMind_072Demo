#include "gpio.h"

/*
 *	 GPIO Initialize function
 *   @ Brief : Initialize GPIO PC0/PC6 as LED driver
 *   @ param : none
 *   @ retval: none
 *
 */
void bsp_lgg_gpio_init(void)
{
	/*  1. enable GPIOC clock  */
	RCC->AHBENR |= (1 << 19);

	/*  2. set PC0/PC6 0, OUT, PP, Pull-Down, Low-Speed */
	GPIOC->ODR &= ~(1 << 0 | 1 << 6);
	GPIOC->MODER = (GPIOC->MODER) & (~((0x3 << 0) | (0x3 << 12))) | ((1 << 0) | (1 << 6));
	GPIOC->OTYPER &= ~(1 << 0 | 1 << 6);
	GPIOC->PUPDR = (GPIOC->PUPDR) & (~((0x3 << 0) | (0x3 << 12))) | ((1 << 1) | (1 << 7));
	GPIOC->OSPEEDR = (GPIOC->OSPEEDR) & (~(0x3 << 0 | 0x3 << 6));

}

void HiSTM_GPIO_Init(void)
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
