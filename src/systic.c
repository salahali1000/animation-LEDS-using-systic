/*
 * systic.c
 *
 *  Created on: Dec 12, 2023
 *      Author: salah
 */
#include "systic.h"
void(*P_Func_Global)(void) ;
void Systic_VoidInit(void(*P_Func)(void))
{
	uint32_t Systic_Config = 0 ;

	/*configure clock source */
	Systic_Config |= Systic_ClkSource<<2 ;

	/*enable interrupt*/
	Systic_Config |= interrupt_state<<1 ;

	/*enable Systic*/
	Systic_Config |= 1 ;

	/*assign configuration variable in the register */
	Systic->STK_CTRL = Systic_Config ;
	P_Func_Global = P_Func ;
}

void Systic_Void_Write(uint32_t value)
{
	Systic->STK_LOAD = value ;
}

void SysTick_Handler(void)
{
	P_Func_Global() ;
}

