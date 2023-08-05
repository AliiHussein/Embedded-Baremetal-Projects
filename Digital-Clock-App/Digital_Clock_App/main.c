/*
 * Digital_Clock_App.c
 *
 * Created: 5/4/2023 7:17:19 PM
 * Author : Ali
 */ 

#include "Timer0.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "seven_seg.h"

uint8_t get_input_from_user(void);

// Global Variables
uint8_t seconds = 0;
uint8_t minutes = 0;
uint8_t hours = 0;

int main(void)
{
	LCD_init();	
	seven_seg_init();
	KEYPAD_init();
	Timer0_normal_init(); // Freq = 16MHz, CC = 1/16 usec, Timer overflow = 256 count/ 16 usec = 16 usec
	
    while (1) 
    {
		LCD_write_command(1);
		LCD_write_string("Press 1 to");
		LCD_write_command(0xc0);
		LCD_write_string("set clock");
		LCD_write_command(0x0E);
		
		do 
		{
			seven_seg_write(seconds/10, 5);
			seven_seg_write(seconds%10, 6);
			seven_seg_write(minutes/10, 3);
			seven_seg_write(minutes%10, 4);
			seven_seg_write(hours/10, 1);
			seven_seg_write(hours%10, 2);
			
		} while (KEYPAD_read() != '1');
		while(KEYPAD_read() != -1);
		
		// Adjusting hours
		LCD_write_command(1);
		LCD_write_string("Hours: ");
		hours = (get_input_from_user() -'0') * 10;
		hours += (get_input_from_user() - '0');
		
		// Adjusting minutes
		LCD_write_command(1);
		LCD_write_string("Minutes: ");
		minutes = (get_input_from_user() -'0') * 10;
		minutes += (get_input_from_user() - '0');
		
		// Adjusting minutes
		LCD_write_command(1);
		LCD_write_string("Seconds: ");
		seconds = (get_input_from_user() -'0') * 10;
		seconds += (get_input_from_user() - '0');
		
    }
}

uint8_t get_input_from_user(){
	int8_t key;
	
	do{
		key = KEYPAD_read();
	}while(key == -1);
	
	LCD_write_char(key);
	while(KEYPAD_read() != -1);
	
	return key;
}

ISR(TIMER0_OVF_vect){
	static uint16_t count = 0;
	count++;
	if(count == 62500){
		count = 0;
		seconds++;
		if(seconds == 60){
			seconds = 0;
			minutes++;
			if(minutes == 60){
				minutes = 0;
				hours++;
				if(hours == 24){
					hours = 0;
				}
			}
		}
	}
}



