/*
 * EXTI_Register.h
 *
 *  Created on: Aug 15, 2024
 *      Author: DELL
 */

#ifndef MCAL_EXTI_HEADER_EXTI_REGISTER_H_
#define MCAL_EXTI_HEADER_EXTI_REGISTER_H_

#define EXTI_MCUCR    *((volatile u8*)0x55)
#define EXTI_MCUCSR   *((volatile u8*)0x54)
#define EXTI_GICR     *((volatile u8*)0x5B)
#define EXTI_GIFR     *((volatile u8*)0x5A)




#endif /* MCAL_EXTI_HEADER_EXTI_REGISTER_H_ */
