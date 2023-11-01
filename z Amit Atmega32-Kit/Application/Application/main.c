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


int main(void)
{
	LCD_init();
	SPI_master_init();
	
	LCD_write_string("Sent: ");
	
	LCD_write_command(0xc0);
	LCD_write_string("Rec: ");
	
	
	
	uint8 data_sent = 22;
	uint8 data_rec;
	while (1)
	{
		//data_rec = SPI_RX_TX(data_sent);
		SPI_send(data_sent);
		SPI_recieve(&data_rec);
		
		LCD_write_command(0x86);
		LCD_write_number(data_sent);
		LCD_write_command(0xc6);
		LCD_write_number(data_rec);
		
		data_sent++;
		
		delay_ms(500);
		
		
	}
}
