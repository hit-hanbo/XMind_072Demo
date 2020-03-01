/*
 * timer.c
 *
 *  Created on: 2020Äê2ÔÂ28ÈÕ
 *      Author: lenovo
 */
#include "../periph_drivers/timer.h"
#include "../periph_drivers/gpio.h"


void LYF_GP_TIM14_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_Base_Init_Struct;
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM14EN, ENABLE);


	/*
	 *   TIM base Configure
	 */
	TIM_Base_Init_Struct.TIM_Prescaler = 48 - 1;
	TIM_Base_Init_Struct.TIM_Period = 60000 - 1;
	TIM_Base_Init_Struct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_Base_Init_Struct.TIM_ClockDivision = 0;
	TIM_Base_Init_Struct.TIM_RepetitionCounter = 0;
	TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
	TIM_TimeBaseInit(TIM14, &TIM_Base_Init_Struct);
	TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);
	NVIC_SetPriority(TIM14_IRQn,2);
	NVIC_EnableIRQ(TIM14_IRQn);

	TIM_Cmd(TIM14, ENABLE);

}

void TIM14_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM14, TIM_IT_Update) == SET )
	{
		TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
		GPIOC->ODR ^= (1 << 10);
		GPIOC->ODR ^= (1 << 0);

	}
}

