/*
 * Ultrasonic_Program.c
 *
 *  Created on: Oct 21, 2024
 *      Author: DELL
 */
#include <util/delay.h>

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/Timer1/Header/T1_Interface.h"
#include "../../../HAL/Servo/Header/Servo_Interface.h"
#include "../Header/Ultrasonic_Interface.h"

static volatile u16 ut1 =0;
static volatile u16 ut2=0;
volatile u16 uflag=0;
static volatile u16 c=0;
static void Func_ICU();
static void TMR_OVR();

void Ultrasonic_Init()

{
	Servo_Init();
	DIO_SelectDirectionForPin(Group_B,Pin0,Output);
	T1_ICU_SetCallBack(Func_ICU);
	T1_SetCallBack_COMPA(TMR_OVR);


}
u16 UltrasonicReadDistance()
{
	u8 distance=0;
	u16 time=0;
	c=0;
	uflag=0;
	T1_TCNT1=0;

	DIO_SelectOutputStateForPin(Group_B,Pin0,Low);
	_delay_us(2);
	DIO_SelectOutputStateForPin(Group_B,Pin0,High);
	_delay_us(10);
	DIO_SelectOutputStateForPin(Group_B,Pin0,Low);

	T1_InputCpetureEdge(RISING_EDGE);
	T1_ICU_InterruptEnable();
	while(uflag<2);
	time=ut2-ut1 + ((u32) 65535*c);
	distance=time/58;
	T1_ICU_InterruptDisnable();
	return distance;
}
static void Func_ICU()
{
	if(uflag==0)
	{
		c=0;
		ut1=T1_ICR1;
		uflag=1;
		T1_InputCpetureEdge(FALLING_EDGE);

	}
	else if(uflag == 1)
	{
		ut2=T1_ICR1;
		uflag=2;
		T1_InputCpetureEdge(RISING_EDGE);
		T1_ICU_InterruptDisnable();
		T1_OutputCompareInterruptDisable(UnitA);

	}
}
static void TMR_OVR()
{
	c++;
}
