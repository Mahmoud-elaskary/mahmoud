/*
 * T1_Program.c
 *
 *  Created on: Aug 26, 2024
 *      Author: DELL
 */
#include "../Header/T1_Interface.h"

static void (*(TMR1_InterriptOveFlow)) (void);
static void (*(TMR1_InterrupICU)) (void);
static void (*(TMR1_InterriptComA)) (void);
static void (*(TMR1_InterriptComB)) (void);
static void Func_ICU();
u8 flag=0;
volatile u16 t1=0;
volatile u16 t2=0;
volatile u16 t3=0;



//static u8  ClockSelectValue =ClockSelectInit;
//static u16  PreloadValue     = PreloadValueInit;
//static u32 NoOFOVFCount     = NoOFOVFCountInit;
//static u8 FastPWMMode = FastPWMModeInit ;
//static u8 T2 = 0 ;
//static u8 T3 = 0 ;
//
//static u16 TopValue  = TopValueInit;
//static u16 CompareValue_A = CompareValueInit_A;
//static u16 CompareValue_B = CompareValueInit_B;

//void T1_FastPWM(u8 Type)
//{
//	if(Type==1)
//	{
//		//fast
//	}
//	if(Type==2)
//	{
//
//	}
//	if(Type==3)
//	{
//
//	}
//	if(Type==4)
//	{
//		u8 TCCR1ATemp = 0;
//		u8 TCCR1BTemp = 0;
//		//FastPWM ICR1 --->Mode 14
//		ClearBit(TCCR1ATemp,0);
//		SetBit(TCCR1ATemp,1);
//		SetBit(TCCR1BTemp,3);
//		SetBit(TCCR1BTemp,4);
//		//Check if Inverting Nin Inverting
//		if(FastPWMMode==T1_FastPWMNinInvarting)
//		{
//			//TCCR1ATemp Unit A
//			ClearBit(TCCR1ATemp,6);
//			SetBit(TCCR1ATemp,7);
//			//TCCR1ATemp Unit B
//			ClearBit(TCCR1ATemp,4);
//			SetBit(TCCR1ATemp,5);
//		}
//		else if (FastPWMMode==T1_FastPWMInvarting)
//		{
//			//TCCR1ATemp Unit A
//			SetBit(TCCR1ATemp,6);
//			SetBit(TCCR1ATemp,7);
//			//TCCR1ATemp Unit B
//			SetBit(TCCR1ATemp,4);
//			SetBit(TCCR1ATemp,5);
//		}
//		else
//		{
//			//TCCR1ATemp Unit A
//			ClearBit(TCCR1ATemp,6);
//			ClearBit(TCCR1ATemp,7);
//			//TCCR1ATemp Unit B
//			ClearBit(TCCR1ATemp,4);
//			ClearBit(TCCR1ATemp,5);
//		}
//		//Update The Top Value For ICR1
//		T1_ICR1 = TopValue;
//		//Update the CompareValue for Unit A
//		T1_OCR1A = CompareValue_A ;
//		//Update the Compare Value for Unit B
//		T1_OCR1B = CompareValue_B ;
//		//Select the Clock Select
//		TCCR1BTemp&=0xf8;
//		TCCR1BTemp|=ClockSelectValue;
//		T1_TCCR1A = TCCR1ATemp;
//		T1_TCCR1B = TCCR1BTemp;
//
//	}
//	if(Type==5)
//	{
//
//	}
//}
//
//void T1_ChangeCompareValue(u16 CompareValue , u8 CompareUnit)
//{
//	if (CompareUnit == UnitA)
//	{
//		T1_OCR1A = CompareValue;
//	}
//	else if (CompareUnit == UnitB)
//	{
//		T1_OCR1B = CompareValue;
//	}
//	else if (CompareUnit == Both)
//	{
//		T1_OCR1A = CompareValue;
//		T1_OCR1B = CompareValue;
//	}
//}
//
//
//
//void T1_NormalModeInit()
//{
//	u8 TCCR1ATemp=0;
//	u8 TCCR1BTemp=0;
//	/*Normal Mode*/
//	ClearBit(TCCR1ATemp,0);
//	ClearBit(TCCR1ATemp,1);
//	ClearBit(TCCR1BTemp,3);
//	ClearBit(TCCR1BTemp,4);
//	/*Update the PreloadValue*/
//	T1_TCNT1 = PreloadValue;
//	/*Enable Normal Mode Interrupt*/
//	SetBit(T1_TIMSK,2);
//	/*Prescaler*/
//	T1_TCCR1A=TCCR1ATemp;
//	T1_TCCR1B=TCCR1BTemp;
//	TCCR1BTemp&=0xf8;
//	TCCR1BTemp|=ClockSelectValue;
//
//}
//
//void __vector_9(void)
//{
//	static u32 Count=0;
//	Count++;
//	if(Count==NoOFOVFCount)
//	{
//		//Action
////		IMT_Timer1_App ();
//		//Preload
//		T1_TCNT1=PreloadValue;
//		//Clear Count
//		Count=0;
//	}
//}

