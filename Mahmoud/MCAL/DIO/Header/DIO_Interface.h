/*
 * DIO_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

#include "../../../Common/StdType.h"
#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"

#include "DIO_Register.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


void  DIO_SelectDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState);

void DIO_SelectOutputStateForPin(u8 GroupName,u8 PinNumber,u8 OutputState);

void DIO_ReadInputValueForPin(u8 GroupName,u8 PinNumber,u8 *InputValue);

void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState);

void DIO_SelectOutputStateForGroup(u8 GroupName,u8 OutputState);

void DIO_ReadInputValueForGroup(u8 GroupName,u8 *InputValue);

void DIO_ControlInternalPullUpForPin(u8 GroupName,u8 PinNumber,u8 State);

void DIO_ControlInternalPullUpForGroup(u8 GroupName,u8 State);
void DIO_ToggelValueForPin(u8 GroupName,u8 PinNumber);
void DIO_ToggelValueForGroup(u8 GroupName);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
