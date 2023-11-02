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
#include "MCAL/SPI/SPI_Interface.h"

// SLAVE 1
int main(void)
{
	LCD_init();
	
	LCD_write_string("SLave 1");
	
	
	
	SPI_slave_init();

	uint8 count;
	while (1)
	{
		
		SPI_recieve(&count);
		
		
		LCD_write_command(0xc0);
		LCD_write_string("   ");
		LCD_write_command(0xc0);
		LCD_write_number(count);
		
		SPI_send(count);
		
		
	}
}
