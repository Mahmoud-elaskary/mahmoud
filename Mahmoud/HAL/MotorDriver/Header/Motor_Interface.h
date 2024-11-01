/*
 * Motor.h
 *
 *  Created on: Oct 22, 2024
 *      Author: DELL
 */

#ifndef HAL_MOTORDRIVER_MOTOR_H_
#define HAL_MOTORDRIVER_MOTOR_H_
void MotorDriver_Init(void);

void MotorDriver_MoveForward(void);


void MotorDriver_MoveBackward(void);


void MotorDriver_MoveForwardRight(void);

void MotorDriver_MoveForwardLeft(void);


void MotorDriver_MoveBackwardRight(void);
void MotorDriver_MoveBackwardLeft(void);

void MotorDriver_Stop(void);


#endif /* HAL_MOTORDRIVER_MOTOR_H_ */
