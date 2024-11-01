/*
 * GIE_Interface.h
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */

#ifndef MCAL_GIE_HEADER_GIE_INTERFACE_H_
#define MCAL_GIE_HEADER_GIE_INTERFACE_H_

#include "../../../Common/Definition.h"
#include "../../../Common/BitMath.h"
#include "../../../Common/StdType.h"
#define SREG                  *((volatile u8*)0x5f)
#define GIE_Pin               7
void GIE_Enable();
void GIE_Disable();



#endif /* MCAL_GIE_HEADER_GIE_INTERFACE_H_ */
