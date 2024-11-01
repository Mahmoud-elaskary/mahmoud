/*
 * T1_Private.h
 *
 *  Created on: Aug 26, 2024
 *      Author: DELL
 */

#ifndef MCAL_TIMER1_HEADER_T1_PRIVATE_H_
#define MCAL_TIMER1_HEADER_T1_PRIVATE_H_
/*TCCR1A*/
#define T1_WGM10             0
#define T1_WGM11             1
#define T1_COM1B0            4
#define T1_COM1B1            5
#define T1_COM1A0            6
#define T1_COM1A1            7

/*TCCR1B*/
#define T1_CS10              0
#define T1_CS11              1
#define T1_CS12              2
#define T1_WGM12             3
#define T1_WGM13             4
#define T1_ICES1             6

/*TIMSK*/
#define T1_TICIE1            5
#define T1_OCIE1A            4
#define T1_OCIE1B            3
#define T1_TOIE1             2

/*TIFR*/
#define T1_ICF1              5
#define T1_OCF1A             4
#define T1_OCG1B             3
#define T1_TOV1              2

typedef enum
{
	T1_Off ,
	T1_Prescaller1,
	T1_Prescaller8,
	T1_Prescaller64,
	T1_Prescaller256,
	T1_Prescaller1024,
	T1_CounterFalling,
	T1_CounterRising,
}ClockOptions;

typedef enum
{
	Normal,
	CTC_Top_OCR1A,
	CTC_Top_ICR1,
	FastPWM_Top_ICR1,
	FastPWM_Top_OCR1A,

}Timer1Modes;

typedef enum
{
	disconnected,
	noninverting ,
	inverting ,

}CompareOutputMode;

typedef enum
{
	UnitA,
	UnitB  ,
	Both ,

}ComperUnit;

typedef enum{
	FALLING_EDGE,
	RISING_EDGE
}Edge_t;
//#define T1_FastPWMDisconnected  0
//#define T1_FastPWMNinInvarting  1
//#define T1_FastPWMInvarting     2
//
//#define T1_Stop           0
//#define T1_Prescaller1    1
//#define T1_Prescaller8    2
//
//#define  UnitA    1
//#define  UnitB    2
//#define  Both     3

#endif /* MCAL_TIMER1_HEADER_T1_PRIVATE_H_ */
