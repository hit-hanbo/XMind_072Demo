/*
 * exti.c
 *
 *  Created on: 2020Äê3ÔÂ1ÈÕ
 *      Author: lenovo
 */
#include "exti.h"

void LYF_EXTI_Init(void)
{

	EXTI_InitTypeDef EXTIInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	EXTIInitStructure.EXTI_Line = EXTI_Line13;
	EXTIInitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIInitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTIInitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTIInitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC,EXTI_PinSource13);

	EXTIInitStructure.EXTI_Line = EXTI_Line14;
	EXTIInitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIInitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTIInitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTIInitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC,EXTI_PinSource14);

	EXTIInitStructure.EXTI_Line = EXTI_Line15;
	EXTIInitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIInitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTIInitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTIInitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC,EXTI_PinSource15);

	EXTIInitStructure.EXTI_Line = EXTI_Line2;
	EXTIInitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIInitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTIInitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTIInitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD,EXTI_PinSource2);

	NVIC_SetPriority(EXTI2_3_IRQn,2);
	NVIC_EnableIRQ(EXTI2_3_IRQn);

	NVIC_SetPriority(EXTI4_15_IRQn,2);
	NVIC_EnableIRQ(EXTI4_15_IRQn);




}



void EXTI2_3_IRQHandler(void)
{   if((EXTI->PR & EXTI_Line2) != (uint32_t)RESET)
    {

	 GPIOC->ODR ^= (1 << 0);
	 EXTI_ClearITPendingBit(EXTI_Line2);


	}

}

void EXTI4_15_IRQHandler(void)
{   if((EXTI->PR & EXTI_Line13) != (uint32_t)RESET)
    {

	 GPIOC->ODR ^= (1 << 10);
	 EXTI_ClearITPendingBit(EXTI_Line13);


	}else if((EXTI->PR & EXTI_Line14) != (uint32_t)RESET)
		{
			GPIOA->ODR ^= (1 << 9);
			EXTI_ClearITPendingBit(EXTI_Line14);

		}else if((EXTI->PR & EXTI_Line15) != (uint32_t)RESET)
		{
			GPIOB->ODR ^= (1 << 14);
			EXTI_ClearITPendingBit(EXTI_Line15);

		}

}

