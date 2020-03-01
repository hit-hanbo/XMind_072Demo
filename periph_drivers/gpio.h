#ifndef XDRV_H_
#define XDRV_H_

#include "stm32f0xx.h"

#define   SYS_LED_PORT  GPIOC
#define   SYS_LED_PIN   GPIO_Pin_0
#define   USR_LED_PORT  GPIOC
#define   USR_LED_PIN   GPIO_Pin_10
#define LGG_LED_R_ON     	GPIOC->ODR &= ~SYS_LED_PIN
#define LGG_LED_R_OFF		GPIOC->ODR |=  SYS_LED_PIN
#define LGG_LED_R_TOGGLE	GPIOC->ODR ^=  (1 << 0)
#define LGG_LED_G_ON     	GPIOC->ODR &= ~USR_LED_PIN
#define LGG_LED_G_OFF		GPIOC->ODR |=  USR_LED_PIN
#define LGG_LED_G_TOGGLE	GPIOC->ODR ^=  (1 << 6)

void bsp_lgg_gpio_init(void);


#endif
