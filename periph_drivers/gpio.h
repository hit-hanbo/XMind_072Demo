#ifndef XDRV_H_
#define XDRV_H_

#include "stm32f0xx.h"

#define LGG_LED_R_ON     	GPIOC->ODR &= ~(1 << 0)
#define LGG_LED_R_OFF		GPIOC->ODR |=  (1 << 0)
#define LGG_LED_R_TOGGLE	GPIOC->ODR ^=  (1 << 0)
#define LGG_LED_G_ON     	GPIOC->ODR &= ~(1 << 6)
#define LGG_LED_G_OFF		GPIOC->ODR |=  (1 << 6)
#define LGG_LED_G_TOGGLE	GPIOC->ODR ^=  (1 << 6)

#define keyport             GPIOA
#define line1               GPIO_Pin_0
#define line2               GPIO_Pin_1
#define line3               GPIO_Pin_2
#define line4               GPIO_Pin_3
#define row1                GPIO_Pin_4
#define row2                GPIO_Pin_5
#define row3                GPIO_Pin_6
#define row4                GPIO_Pin_7

void wpc_gpio_keyline_init(void);
void wpc_gpio_keyrow_init(void);


#endif
