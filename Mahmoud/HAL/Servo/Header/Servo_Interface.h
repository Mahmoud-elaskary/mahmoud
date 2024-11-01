/*
 * Serrvo_Interface.h
 *
 *  Created on: Oct 6, 2024
 *      Author: DELL
 */

#ifndef HAL_Serrvo_HEADER_Serrvo_INTERFACE_H_
#define HAL_Serrvo_HEADER_Serrvo_INTERFACE_H_

#include "../../../MCAL/Timer1/Header/T1_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"


void Servo_Init(void);
void Servo_SetAngle(u8 Angle);
#endif /* HAL_Serrvo_HEADER_Serrvo_INTERFACE_H_ */
