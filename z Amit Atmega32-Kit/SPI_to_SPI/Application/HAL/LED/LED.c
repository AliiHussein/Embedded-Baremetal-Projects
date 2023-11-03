/*
 * LED.c
 *
 * Created: 10/20/2023 12:14:40 PM
 *  Author: Ali
 */ 

#include "LED.h"

void led_init(uint8 copy_u8PortID, uint8 copy_u8PinID){
	DIO_voidSetPinDirection(copy_u8PortID, copy_u8PinID, OUTPUT);
}

void led_on(uint8 copy_u8PortID, uint8 copy_u8PinID){
	DIO_voidSetPinValue(copy_u8PortID, copy_u8PinID, HIGH);
}

void led_off(uint8 copy_u8PortID, uint8 copy_u8PinID){
	DIO_voidSetPinValue(copy_u8PortID, copy_u8PinID, LOW);
}

void led_toggle(uint8 copy_u8PortID, uint8 copy_u8PinID){
	switch(copy_u8PortID){
		case portA: TOGBIT(PORTA, copy_u8PinID); break;
		case portB: TOGBIT(PORTB, copy_u8PinID); break;
		case portC: TOGBIT(PORTC, copy_u8PinID); break;
		case portD: TOGBIT(PORTD, copy_u8PinID); break;
	}
}