/*
 * Buzzer.c
 *
 * Created: 10/24/2023 6:39:09 PM
 *  Author: Ali
 */ 

#include "Bit_math.h"
#include "std_types.h"

#include "Buzzer_interface.h"
#include "Buzzer_CFG.h"

void Buzzer_init(){
	DIO_voidSetPinDirection(Buzzer_PORT, Buzzer_PIN, OUTPUT);
}

void Buzzer_on(){
	DIO_voidSetPinValue(Buzzer_PORT, Buzzer_PIN, HIGH);
}

void Buzzer_off(){
	DIO_voidSetPinValue(Buzzer_PORT, Buzzer_PIN, LOW);
}

void Buzzer_toggle(){
	switch(Buzzer_PORT){
		case portA: TOGBIT(PORTA, Buzzer_PIN); break;
		case portB: TOGBIT(PORTB, Buzzer_PIN); break;
		case portC: TOGBIT(PORTC, Buzzer_PIN); break;
		case portD: TOGBIT(PORTD, Buzzer_PIN); break;
	}
}