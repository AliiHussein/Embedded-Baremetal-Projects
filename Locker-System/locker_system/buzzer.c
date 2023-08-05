/*
 * buzzer.c
 *
 * Created: 3/11/2023 10:50:56 PM
 *  Author: Ali
 */ 

#include "buzzer.h"

#define INIT_BUZZER_PIN() DDRD |= 0b10000000;
#define BUZZER_PIN(x) if(x == 1) SETBIT(PORTD, 7); else CLRBIT(PORTD, 7);

void buzzer_init(){
	INIT_BUZZER_PIN();	
}
void buzzer_button_pressed(){
	BUZZER_PIN(1);
	_delay_ms(100);
	BUZZER_PIN(0);
	
}
void buzzer_change_password(){
	BUZZER_PIN(1);
	_delay_ms(3000);
	BUZZER_PIN(0);
}