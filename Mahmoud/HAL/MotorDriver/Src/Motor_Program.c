/*
 * Motor.c
 *
 *  Created on: Oct 22, 2024
 *      Author: DELL
 */




#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Motor_Interface.h"


void MotorDriver_Init(void)
{
	// set directions and select pins for motor
	DIO_SelectDirectionForPin(Group_A, Pin0, Output);
	DIO_SelectDirectionForPin(Group_A, Pin1, Output);
	DIO_SelectDirectionForPin(Group_A, Pin2, Output);
	DIO_SelectDirectionForPin(Group_A, Pin3, Output);
}

void MotorDriver_MoveForward(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, High);
	DIO_SelectOutputStateForPin(Group_A, Pin1, Low);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, High);
	DIO_SelectOutputStateForPin(Group_A, Pin3, Low);

}


void MotorDriver_MoveBackward(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin1, High);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin3, High);

}


void MotorDriver_MoveForwardRight(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin1, Low);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, High);
	DIO_SelectOutputStateForPin(Group_A, Pin3, Low);


}

void MotorDriver_MoveForwardLeft(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, High);
	DIO_SelectOutputStateForPin(Group_A, Pin1, Low);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin3, Low);


}

void MotorDriver_MoveBackwardRight(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin1, High);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin3, Low);

}
void MotorDriver_MoveBackwardLeft(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin1, Low);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin3, High);

}


void MotorDriver_Stop(void)
{
	// for motor in right side
	DIO_SelectOutputStateForPin(Group_A, Pin0, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin1, Low);

	// for motor in left side
	DIO_SelectOutputStateForPin(Group_A, Pin2, Low);
	DIO_SelectOutputStateForPin(Group_A, Pin3, Low);

		/*
		 * or
		 * 	// for motor in write side
		DIO_WritePin('A',0,1);
		DIO_WritePin('A',1,1);


		// for motor in write side
		DIO_WritePin('A',2,1);
		DIO_WritePin('A',3,1);
		 * */
}

