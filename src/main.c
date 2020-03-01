



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
<<<<<<< HEAD
=======
    uint32_t i = 0;
>>>>>>> refs/remotes/origin/master

<<<<<<< HEAD
=======
    /* TODO - Add your application code here */
>>>>>>> refs/remotes/origin/master

<<<<<<< HEAD
	LYF_GPIO_Init();
	LYF_LED_R_ON;
    LYF_LED_G_OFF;
    LYF_GP_TIM14_Init();
    while(1);

=======
    /* Infinite loop */
    while (1)
    {
	  i++;
    }
>>>>>>> refs/remotes/origin/master
}
