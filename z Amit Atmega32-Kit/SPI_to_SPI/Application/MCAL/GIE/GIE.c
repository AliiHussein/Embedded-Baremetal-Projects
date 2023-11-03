/*
 * GIE.c
 *
 * Created: 10/22/2023 1:52:39 PM
 *  Author: Ali
 */ 

#include "GIE_Interface.h"
#include "std_macros.h"

void GIE_Enable(void){
	SETBIT(SREG, I_BIT);
}

void GIE_Disable(void){
	CLRBIT(SREG, I_BIT);
}