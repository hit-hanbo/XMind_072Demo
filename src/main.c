



/* Includes */
#include "stm32f0xx.h"
#include "main.h"
#include "../periph_drivers/gpio.h"
#include "../periph_drivers/exti.h"


/* Private macro */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
**/


int main(void)
{
	LYF_GPIO_Init();
	LYF_PWM_LED1_ON;
	LYF_PWM_LED2_ON;
	LYF_EXTI_Init();
	while(1);
}
