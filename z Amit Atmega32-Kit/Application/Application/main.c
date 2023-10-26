/*
 * Application.c
 *
 * Created: 10/23/2023 6:34:02 PM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED/LED.h"
#include "HAL/Button/Button.h"
#include "HAL/LCD/LCD.h"
#include "HAL/SevenSeg/SevenSeg.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/Buzzer/Buzzer_interface.h"

#include "MCAL/DIO/DIO.h"
#include "MCAL/EXT/EXT_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/DELAY/DELAY.h"


int main(void)
{
	LCD_init();
	KEYPAD_init();
	
	LCD_write_string("ALI");
	LCD_write_command(0xc0);
	LCD_write_string("KP: ");
	int8 key;
	uint8 count = 0;
	while(1){
		LCD_write_command(0xc4);
		do{
			key = KEYPAD_read();
		}
		while(key == -1);
		
		LCD_write_char(key);
		LCD_write_command(0x85);
		LCD_write_number(count);
		delay_ms(200);
		count++;
		
		
		
	}

	

}
