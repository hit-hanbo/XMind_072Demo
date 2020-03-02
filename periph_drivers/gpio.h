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

void LYF_GPIO_Init(void);

#endif
