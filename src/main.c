



/* Includes */
#include "stm32f0xx.h"
#include "main.h"
#include "../periph_drivers/gpio.h"
#include "../periph_drivers/timer.h"


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
void HiSTM_SystemClock_Init(void);


int main(void)
{


	HiSTM_GPIO_Init();
	LGG_LED_R_ON;
    LGG_LED_G_OFF;
    HiSTM_GP_TIM14_Init();
    while(1);

}
