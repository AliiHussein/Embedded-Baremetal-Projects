/*
 * Timer0.c
 *
 * Created: 3/19/2023 1:54:57 PM
 *  Author: Ali
 */ 

#include "Timer0.h"

void Timer0_normal_init(void){
	CLRBIT(SREG, 7); // Disable global interrupt
	TCNT0 = 0; // initial value of timer is zero
	TCCR0 = (1<<FOC0) | (1<<CS00); // no prescaler, normal mode
	SETBIT(TIMSK, TOIE0); // enable interrupt for normal mode
	SETBIT(SREG, 7); // Enable global interrupt
}

void Timer0_CTC_init(uint8_t max){
	CLRBIT(SREG, 7); // Disable global interrupt
	TCNT0 = 0; // initial value of timer is zero
	OCR0 = max; //set the compare value
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<WGM01); // no prescaler, CTC mode
	SETBIT(TIMSK, OCIE0); // enable interrupt for CTC mode
	SETBIT(SREG, 7); // Enable global interrupt
}

void Timer0_freq_gen_init(uint8_t max){
	TCNT0 = 0; // initial value of timer is zero
	OCR0 = max; //set the compare value
	SETBIT(DDRB, 3); // Make PB3 (OC0) output digital 
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<COM00) | (1<<WGM01); // toggle OC0 pin on compare match, no prescaler, CTC mode	
}