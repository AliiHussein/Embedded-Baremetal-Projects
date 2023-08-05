/*
 * locker_system.c
 *
 * Created: 3/11/2023 10:24:54 PM
 * Author : Ali
 */ 

#include "LCD.h"
#include "eeprom.h"
#include "buzzer.h"
#include "KEYPAD.h"

int main(void)
{
	LCD_init();
	KEYPAD_init();
	buzzer_init();
	
	uint8_t locker_state = 1; // 1 means open, 0 means closed
	uint8_t correct = 1;
	uint8_t password[4];
	uint8_t input[4];
	uint8_t i = 0;
	
	for(i = 0; i < 4; i++){
		password[i] = eeprom_read(20+i);
	}

    while (1) 
    {
		// Locker in open mode
		if(locker_state){
			
			LCD_write_command(1);
			LCD_write_string((uint8_t *)"LOCKER OPEN");
			// check if I want to change the password or lock the locker
			while((KEYPAD_read() != '*') && (KEYPAD_read() != '/') && (KEYPAD_read() != '0') );
			// check if lock
			if(KEYPAD_read() == '*'){
				locker_state = 0;
			}
			// change password
			else if(KEYPAD_read() == '/'){
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"Set New PW: ");
				buzzer_change_password();
				for(i = 0; i < 4; i++){
					while(KEYPAD_read() == -1);
					LCD_write_char(KEYPAD_read());
					buzzer_button_pressed();
					input[i] = KEYPAD_read() - '0';
					while(KEYPAD_read() != -1);
				}
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"Press / to save changes");
				while(KEYPAD_read() == -1);
				if(KEYPAD_read() == '/'){
					for(i = 0; i < 4; i++){
						password[i] = input[i];
						eeprom_write(20+i, input[i]);
					}
				}
				while(KEYPAD_read() != -1);
			}
			// Reset password
			else{
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"Reset pw: ");
				for(i = 0; i < 6; i++){
					while(KEYPAD_read() != '0');
					LCD_write_char(KEYPAD_read());
					buzzer_button_pressed();
					while(KEYPAD_read() != -1);
				}
				for(i = 0; i < 4; i++){
					password[i] = 0;
					eeprom_write(20+i, 0);
				}
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"PW is reset");
			}	
			while(KEYPAD_read() != -1);		
		}
		// Locker in lock mode
		else{
			LCD_write_command(1);
			LCD_write_string((uint8_t *)"LOCKER CLOSED");
			
			LCD_write_command(0xc0);
			LCD_write_string((uint8_t *)"pw: ");
			
			// Take the inputs
			for(i = 0; i < 4; i++){
				while(KEYPAD_read() == -1);
				LCD_write_char('*');
				buzzer_button_pressed();
				input[i] = KEYPAD_read() - '0';
				while(KEYPAD_read() != -1);
				
			}
			
			// check if input matches the password
			for(i = 0; i < 4; i++){
				if(input[i] == password[i]){
					correct = 1;
				}
				else{
					correct = 0;
				}
			}
			if(correct == 1){
				locker_state = 1;
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"correct password");
				_delay_ms(500);
				LCD_write_command(1);
			}
			else{
				LCD_write_command(1);
				LCD_write_string((uint8_t *)"Wrong password");
				_delay_ms(500);
				LCD_write_command(1);
			}
		}
    }
}