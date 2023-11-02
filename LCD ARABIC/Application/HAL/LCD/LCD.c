/*
 * LCD.c
 *
 * Created: 3/7/2023 2:24:02 PM
 *  Author: Ali
 */ 

#include "LCD.h"
#include "LCD_cfg.h"
#include "std_macros.h"

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : initialize LCD to work in 4-bit mode - clear lcd - cursor off
* Parameters   : void
* Return value : void

*****************************************************************************/
void LCD_init(void){
	INIT_LCD_PINS();
	delay_ms(20);			/* LCD Power ON delay always >15ms */
	
	LCD_write_command(0x02);		      /* send for 4 bit initialization of LCD  */
	LCD_write_command(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_write_command(0x0c);              /* Display on cursor off*/
	LCD_write_command(0x06);              /* Increment cursor (shift cursor to right)*/
	LCD_write_command(0x01);              /* Clear display screen*/
	delay_ms(30);
	// Always write on LCD
	//SETBIT(DDRB, 2);
	//CLRBIT(PORTB, 2);
}

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Write a specific Ascii char (data) to lcd (valid only with 4-bit mode)
* Parameters   : data  (data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_char(uint8 data){
	LCD_RS(1);
	LCD_D4(READBIT(data, 4));
	LCD_D5(READBIT(data, 5));
	LCD_D6(READBIT(data, 6));
	LCD_D7(READBIT(data, 7));
	
	LCD_EN(1);
	delay_ms(1);
	LCD_EN(0);
	delay_ms(1);
	
	LCD_D4(READBIT(data, 0));
	LCD_D5(READBIT(data, 1));
	LCD_D6(READBIT(data, 2));
	LCD_D7(READBIT(data, 3));
	
	LCD_EN(1);
	delay_ms(1);
	LCD_EN(0);
	delay_ms(1);
	
}

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send a specific command (cmd) to lcd (valid only with 4-bit mode)
* Parameters   : cmd  (command to be done by lcd)
* Return value : void
*****************************************************************************/
void LCD_write_command(uint8 cmd){
	LCD_RS(0);
	LCD_D4(READBIT(cmd, 4));
	LCD_D5(READBIT(cmd, 5));
	LCD_D6(READBIT(cmd, 6));
	LCD_D7(READBIT(cmd, 7));

	LCD_EN(1);
	delay_ms(1);
	LCD_EN(0);
	delay_ms(1);
	
	LCD_D4(READBIT(cmd, 0));
	LCD_D5(READBIT(cmd, 1));
	LCD_D6(READBIT(cmd, 2));
	LCD_D7(READBIT(cmd, 3));
	
	LCD_EN(1);
	delay_ms(1);
	LCD_EN(0);
	delay_ms(1);
}

/*****************************************************************************
* Function Name: LCD_write_num
* Purpose      : Write a specific number (num) on lcd (valid only with 4-bit mode)
* Parameters   : num  (num to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_number(int32 num){
	int8 i = 0;
	uint8 num_arr[10];
	uint8 neg_flag = 0;
	
	if(num < 0){
		num *= -1;
		neg_flag = 1;
	}
	
	if(num == 0) {
		LCD_write_char('0');
		return;
	}
	
	for(i = 0; num != 0 ;i++){ // 6,5,2,1
		num_arr[i] = num % 10 + '0';
		num /= 10;
	}
	i--;
	if(neg_flag == 1){
		LCD_write_char('-');
	}
	while (i >= 0){
		LCD_write_char(num_arr[i]);
		i--;
	}
}

/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : Write a string (*txt) to lcd (valid only with 4-bit mode)
*                (assume the end char of string is NULL (Ascii:'\0' - decimal:0 ))
* Parameters   : *txt  (array of char to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_string(uint8 * str){
	uint8 i;
	
	for(i = 0; str[i] != '\0'; i++){
		LCD_write_char(str[i]);
	}
	
}

void clear_screen(void){
	LCD_write_command(0x01);
}

void LCD_create_char(uint8 location,uint8 * new_char){
	for(int i = 0; i < 8; i++){
		LCD_write_char(new_char[i]);
	}
}