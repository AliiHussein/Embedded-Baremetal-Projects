/*
 * drivers.c
 *
 * Created: 8/19/2023 6:46:37 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "LCD.h"

int main(void)
{	
	// Initializing LCD
	LCD_init();
	
	// Enable Interrupt or cli();
	CLRBIT(SREG, 7);
		
	// Initializing PD2 (INT0 pin) as pullup input
	CLRBIT(DDRD, 2);
	SETBIT(PORTD, 2);
	// Initializing PD3 (INT1 pin) as pullup input
	CLRBIT(DDRD, 3);
	SETBIT(PORTD, 3);
	// Initializing PB2 (INT2 pin) as pullup input
	CLRBIT(DDRB, 2);
	SETBIT(PORTB, 2);
	
	// use MCUCR to choose pin mode for INT0 & INT1 (falling edge)
	// InNT2 is always edge triggered
	MCUCR |= 0b00001010;
	
	//Enable INT0 using GCIR
	GICR |= 0b11100000;
	
	//Enable global interrupt or sei();
	SETBIT(SREG, 7);
	
	
    while (1) 
    {
		
    }
}

ISR(INT0_vect)
{
	LCD_write_command(0x80);
	LCD_write_string("INT0");
}

ISR(INT1_vect)
{
	LCD_write_command(0x80);
	LCD_write_string("INT1");
}

ISR(INT2_vect)
{
	LCD_write_command(0x80);
	LCD_write_string("INT2");
}

