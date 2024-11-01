/*
 * T1_Interface.h
 *
 *  Created on: Aug 26, 2024
 *      Author: DELL
 */

#ifndef MCAL_TIMER1_HEADER_T1_INTERFACE_H_
#define MCAL_TIMER1_HEADER_T1_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/StdType.h"
#include "../../../Common/Definition.h"

#include "T1_Register.h"
#include "T1_Private.h"
#include "T1_Config.h"

void T1_Init(Timer1Modes Mode,ClockOptions Clock,CompareOutputMode State);
void T1_OutputCompareInterruptEnable(ComperUnit Unit);
void T1_OutputCompareInterruptDisable(ComperUnit Unit);
void T1_Interrupt_Enable();
void T1_Interrupt_Disable();
void T1_SetCallBack(void (*tmr1_ptf)(void));
void T1_SetCallBack_COMPA(void (*tmr1_ptf)(void));

void T1_ICU_SetCallBack(void (*(TMR1_ICU)) (void));
void T1_Interrupt_CAPT_Disable();
void T1_InputCpetureEdge(Edge_t _edge);
void T1_ICU_InterruptEnable();
void T1_ICU_InterruptDisnable();
/*******************************************************************************/
//void T1_NormalModeInit();
//void T1_CTCModeInit();
//void T1_FastPWM(u8 Type);
//void T1_EnableICU();
//void T1_ChangeCompareValue(u16 CompareValue , u8 CompareUnit);

/*Normal Mode */
void __vector_9(void) __attribute__((signal));
/*CTC Mode Compare Match B*/
void __vector_8(void) __attribute__((signal));
/*CTC Mode Compare Match A*/
void __vector_7(void) __attribute__((signal));
/*Capture Event*/
void __vector_6(void) __attribute__((signal));
#endif /* MCAL_TIMER1_HEADER_T1_INTERFACE_H_ */
