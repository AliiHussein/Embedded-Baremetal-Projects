/*
 * Traffic_light.c
 *
 * Created: 4/30/2023 12:07:43 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "LCD.h"
#include "Timer0.h"

#define RED 0
#define YELLOW 1
#define GREEN 2

uint8_t lcd_counter = 255;
uint8_t state = GREEN;

int main(void)
{
    LCD_init();
	//Timer0_CTC_init(160); // Freq = 16Mhz, CC = 1/16 usec, Counter overflow = 160 count / 16 usec = 10 usec
	Timer0_normal_init(); // Freq = 16MHz, CC = 1/16 usec, Timer overflow = 256 count/ 16 usec = 16 usec
	
	
	// Set pins Mode to outputs
	SETBIT(DDRD, RED);      // PB0 output (RED LIGHT)
	SETBIT(DDRD, YELLOW);   // PB1 output (YELLOW LIGHT)
	SETBIT(DDRD, GREEN);     // PB2 output (GREEN LIGHT)
	
	SETBIT(PORTD, RED); 
	LCD_write_string("Timer: ");
	LCD_write_command(0xc0);
	LCD_write_string("STATE: ");
    while (1) 
    {
		while(lcd_counter != 255);
		if(state == RED){
			state = YELLOW;
			lcd_counter = 3;
			CLRBIT(PORTD, RED);
			SETBIT(PORTD, YELLOW);
			CLRBIT(PORTD, GREEN);
			LCD_write_command(0xc7);
			LCD_write_string("           ");
			LCD_write_command(0xc7);
			LCD_write_string("YELLOW");
		}
		else if(state == YELLOW){
			state = GREEN;
			CLRBIT(PORTD, RED);
			CLRBIT(PORTD, YELLOW);
			SETBIT(PORTD, GREEN);
			lcd_counter = 4;
			LCD_write_command(0xc7);
			LCD_write_string("           ");
			LCD_write_command(0xc7);
			LCD_write_string("GREEN");
		}
		else{
			state = RED;
			SETBIT(PORTD, RED);
			CLRBIT(PORTD, YELLOW);
			CLRBIT(PORTD, GREEN);
			lcd_counter = 5;
			LCD_write_command(0xc7);
			LCD_write_string("           ");
			LCD_write_command(0xc7);
			LCD_write_string("RED");
		}
		
    }
}

ISR(TIMER0_OVF_vect){
	static uint16_t count = 0;
	count++;
	if(count == 62500){
		LCD_write_command(0x87);
		LCD_write_number(lcd_counter--);
		count = 0;
	}
}