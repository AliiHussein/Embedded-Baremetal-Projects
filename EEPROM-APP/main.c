/*
 * drivers.c
 *
 * Created: 8/19/2023 6:46:37 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "LCD.h"
#include "eeprom.h"

int main(void)
{	
	// Initializing LCD
	LCD_init();
	
	uint8_t x;
	
	if(eeprom_read(4) == 255){
		x = 0;
	}
	else{
		x = eeprom_read(4);
	}
	
	LCD_write_string("num = ");
    while (1) 
    {
		
		LCD_write_command(0x86);
		LCD_write_number(x++);
		eeprom_write(4, x);
		_delay_ms(1000);
		
		
		
		
    }
}

/*
ISR(TIMER0_COMP_vect){
	static uint16_t count = 0;
	count++;
	if(count == 40000){
		TOGBIT(PORTB, 0);
		count = 0;
	}
}
*/

/* 
	To get the count value:
	Timer_counts = (Required_time / timer_count_time) - 1
	count = Timer_counts / max_timer_counts

ISR(TIMER0_OVF_vect){
	static uint16_t count = 0;
	count++;
	if(count == 625){
		TOGBIT(PORTB, 0);
		count = 0;
	}
}
*/

