/*
 * DIO_Register.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_DIO_HEADER_DIO_REGISTER_H_
#define MCAL_DIO_HEADER_DIO_REGISTER_H_


#define DIO_DDRA    *((volatile unsigned char*)0x3A)
#define DIO_DDRB    *((volatile unsigned char*)0x37)
#define DIO_DDRC    *((volatile unsigned char*)0x34)
#define DIO_DDRD    *((volatile unsigned char*)0x31)

#define DIO_PORTA    *((volatile unsigned char*)0x3B)
#define DIO_PORTB    *((volatile unsigned char*)0x38)
#define DIO_PORTC    *((volatile unsigned char*)0x35)
#define DIO_PORTD    *((volatile unsigned char*)0x32)


#define DIO_PINA     *((volatile unsigned char*)0x39)
#define DIO_PINB     *((volatile unsigned char*)0x36)
#define DIO_PINC     *((volatile unsigned char*)0x33)
#define DIO_PIND     *((volatile unsigned char*)0x30)

#endif /* MCAL_DIO_HEADER_DIO_REGISTER_H_ */
