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

uint8 Ain[8] = {
	0b00000,
	0b00000,
	0b01111,
	0b01000,
	0b01000,
	0b11111,
	0b00000,
	0b00000
};

uint8 lam[8] = {  
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b11111,
	0b00000,
	0b00000
};

uint8 ya2[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b10110,
	0b10111,
	0b11100,
	0b01100
};

uint8 haa2[8] = { 
	0b00000,
	0b00000,
	0b11100,
	0b00110,
	0b00011,
	0b11111,
	0b00000,
	0b00000
};

uint8 seen[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b10101,
	0b11111,
	0b00000,
	0b00000
};

uint8 yaa2_nos[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00010,
	0b11111,
	0b00000,
	0b10100
};

uint8 noon[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b01000,
	0b00000,
	0b10011,
	0b10010,
	0b11110
};

int main(void)
{
	LCD_init();
	LCD_write_string("Ali Hussein");
	
	LCD_write_command(0xc0);
	LCD_write_command(64);
	// Ain=0, lam=1, ya2=2, haa2=3, seen=4, yaa2_nos=5, noon=6
	LCD_create_char(0,Ain);
	LCD_create_char(1,lam);
	LCD_create_char(2,ya2);
	LCD_create_char(3,haa2);
	LCD_create_char(4,seen);
	LCD_create_char(5,yaa2_nos);
	LCD_create_char(6,noon);
	
	LCD_write_command(0xcf); // a=10 b=11 c=12 d=12 e=14 f=15 g=16
	LCD_write_char(0);
	LCD_write_command(0xce);
	LCD_write_char(1);
	LCD_write_command(0xcd);
	LCD_write_char(2);
	LCD_write_command(0xcc);
	LCD_write_char(32);
	LCD_write_command(0xcb);
	LCD_write_char(3);
	LCD_write_command(0xca);
	LCD_write_char(4);
	LCD_write_command(0xc9);
	LCD_write_char(5);
	LCD_write_command(0xc8);
	LCD_write_char(6);
	LCD_write_command(0xc7);
	
	
	while (1)
	{
	}
}
