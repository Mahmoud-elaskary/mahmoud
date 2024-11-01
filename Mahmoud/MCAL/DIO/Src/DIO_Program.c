/*
 * DIO_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#include "util/delay.h"
#include "../../../Common/StdType.h"
#include "../Header/DIO_Interface.h"

void DIO_SelectDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{

		if(PinNumber<=Pin7 && PinNumber>=Pin0)
		{


			if(DirectionState==Input)
			{
				switch(GroupName)
				{
				case Group_A: ClearBit(DIO_DDRA,PinNumber); break;
				case Group_B: ClearBit(DIO_DDRB,PinNumber); break;
				case Group_C: ClearBit(DIO_DDRC,PinNumber); break;
				case Group_D: ClearBit(DIO_DDRD,PinNumber); break;
				}
			}

			else if(DirectionState==Output)
			{

				switch(GroupName)
				{
				case Group_A: SetBit(DIO_DDRA,PinNumber); break;
				case Group_B: SetBit(DIO_DDRB,PinNumber); break;
				case Group_C: SetBit(DIO_DDRC,PinNumber); break;
				case Group_D: SetBit(DIO_DDRD,PinNumber); break;
				}

			}


		}


	}

}
/***************************************************************************************/


void DIO_SelectOutputStateForPin(u8 GroupName,u8 PinNumber,u8 OutputState)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{

		if(PinNumber<=Pin7 && PinNumber>=Pin0)
		{
			if(OutputState==High)
			{
				switch(GroupName)
				{
				case Group_A: SetBit(DIO_PORTA,PinNumber); break;
				case Group_B: SetBit(DIO_PORTB,PinNumber); break;
				case Group_C: SetBit(DIO_PORTC,PinNumber); break;
				case Group_D: SetBit(DIO_PORTD,PinNumber); break;
				}

			}
			else if(OutputState==Low)
			{
				switch(GroupName)
				{
				case Group_A: ClearBit(DIO_PORTA,PinNumber); break;
				case Group_B: ClearBit(DIO_PORTB,PinNumber); break;
				case Group_C: ClearBit(DIO_PORTC,PinNumber); break;
				case Group_D: ClearBit(DIO_PORTD,PinNumber); break;
				}
			}
		}

	}

}

/*****************************************************************************************/



void DIO_ReadInputValueForPin(u8 GroupName,u8 PinNumber,u8* InputValue)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		if(PinNumber<=Pin7 && PinNumber>=Pin0)
		{
			if(InputValue!=NULL)
			{
				switch(GroupName)
				{
				case Group_A: *InputValue=GetBit(DIO_PINA,PinNumber); break;
				case Group_B: *InputValue=GetBit(DIO_PINB,PinNumber); break;
				case Group_C: *InputValue=GetBit(DIO_PINC,PinNumber); break;
				case Group_D: *InputValue=GetBit(DIO_PIND,PinNumber); break;
				}
			}
		}

	}


}

/**************************************************************************************/


void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		if(DirectionState<=255 && DirectionState>=0)
		{
			switch(GroupName)
			{
			case Group_A: DIO_DDRA=DirectionState;break;
			case Group_B: DIO_DDRB=DirectionState;break;
			case Group_C: DIO_DDRC=DirectionState;break;
			case Group_D: DIO_DDRD=DirectionState;break;
			}
		}
	}
}
/**************************************************************************************/

void DIO_SelectOutputStateForGroup(u8 GroupName,u8 OutputState)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		if(OutputState<=255 && OutputState>=0)
		{
			switch(GroupName)
			{
			case Group_A: DIO_PORTA=OutputState;break;
			case Group_B: DIO_PORTB=OutputState;break;
			case Group_C: DIO_PORTC=OutputState;break;
			case Group_D: DIO_PORTD=OutputState;break;
			}
		}
	}
}

/****************************************************************************************/

void DIO_ReadInputValueForGroup(u8 GroupName,u8* InputValue)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		if(InputValue!=NULL)
		{
			switch(GroupName)
			{
			case Group_A: *InputValue=DIO_PINA;break;
			case Group_B: *InputValue=DIO_PINB;break;
			case Group_C: *InputValue=DIO_PINC;break;
			case Group_D: *InputValue=DIO_PIND;break;
			}
		}
	}
}

/*****************************************************************************************/

void DIO_ControlInternalPullUpForPin(u8 GroupName,u8 PinNumber,u8 State)
{
	if(State==Enable)
	{
		DIO_SelectDirectionForPin(GroupName,PinNumber,Input);
		DIO_SelectOutputStateForPin(GroupName,PinNumber,High);
	}
	else if(State==Disable)
	{
		DIO_SelectDirectionForPin(GroupName,PinNumber,Input);
		DIO_SelectOutputStateForPin(GroupName,PinNumber,Low);
	}
}

/********************************************************************/

void DIO_ControlInternalPullUpForGroup(u8 GroupName,u8 State)
{
	if(State<=255 && State>=0)
	{
		DIO_SelectDirectionForGroup(GroupName,State);
		DIO_SelectOutputStateForGroup(GroupName,~State);
	}
}
/*********************************************************************************/


void DIO_ToggleForPin(u8 GroupName,u8 PinNumber)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		if(PinNumber<=Pin7 && PinNumber>=Pin0)
		{
			switch(GroupName)
			{
			case Group_A: ToggleBit(DIO_PORTA,PinNumber); break;
			case Group_B: ToggleBit(DIO_PORTB,PinNumber); break;
			case Group_C: ToggleBit(DIO_PORTC,PinNumber); break;
			case Group_D: ToggleBit(DIO_PORTC,PinNumber); break;

			}
		}
	}

}
/***************************************************************************************/
void DIO_ToggleForGroup(u8 GroupName)
{
	if(GroupName<=Group_D && GroupName>=Group_A)
	{
		switch(GroupName)
		{
		  case Group_A:DIO_PORTA= ~DIO_PORTA; break;
		  case Group_B:DIO_PORTB= ~DIO_PORTB; break;
		  case Group_C:DIO_PORTC= ~DIO_PORTC; break;
		  case Group_D:DIO_PORTD= ~DIO_PORTC; break;
		}
	}
}
