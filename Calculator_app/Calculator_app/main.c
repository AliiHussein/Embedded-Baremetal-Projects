/*
 * Lcd_Keypad_app.c
 *
 * Created: 3/7/2023 2:17:48 PM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "LCD.h"
#include "KEYPAD.h"

uint8_t get_input_from_user(void);
int8_t get_calc_value(uint8_t a, uint8_t c, uint8_t b);

int main(void)
{
	LCD_init();
	KEYPAD_init();
	
	uint8_t first_digit, second_digit, opertor;
	
	int8_t pressed_key;
	
    while (1) 
    {
		
		int8_t key;
		
		key = get_input_from_user();
		if((key >= '0') && (key <= '9')){
			first_digit = key - '0';
		}
		
		key = get_input_from_user();
		if((key == '+') || (key == '-') || (key == '*') || (key == '/')){
			opertor = key;
		}
		
		key = get_input_from_user();
		if((key >= '0') && (key <= '9')){
			second_digit = key - '0';
		}

		
		key = get_input_from_user();
		if(key == '='){
			LCD_write_number(get_calc_value(first_digit,opertor,second_digit));
		}
		
		while(KEYPAD_read() != 'c');
		LCD_write_command(1);
		while(KEYPAD_read() != -1);
		
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

int8_t get_calc_value(uint8_t a, uint8_t c, uint8_t b){
	switch(c){
		case '+': return a+b;
		case '-': return a-b;
		case '/': return a/b;
		case '*': return a*b;
	}
}

