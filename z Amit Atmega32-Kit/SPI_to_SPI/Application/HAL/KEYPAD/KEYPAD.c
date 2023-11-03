/*
 * KEYPAD.c
 *
 * Created: 3/7/2023 3:09:19 PM
 *  Author: Ali
 */ 

#include "std_macros.h"
#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "HAL/Button/Button.h"

uint8 const keypad_matrix[] = {
	'1','2','3',
	'4','5','6',
	'7','8','9',
	'*','0','#',
};

/*****************************************************************************
* Function Name: KEYPAD_init
* Purpose      : initialize keypad 4x4
* Parameters   : void
* Return value : void
*****************************************************************************/
void KEYPAD_init(){
	INIT_KEYPAD_PINS();
	button_init(portC, 1);
	button_init(portC, 2);
	button_init(portC, 3);
}

/*****************************************************************************
* Function Name: KEYPAD_read
* Purpose      : Read pins of keypad
* Parameters   : void
* Return value : -1 if no press, value if pressed on of push buttons
*****************************************************************************/
int8 KEYPAD_read(){
	ROW1(0);ROW2(1);ROW3(1);ROW4(1);
	if(COL1() == 0) return keypad_matrix[0];
	if(COL2() == 0) return keypad_matrix[1];
	if(COL3() == 0) return keypad_matrix[2];
	delay_ms(5);
	
	ROW1(1);ROW2(0);ROW3(1);ROW4(1);
	if(COL1() == 0) return keypad_matrix[3];
	if(COL2() == 0) return keypad_matrix[4];
	if(COL3() == 0) return keypad_matrix[5];
	delay_ms(5);
	
	ROW1(1);ROW2(1);ROW3(0);ROW4(1);
	if(COL1() == 0) return keypad_matrix[6];
	if(COL2() == 0) return keypad_matrix[7];
	if(COL3() == 0) return keypad_matrix[8];
	delay_ms(5);
	
	ROW1(1);ROW2(1);ROW3(1);ROW4(0);
	if(COL1() == 0) return keypad_matrix[9];
	if(COL2() == 0) return keypad_matrix[10];
	if(COL3() == 0) return keypad_matrix[11];
	delay_ms(5);
	
	return -1;
}

uint8 get_input_from_user(){
	int8 key;
	
	do{
		key = KEYPAD_read();
	}while(key == -1);
	
	LCD_write_char(key);
	delay_ms(70);
	
	return key;
}

