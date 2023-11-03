/*
 * Button.c
 *
 * Created: 10/20/2023 2:20:56 PM
 *  Author: Ali
 */ 

#include "Button.h"

void button_init(uint8 copy_u8PortID, uint8 copy_u8PinID){
	DIO_voidSetPinDirection(copy_u8PortID, copy_u8PinID, INPUT);
	
	// Pullup
	switch(copy_u8PortID){
		case portA: SETBIT(PORTA, copy_u8PinID); break;
		case portB: SETBIT(PORTB, copy_u8PinID); break;
		case portC: SETBIT(PORTC, copy_u8PinID); break;
		case portD: SETBIT(PORTD, copy_u8PinID); break;
	}
}

uint8 button_read(uint8 copy_u8PortID, uint8 copy_u8PinID){
	return DIO_voidGetBitValue(copy_u8PortID, copy_u8PinID);
}

