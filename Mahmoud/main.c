/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: DELL
 */
#define  F_CPU  8000000UL
#include <util/delay.h>
#include "MCAL/DIO/Header/DIO_Interface.h"
#include "HAL/Servo/Header/Servo_Interface.h"
#include "MCAL/Timer1/Header/T1_Interface.h"
#include "MCAL/GIE/Header/GIE_Interface.h"
#include "HAL/Ultrasonic/Header/Ultrasonic_Interface.h"
#include "HAL/MotorDriver/Header/Motor_Interface.h"
#include "HAL/IR_Sensor/Header/IR_Interface.h"

#define STOP_DISTANCE     30
#define  WHITE	  0
#define  BLACK	  1
u8 dis;
u8 dis_right=0;
u8 dis_left=0;

int main()
{
	GIE_Enable();
	IR_Init();
	MotorDriver_Init();
	Ultrasonic_Init();


	while(1)
	{

		if (IR_Read_LeftIR()==WHITE && IR_Read_RightIR()==WHITE)
		{
			dis=UltrasonicReadDistance();
			if(dis > STOP_DISTANCE)
			{
				MotorDriver_MoveForward();
				//_delay_ms(1500);
			}
			else if(dis < STOP_DISTANCE)
			{
				MotorDriver_Stop();
				_delay_ms(2000);
				dis=UltrasonicReadDistance();
				if(dis > STOP_DISTANCE)
				{
					MotorDriver_MoveForward();

				}
				else
				{
					Servo_SetAngle(0);
					_delay_ms(300);
					dis_right=UltrasonicReadDistance();
					_delay_ms(300);
					Servo_SetAngle(180);
					_delay_ms(300);
					dis_left=UltrasonicReadDistance();
					_delay_ms(300);
					Servo_SetAngle(90);
					if(dis_right>dis_left && dis_right>STOP_DISTANCE  )
					{
						MotorDriver_MoveForwardRight();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardLeft();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardLeft();
						_delay_ms(400);
					}
					else if(dis_right<dis_left && dis_left >STOP_DISTANCE  )
					{
						MotorDriver_MoveForwardLeft();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardRight();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardRight();
						_delay_ms(400);

					}
					else if(dis_right==dis_left && dis_left >STOP_DISTANCE /*&& IR_Read_LeftIR()==BLACK && IR_Read_RightIR()==WHITE*/ )
					{
						MotorDriver_MoveForwardRight();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardLeft();
						_delay_ms(500);
						MotorDriver_MoveForward();
						_delay_ms(600);
						MotorDriver_MoveForwardLeft();
						_delay_ms(400);
					}
					else if(dis_right==dis_left && dis_left <STOP_DISTANCE)
					{

						MotorDriver_Stop();
						_delay_ms(500);
					}

				}


			}
		}
		else if (IR_Read_LeftIR()==BLACK && IR_Read_RightIR()==WHITE)
		{
			MotorDriver_MoveForwardLeft();

		}
		else if (IR_Read_LeftIR()==WHITE && IR_Read_RightIR()==BLACK)
		{
			MotorDriver_MoveForwardRight();

		}

		else if (IR_Read_LeftIR()==BLACK && IR_Read_RightIR()==BLACK)
		{
			MotorDriver_Stop();
		}
		_delay_ms(10);
	}
}






// int main()
//{
//
//
//	DIO_SelectDirectionForGroup(Group_A,0xff);
//	while(1)
//	{
//		DIO_SelectOutputStateForPin(Group_A,Pin0,High);
//		DIO_SelectOutputStateForPin(Group_A,Pin1,Low);
//		_delay_ms(3000);
//		DIO_SelectOutputStateForPin(Group_A,Pin0,Low);
//		DIO_SelectOutputStateForPin(Group_A,Pin1,High);
//		_delay_ms(3000);
//		DIO_SelectOutputStateForPin(Group_A,Pin0,Low);
//		DIO_SelectOutputStateForPin(Group_A,Pin1,Low);
//		_delay_ms(3000);
//	}
//	return 0;
//}




















