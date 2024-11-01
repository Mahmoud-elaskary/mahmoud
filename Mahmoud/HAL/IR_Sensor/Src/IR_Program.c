/*
 * IR_Program.c
 *
 *  Created on: Oct 2, 2024
 *      Author: moham
 */


#include "../../../Common/StdType.h"
#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"



void IR_Init(void)
{
	DIO_SelectDirectionForPin(Group_C, Pin0, Input);
	DIO_SelectDirectionForPin(Group_C, Pin1, Input);
}

u8 IR_Read_RightIR(void)
{
	u8 state =1 ;
	if(state!=NULL)
	{
		DIO_ReadInputValueForPin(Group_C, Pin0 , &state);

	}
	return state ;
}
u8 IR_Read_LeftIR(void)
{
	u8 state =1 ;
	if(state!=NULL)
	{
		DIO_ReadInputValueForPin(Group_C, Pin1 , &state);


	}
	return state ;
}