//
//void T1_NormalModeInit()
//{
//	//select normal mode
//	ClearBit(T1_TCCR1A,T1_WGM10);
//	ClearBit(T1_TCCR1A,T1_WGM11);
//	ClearBit(T1_TCCR1B,T1_WGM12);
//	ClearBit(T1_TCCR1B,T1_WGM13);
//	//Enable Interrupt
//	SetBit(T1_TIMSK,T1_TOIE1);
//	//Update the Timer Register
//	T1_TCCR1A=PreloadValue;
//	//clock select
//	if(ClockSelectValue<=T1_Prescaller1024 && ClockSelectValue>=T1_Prescaller1)
//	{
//		T1_TCCR1B &=0b11111000; //0xf8
//		T1_TCCR1B|=ClockSelectValue;
//	}
//}
///***********************************************************************************/
//
//void __vector_9()
//{
//	static u32 Count = 0;
//	Count++;
//	if(Count==NoOFOVFCount)
//	{
//		//Action
//		//		ToggAPP();
//		//update Preload again
//		T1_TCCR1A=PreloadValue;
//		//Rest COunt
//		Count=0;
//	}
//}
///***************************************************************/
//void T1_CTC1AModeInit()
//{
//
//}
///***************************************************************/
//void __vector_7()
//{
//
//}
///*********************************************************/
//void T1_ICUModeInit()
//{
//	T1_TCCR1B |= (1<<6);
//	T1_TIMSK |= (1<<5);
//
//}
///*********************************************************/
//void T1_FastPWMMaxICRInit()
//{
//	T1_TCCR1A = (1<<7)|(1<<5)|(1<<1);
//	T1_TCCR1B = (1<<4)|(1<<3)|(1<<1);
//	T1_OCR1A = 1000UL;
//	T1_OCR1B = 1000UL;
//	T1_ICR1 = 20000UL;
//}
///******************************************************/
//void T1_ChangeAngle(u8 Angle , u8 Unit)
//{
//	u16 CompareValue = 0 ;
//	if (Unit == 1)
//	{
//		CompareValue = (u16) ( ((Angle*1000)/180)+1000 );
//		T1_OCR1A = CompareValue;
//	}
//	else if (Unit == 2)
//	{
//		CompareValue = (u16) ( ((Angle*1000)/180)+1000 );
//		T1_OCR1B = CompareValue;
//	}
//}
///**********************************************************/
//void T1_GetICUInfo(u8 *DutyCycle , u8 *PeriodicTime , u8 *OnTime)
//{
//	*PeriodicTime = T2;
//	*OnTime = T3 - T2 ;
//	*DutyCycle = ((*OnTime)/(*PeriodicTime))*100;
//
//}
///**********************************************************/
///* For ICU */
//void __vector_6 (void)
//{
//	static u8 count = 0 ;
//	count++;
//	if (count == 1)
//	{
//		//Clear Timer
//		T1_TCNT1 = 0 ;
//		T1_ICR1 = 0 ;
//	}
//	else if (count == 2)
//	{
//		T2 = T1_ICR1 ;
//		T1_TCCR1B &= ~(1<<6);
//	}
//	else if (count == 30)
//	{
//		T3 = T1_ICR1;
//		// Disable the ICU interrupt
//		T1_TIMSK &= ~(1<<5);
//	}
//}
//
///*************************************************/

