/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Oct 21, 2024
 *      Author: DELL
 */

#ifndef HAL_ULTRASONIC_HEADER_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_HEADER_ULTRASONIC_INTERFACE_H_
#include "../../../Common/BitMath.h"
#include "../../../Common/StdType.h"
#include "../../../Common/Definition.h"
typedef struct{
	u16 Echo;
	u16 Trigger;
}Ultrasonic_t;

void Ultrasonic_Init();
u16 UltrasonicReadDistance();
#endif /* HAL_ULTRASONIC_HEADER_ULTRASONIC_INTERFACE_H_ */
