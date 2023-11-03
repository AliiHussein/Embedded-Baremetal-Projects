/*
 * DIO.c
 *
 * Created: 10/20/2023 10:57:23 AM
 *  Author: Ali
 */ 

#include "DIO.h"

void DIO_voidSetPortDirection(uint8 copy_u8PortID, uint8 copy_u8PortDir){
	if(copy_u8PortDir == INPUT){ // input
		switch(copy_u8PortID){
			case portA: DDRA = 0; break;
			case portB: DDRB = 0; break;
			case portC: DDRC = 0; break;
			case portD: DDRD = 0; break;
		}
	}
	else{ // output
		switch(copy_u8PortID){
			case portA: DDRA = 0xFF; break;
			case portB: DDRB = 0xFF; break;
			case portC: DDRC = 0xFF; break;
			case portD: DDRD = 0xFF; break;
		}
	}
}
void DIO_voidSetPortValue(uint8 copy_u8PortID, uint8 copy_u8PortVal){
	if(copy_u8PortVal == LOW){ // LOW
		switch(copy_u8PortID){
			case portA: PORTA = 0; break;
			case portB: PORTB = 0; break;
			case portC: PORTC = 0; break;
			case portD: PORTD = 0; break;
		}
	}
	else{ // HIGH
		switch(copy_u8PortID){
			case portA: PORTA = 0xFF; break;
			case portB: PORTB = 0xFF; break;
			case portC: PORTC = 0xFF; break;
			case portD: PORTD = 0xFF; break;
		}
	}
}

void DIO_voidSetPinDirection(uint8 copy_u8PortID, uint8 copy_u8PinID, uint8 Copy_u8PinDir){
	
	if(Copy_u8PinDir == INPUT){ // input
		switch(copy_u8PortID){
			case portA: CLRBIT(DDRA, copy_u8PinID); break;
			case portB: CLRBIT(DDRB, copy_u8PinID); break;
			case portC: CLRBIT(DDRC, copy_u8PinID); break;
			case portD: CLRBIT(DDRD, copy_u8PinID); break;
		}
	}
	else{ // output
		switch(copy_u8PortID){
			case portA: SETBIT(DDRA, copy_u8PinID); break;
			case portB: SETBIT(DDRB, copy_u8PinID); break;
			case portC: SETBIT(DDRC, copy_u8PinID); break;
			case portD: SETBIT(DDRD, copy_u8PinID); break;
		}
	}
	
}
void DIO_voidSetPinValue(uint8 copy_u8PortID, uint8 copy_u8PinID, uint8 Copy_u8PinValue){
	if(Copy_u8PinValue == LOW){ // LOW
		switch(copy_u8PortID){
			case portA: CLRBIT(PORTA, copy_u8PinID); break;
			case portB: CLRBIT(PORTB, copy_u8PinID); break;
			case portC: CLRBIT(PORTC, copy_u8PinID); break;
			case portD: CLRBIT(PORTD, copy_u8PinID); break;
		}
	}
	else{ // HIGH
		switch(copy_u8PortID){
			case portA: SETBIT(PORTA, copy_u8PinID); break;
			case portB: SETBIT(PORTB, copy_u8PinID); break;
			case portC: SETBIT(PORTC, copy_u8PinID); break;
			case portD: SETBIT(PORTD, copy_u8PinID); break;
		}
	}
}

uint8 DIO_voidGetBitValue(uint8 copy_u8PortID, uint8 copy_u8PinID){
	uint8 value = 0;
	switch(copy_u8PortID){
		case portA: value = READBIT(PINA, copy_u8PinID); break;
		case portB: value = READBIT(PINB, copy_u8PinID); break;
		case portC: value = READBIT(PINC, copy_u8PinID); break;
		case portD: value = READBIT(PIND, copy_u8PinID); break;
	}
	return value;
}