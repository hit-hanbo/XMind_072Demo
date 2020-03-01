#include "stm32f0xx.h"
#include "gpio.h"



int main(void)
{
    uint16_t i;
    wpc_gpio_keyline_init();
    wpc_gpio_keyrow_init();
    while (1)
    {
        i =wpc_keyscan();
	}
}


