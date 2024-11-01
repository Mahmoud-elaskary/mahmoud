/*
 * EXTI_Program.c
 *
 *  Created on: Aug 15, 2024
 *      Author: DELL
 */
#include "../Header/EXTI_Interface.h"

void EXTI0_Init(u8 Sens_Control)
{
	if(Sens_Control == Falling)
	{
		ClearBit(EXTI_MCUCR , ISC00);
		SetBit(EXTI_MCUCR , ISC01);

	}
	else if (Sens_Control == Rising)
	{
		SetBit(EXTI_MCUCR , ISC00);
		SetBit(EXTI_MCUCR , ISC01);
	}
	else if (Sens_Control == Low_Level)
	{
		ClearBit(EXTI_MCUCR , ISC00);
		ClearBit(EXTI_MCUCR , ISC01);
	}
	else if (Sens_Control == AnyLogic)
	{
		SetBit(EXTI_MCUCR , ISC00);
		ClearBit(EXTI_MCUCR , ISC01);
	}

	// Enable INT0


	SetBit(EXTI_GICR,INT0);

}
/**********************************************************/
void EXTI1_Init(u8 Sens_Control )
{
	if(Sens_Control == Falling)
	{
		ClearBit(EXTI_MCUCR , ISC10);
		SetBit(EXTI_MCUCR , ISC11);

	}
	else if (Sens_Control == Rising)
	{
		SetBit(EXTI_MCUCR , ISC10);
		SetBit(EXTI_MCUCR , ISC11);
	}
	else if (Sens_Control == Low_Level)
	{
		ClearBit(EXTI_MCUCR , ISC11);
		ClearBit(EXTI_MCUCR , ISC10);
	}
	else if (Sens_Control == AnyLogic)
	{
		SetBit(EXTI_MCUCR , ISC10);
		ClearBit(EXTI_MCUCR , ISC11);
	}

	//Enable INT1
	SetBit(EXTI_GICR,INT1);
}

void EXTI2_Init(u8 Sens_Control )
{
	if(Sens_Control == Falling)
	{
		ClearBit(EXTI_MCUCR , ISC2);
	}
	else if (Sens_Control == Rising)
	{
		SetBit(EXTI_MCUCR , ISC2);
	}
	//Enable INT2
	SetBit(EXTI_GICR,INT2);
}
