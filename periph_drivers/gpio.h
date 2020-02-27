#ifndef XDRV_H_
#define XDRV_H_

#include "stm32f072xb.h"

#define LGG_LED_R_ON     	GPIOC->ODR &= ~(1 << 0)
#define LGG_LED_R_OFF		GPIOC->ODR |=  (1 << 0)
#define LGG_LED_R_TOGGLE	GPIOC->ODR ^=  (1 << 0)
#define LGG_LED_G_ON     	GPIOC->ODR &= ~(1 << 6)
#define LGG_LED_G_OFF		GPIOC->ODR |=  (1 << 6)
#define LGG_LED_G_TOGGLE	GPIOC->ODR ^=  (1 << 6)

void bsp_lgg_gpio_init(void);


#endif