void T1_Init(Timer1Modes Mode,ClockOptions Clock,CompareOutputMode State)
{
	switch(Mode)
	{
	case FastPWM_Top_OCR1A:
		SetBit(T1_TCCR1A ,T1_WGM10);
		SetBit(T1_TCCR1A ,T1_WGM11);
		SetBit(T1_TCCR1B ,T1_WGM12);
		SetBit(T1_TCCR1B ,T1_WGM13);
		break;
	case FastPWM_Top_ICR1:
		ClearBit(T1_TCCR1A ,T1_WGM10);
		SetBit(T1_TCCR1A ,T1_WGM11);
		SetBit(T1_TCCR1B ,T1_WGM12);
		SetBit(T1_TCCR1B ,T1_WGM13);
		break;
	case Normal:
		ClearBit(T1_TCCR1A ,T1_WGM10);
		ClearBit(T1_TCCR1A ,T1_WGM11);
		ClearBit(T1_TCCR1B ,T1_WGM12);
		ClearBit(T1_TCCR1B ,T1_WGM13);
		break;
	case CTC_Top_OCR1A:
		ClearBit(T1_TCCR1A ,T1_WGM10);
		ClearBit(T1_TCCR1A ,T1_WGM11);
		SetBit(T1_TCCR1B ,T1_WGM12);
		ClearBit(T1_TCCR1B ,T1_WGM13);
		break;
	case CTC_Top_ICR1:
		ClearBit(T1_TCCR1A ,T1_WGM10);
		ClearBit(T1_TCCR1A ,T1_WGM11);
		SetBit(T1_TCCR1B ,T1_WGM12);
		SetBit(T1_TCCR1B ,T1_WGM13);
		break;
	}
	switch(Clock)
	{
	case T1_Off:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Off;
		break;
	case T1_Prescaller1:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Prescaller1;
		break;
	case T1_Prescaller8:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Prescaller8;
		break;
	case T1_Prescaller64:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Prescaller64;
		break;
	case T1_Prescaller256:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Prescaller256;
		break;
	case T1_Prescaller1024:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_Prescaller1024;
		break;
	case T1_CounterFalling:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_CounterFalling;
		break;
	case T1_CounterRising:
		T1_TCCR1B &=0b11111000;
		T1_TCCR1B |=T1_CounterRising;
		break;
	}
	switch (State)
	{
	case disconnected:
		ClearBit(T1_TCCR1A,T1_COM1A0);
		ClearBit(T1_TCCR1A,T1_COM1A1);
		ClearBit(T1_TCCR1A,T1_COM1B0);
		ClearBit(T1_TCCR1A,T1_COM1B1);

		break;
	case noninverting:
		ClearBit(T1_TCCR1A,T1_COM1A0);
		SetBit(T1_TCCR1A,T1_COM1A1);
		ClearBit(T1_TCCR1A,T1_COM1B0);
		SetBit(T1_TCCR1A,T1_COM1B1);

		break;
	case inverting:
		SetBit(T1_TCCR1A,T1_COM1A0);
		SetBit(T1_TCCR1A,T1_COM1A1);
		SetBit(T1_TCCR1A,T1_COM1B0);
		SetBit(T1_TCCR1A,T1_COM1B1);

		break;

	}
}
void T1_OutputCompareInterruptEnable(ComperUnit Unit)
{
	switch(Unit)
	{
	case UnitA:
		SetBit(T1_TIMSK,T1_OCIE1A);
		break;
	case UnitB:
		SetBit(T1_TIMSK,T1_OCIE1B);
		break;
	case Both:
		SetBit(T1_TIMSK,T1_OCIE1A);
		SetBit(T1_TIMSK,T1_OCIE1B);
		break;
	}
}

void T1_OutputCompareInterruptDisable(ComperUnit Unit)
{
	switch(Unit)
	{
	case UnitA:
		ClearBit(T1_TIMSK,T1_OCIE1A);
		break;
	case UnitB:
		ClearBit(T1_TIMSK,T1_OCIE1B);
		break;
	case Both:
		ClearBit(T1_TIMSK,T1_OCIE1A);
		ClearBit(T1_TIMSK,T1_OCIE1B);
		break;
	}
}

void T1_Interrupt_Enable()
{
	SetBit(T1_TIMSK,T1_TOIE1);
}
void T1_Interrupt_Disable()
{
	ClearBit(T1_TIMSK,T1_TOIE1);
}
void T1_SetCallBack(void (*tmr1_ptf)(void))
{
	TMR1_InterriptOveFlow = tmr1_ptf;
}


void T1_ICU_SetCallBack(void (*(TMR1_ICU)) (void))
{
	TMR1_InterrupICU=TMR1_ICU;
}

void T1_SetCallBack_COMPA(void (*tmr1_ptf)(void))
{
	TMR1_InterriptComA=tmr1_ptf;
}
void T1_InputCpetureEdge(Edge_t _edge)
{
	if(FALLING_EDGE ==_edge)
	{
		ClearBit(T1_TCCR1B,T1_ICES1);
	}
	else if(RISING_EDGE ==_edge)
	{
		SetBit(T1_TCCR1B,T1_ICES1);
	}
}
void T1_ICU_InterruptEnable()
{
	SetBit(T1_TIMSK,T1_TICIE1);
}
void T1_ICU_InterruptDisnable()
{
	ClearBit(T1_TIMSK,T1_TICIE1);
}

static void Func_ICU()
{
	if(flag==0)
	{
		t1=T1_ICR1;
		T1_InputCpetureEdge(FALLING_EDGE);
		flag=1;

	}
	else if(flag==1)
	{
		t2=T1_ICR1;
		T1_InputCpetureEdge(RISING_EDGE);
		flag=2;
	}
	else if(flag==2)
	{
		t3=T1_ICR1;
		T1_ICU_InterruptDisnable();
		flag=3;
	}
}
/**********************ISR For TMR1 For OVF**************************/
void __vector_9(void)
{
	if(TMR1_InterriptOveFlow)
	{
		TMR1_InterriptOveFlow();
	}

}
/**********************ISR For TMR1 For ICU****************************/
void __vector_6(void)
{
	if(TMR1_InterrupICU)
	{
		TMR1_InterrupICU();
	}

}
/**********************ISR For TMR1 For COMPB**************************/
void __vector_8(void)
{
	if(TMR1_InterriptComB)
	{
		TMR1_InterriptComB();
	}
}
/**********************ISR For TMR1 For COMPA**************************/
void __vector_7(void)
{
	if(TMR1_InterriptComA)
	{
		TMR1_InterriptComA();
	}

}


