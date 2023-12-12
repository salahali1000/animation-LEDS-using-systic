/*
 * systic.h
 *
 *  Created on: Dec 12, 2023
 *      Author: salah
 */

#ifndef SYSTIC_H_
#define SYSTIC_H_

#include "STD_TYPES.h"
#include "stm32f103x6.h"

/* register definition */

typedef struct {

	vuint32 STK_CTRL ;
	vuint32 STK_LOAD ;
	vuint32 STK_VAL ;
	vuint32 STK_CALIB ;
}Systic_t;


#define Systic  				((Systic_t*)0xE000E010)

#define Processor_clock_AHB			1
#define AHB_pre_8					0


#define Enable_interrupt			1
#define Disable_interrupt			0

/* user options :  Processor_clock_AHB
 				           AHB_pre_8 */
#define Systic_ClkSource		AHB_pre_8
#define interrupt_state			Enable_interrupt

void Systic_VoidInit(void(*P_Func)(void)) ;
void Systic_Void_Write(uint32_t value) ;

#endif /* SYSTIC_H_ */
