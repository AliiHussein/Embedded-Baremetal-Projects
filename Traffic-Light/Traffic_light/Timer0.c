/*
 * Timer0.c
 *
 * Created: 3/19/2023 1:54:57 PM
 *  Author: Ali
 */ 

#include "Timer0.h"

void Timer0_normal_init(void){
	TCCR0 = (1<<FOC0) | (1<<CS00); // no prescaler, normal mode
	SETBIT(TIMSK, TOIE0); // enable interrupt for normal mode
	SETBIT(SREG, 7); // Enable global interrupt
}

void Timer0_CTC_init(uint8_t max){
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<WGM01); // no prescaler, CTC mode
	OCR0 = max;
	SETBIT(TIMSK, OCIE0); // enable interrupt for CTC mode
	SETBIT(SREG, 7); // Enable global interrupt
}

void Timer0_freq_gen_init(uint8_t max){
	SETBIT(DDRB, 3); // Make PB3 (OC0) output digital 
	OCR0 = max;
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<COM00) | (1<<WGM01); // toggle OC0 pin on compare match, no prescaler, CTC mode	
}