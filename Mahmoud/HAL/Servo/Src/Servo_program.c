/*
 * Servo_program.c
 *
 *  Created on: Oct 6, 2024
 *      Author: DELL
 */

#include "../Header/Servo_Interface.h"
void Servo_Init(void)
{
	/*

	        making frequecny equal to 50Hz, how?
	        CPU_freq=8MHz       &  prescaler = 8
	        so TIMER_Freq= 1MHz &  tick_time= 1 usec
	        time = 1/50 hz = 20msec =20000usec
	        so setting value of ICR1 to be 19999 cause it takes another step from 19999 to 0
	        By varing the duty cycle between 999 to 1999 we get 0 to 180

	 */
	DIO_SelectDirectionForPin(Group_D,Pin4,Output);
	T1_Init(FastPWM_Top_OCR1A,T1_Prescaller8,noninverting);
	T1_OutputCompareInterruptEnable(Both);
	T1_OCR1A=19999;
	//T1_OCR1B=999;


}
void Servo_SetAngle(u8 Angle)
{
//	u16 OCRAValue = (((u32)Angle * 2000) / 180) + 599;
//	T1_OCR1B= OCRAValue;

	u16 OCRAValue = (((u32)Angle * 1000) / 180) + 999;
	T1_OCR1B= OCRAValue;
}
