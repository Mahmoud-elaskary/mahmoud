/*
 * T1_Register.h
 *
 *  Created on: Aug 26, 2024
 *      Author: DELL
 */

#ifndef MCAL_TIMER1_HEADER_T1_REGISTER_H_
#define MCAL_TIMER1_HEADER_T1_REGISTER_H_
#include "../../../Common/StdType.h"

#define T1_TCCR1A          *((volatile u8*) 0x4F)
#define T1_TCCR1B          *((volatile u8*) 0x4E)
#define T1_TCNT1           *((volatile u16*)0x4C)
#define T1_OCR1A           *((volatile u16*)0x4A)
#define T1_OCR1B           *((volatile u16*)0x48)
#define T1_ICR1            *((volatile u16*)0x46)
#define T1_TIMSK           *((volatile u8*) 0x59)
#define T1_TIFR            *((volatile u8*) 0x58)



#endif /* MCAL_TIMER1_HEADER_T1_REGISTER_H_ */
