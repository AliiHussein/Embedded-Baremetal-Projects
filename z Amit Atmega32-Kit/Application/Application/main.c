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
#include "MCAL/UART/UART_Interface.h"


int main(void)
{
	LCD_init();
	Uart_init();
	
	LCD_write_string("Hello Farah!");
	LCD_write_command(0xc0);
	
	
	uint8 data;
	while (1)
	{
		Uart_Receive(&data);
		
		LCD_write_char(data);
		
		if(data == 127){
			LCD_write_command(0x10);
			LCD_write_command(0x10);
			LCD_write_string("  ");
			LCD_write_command(0x10);
			LCD_write_command(0x10);
			/*LCD_write_command(1);*/
		}
		
	}

	

}
