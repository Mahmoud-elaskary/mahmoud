/*
 * GIE_Program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */

#include "../Header/GIE_Interface.h"




void GIE_Enable()
{
	SetBit(SREG,GIE_Pin);
}
void GIE_Disable()
{
	ClearBit(SREG,GIE_Pin);
}
