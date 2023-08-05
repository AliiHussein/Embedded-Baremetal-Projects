/*
 * Slave.c
 *
 * Created: 5/12/2023 11:46:43 PM
 * Author : Ali
 */ 

#include "SPI.h"
#include "LCD.h"


int main(void)
{
    SPI_init_slave();
	LCD_init();
	
	LCD_write_string("Hi, Im slave");
	_delay_ms(400);
	
	//set pins
	SETBIT(DDRD, 2);  // PD2 output
	SETBIT(DDRD, 3);  // PD3 output
	SETBIT(DDRD, 4);  // PD4 output
	SETBIT(DDRD, 5);  // PD5 output
	SETBIT(DDRD, 6);  // PD6 output
	SETBIT(DDRD, 7);  // PD7 output
	
	/*
	// set bits to high
	SETBIT(PORTD, 2);  // PD2 high
	SETBIT(PORTD, 3);  // PD3 high
	SETBIT(PORTD, 4);  // PD4 high
	SETBIT(PORTD, 5);  // PD5 high
	SETBIT(PORTD, 6);  // PD6 high
	SETBIT(PORTD, 7);  // PD7 high
	*/
	LCD_write_command(1);
	LCD_write_string("R1:0 R2:0 R3:0");
	LCD_write_command(0xc0);
	LCD_write_string("AC:0 TV:0");
	
    while (1) 
    {
		switch(SPI_read()){
			case 1: TOGBIT(PORTD, 4); LCD_write_command(0x83); LCD_write_char(READBIT(PORTD, 4) + '0'); break;
			case 2: TOGBIT(PORTD, 5); LCD_write_command(0x88); LCD_write_char(READBIT(PORTD, 5) + '0'); break;
			case 3: TOGBIT(PORTD, 6); LCD_write_command(0x8d); LCD_write_char(READBIT(PORTD, 6) + '0'); break;
			case 5: TOGBIT(PORTD, 3); LCD_write_command(0xc8); LCD_write_char(READBIT(PORTD, 3) + '0'); break;
			case 6: TOGBIT(PORTD, 2); LCD_write_command(0xc3); LCD_write_char(READBIT(PORTD, 2) + '0'); break;
		}
    }
}

