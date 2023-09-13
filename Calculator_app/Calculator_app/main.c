/*
 * Lcd_Keypad_app.c
 *
 * Created: 3/7/2023 2:17:48 PM
 * Author : Ali
 */ 

// Libraries
#include "std_macros.h"
#include "LCD.h"
#include "KEYPAD.h"
#include <math.h>

// functions prototype
uint8_t get_input_from_user(void);
int32_t get_calc_value(uint32_t a, uint8_t c, uint32_t b);

#define max_digits 3
#define DEBUG1 1

int main(void)
{
	// Initializations
	LCD_init();
	KEYPAD_init();
	
	uint8_t first_arr[max_digits], second_arr[max_digits];
	uint8_t size1 = 0, size2 = 0, operator = 0;
	uint32_t first_num = 0, second_num =0;
		
    while (1) 
    {
		
		int8_t key;
		
		for(int i = 0; i < max_digits; i++){
			key = get_input_from_user();
			if((key >= '0') && (key <= '9')){
				first_arr[i]= key - '0';
				size1++;
			}
			else{
				break;
			}
		}
		
		LCD_write_command(1);
		// calculate the first number
		for(int i = 0 ; i < size1; i++){
			first_num += first_arr[size1-1-i] * pow(10, i);
			LCD_write_number(first_num);
			LCD_write_string("->");

		}

		
		if(size1 == max_digits){
			key = get_input_from_user();
		}
		
		// Operator
		if((key == '+') || (key == '-') || (key == '*') || (key == '/')){
			operator = key;
		}
		
		for(int i = 0; i < max_digits; i++){
			key = get_input_from_user();
			if((key >= '0') && (key <= '9')){
				second_arr[i]= key - '0';
				size2++;
			}
			else{
				break;
			}
		}
		
		// calculate the second number
		for(int i = 0 ; i < size2; i++){
			second_num += second_arr[size2-1-i] * pow(10, i) ;
		}
		
		
		if(size2 == max_digits){
			key = get_input_from_user();
		}

		if(key == '='){
			LCD_write_number(get_calc_value(first_num,operator,second_num));
		}
		
		// reset variables
		size1 = 0;
		first_num = 0;
		size2 = 0;
		second_num = 0;
		
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

int32_t get_calc_value(uint32_t a, uint8_t c, uint32_t b){
	switch(c){
		case '+': return a+b;
		case '-': return a-b;
		case '/': return a/b;
		case '*': return a*b;
	}
	return -1;
}

