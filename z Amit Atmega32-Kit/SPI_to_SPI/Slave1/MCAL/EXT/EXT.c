/*
 * EXT.c
 *
 * Created: 10/22/2023 1:59:01 PM
 *  Author: Ali
 */ 

#include "EXT_Interface.h"
#include "MCAL/DIO/DIO.h"
#include "std_macros.h"

void (*ptr_EXT1)(void) = NULL;
void (*ptr_EXT2)(void) = NULL;
void (*ptr_EXT3)(void) = NULL;

void EXT_init(uint8 EXT_num, uint8 EXT_sens){
		switch(EXT_num){
			case EXT0: 
			// Enable INT0 from GICR
			SETBIT(GICR, INT0); 
			// Button Direction (INPUT)
			DIO_voidSetPinDirection(portD, 2, INPUT);
			// Switch on Sens
			switch(EXT_sens){
				case LOW_Level: CLRBIT(MCUCR, ISC01); CLRBIT(MCUCR, ISC00); break;
				case CHANGE:    CLRBIT(MCUCR, ISC01); SETBIT(MCUCR, ISC00); break;
				case FALLING:   SETBIT(MCUCR, ISC01); CLRBIT(MCUCR, ISC00); break;
				case RISING:    SETBIT(MCUCR, ISC01); SETBIT(MCUCR, ISC00); break;
			}
			
			break;
			/***************************************************************************/
			case EXT1: 
			// Enable INT1 from GICR
			SETBIT(GICR, INT1); 
			// Button Direction (INPUT)
			DIO_voidSetPinDirection(portD, 3, INPUT);
			// Switch on Sens
			switch(EXT_sens){
				case LOW_Level: CLRBIT(MCUCR, ISC11); CLRBIT(MCUCR, ISC10); break;
				case CHANGE:    CLRBIT(MCUCR, ISC11); SETBIT(MCUCR, ISC10); break;
				case FALLING:   SETBIT(MCUCR, ISC11); CLRBIT(MCUCR, ISC10); break;
				case RISING:    SETBIT(MCUCR, ISC11); SETBIT(MCUCR, ISC10); break;
			}
			break;
			
			/***************************************************************************/
			case EXT2: 
			// Enable INT2 from GICR
			SETBIT(GICR, INT2);
			// Button Direction (INPUT)
			DIO_voidSetPinDirection(portB, 2, INPUT);
			// Switch on Sens
			switch(EXT_sens){
				case FALLING: CLRBIT(MCUCSR, ISC2); break;
				case RISING:  SETBIT(MCUCSR, ISC2); break;
			}
			break;
		}
		
}

void EXT_callback(void (*PTR)(void) ,uint8 EXT_num){
	switch(EXT_num){
		case EXT0: ptr_EXT1 = PTR; break;
		case EXT1: ptr_EXT2 = PTR; break;
		case EXT2: ptr_EXT3 = PTR; break;
	}
}

void __vector_1() __attribute__((signal));

void __vector_1(){
	ptr_EXT1();
}

void __vector_2() __attribute__((signal));

void __vector_2(){
	ptr_EXT2();
}

void __vector_3() __attribute__((signal));

void __vector_3(){
	ptr_EXT3();
}