#ifndef XDRV_H_
#define XDRV_H_

#include "stm32f0xx.h"

#define   SYS_LED_PORT  GPIOC
#define   SYS_LED_PIN   GPIO_Pin_0
#define   USR_LED_PORT  GPIOC
#define   USR_LED_PIN   GPIO_Pin_10
#define   PWM_LED1_PORT  GPIOA
#define   PWM_LED1_PIN   GPIO_Pin_9
#define   PWM_LED2_PORT  GPIOB
#define   PWM_LED2_PIN   GPIO_Pin_14

#define LYF_LED_R_ON     	GPIOC->ODR &= ~SYS_LED_PIN
#define LYF_LED_R_OFF		GPIOC->ODR |=  SYS_LED_PIN
#define LYF_LED_G_ON     	GPIOC->ODR &= ~USR_LED_PIN
#define LYF_LED_G_OFF		GPIOC->ODR |=  USR_LED_PIN
#define LYF_PWM_LED1_ON     GPIOA->ODR |= PWM_LED1_PIN
#define LYF_PWM_LED2_ON     GPIOB->ODR |= PWM_LED2_PIN


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
void LYF_KEY_GPIO_Init(void);
void LYF_LED_GPIO_Init(void);

#endif
