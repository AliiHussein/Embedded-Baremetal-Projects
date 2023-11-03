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

// MASTER
int main(void)
{
	LCD_init();
	LCD_write_string("Master");
	button_init(portD, 7);
	
	SPI_master_init();

	uint8 count = 0;
	while (1)
	{
		
		//if(button_read(portD,7) == 0){
			SPI_send(count);
			
			
			
			LCD_write_command(0xc0);
			LCD_write_string("   ");
			LCD_write_command(0xc0);
			LCD_write_number(count);
			count++;
			
			
			
			delay_ms(300);
		//}
		
		
		
	}
}
