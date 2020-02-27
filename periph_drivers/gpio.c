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

