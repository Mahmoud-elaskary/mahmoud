/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 15, 2024
 *      Author: DELL
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "../../../Common/StdType.h"
#include "../../../Common/BitMath.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"



void EXTI0_Init(u8 Sens_Control);
void EXTI1_Init(u8 Sens_Control);
void EXTI2_Init(u8 Sens_Control);

void __vector_1(void)  __attribute__((signal));   //->1      -> INT0
void __vector_2(void)  __attribute__((signal));   //->2      -> INT1
void __vector_3(void)  __attribute__((signal));   //->3      -> INT2





#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
