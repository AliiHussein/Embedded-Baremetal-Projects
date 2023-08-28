/*
 * ICU.c
 *
 * Created: 8/24/2023 10:42:22 AM
 *  Author: Ali
 */ 

#include "ICU.h"

uint16_t timer1_init_input_capture_usec(void){
	uint16_t t1,t2;
	TCNT1 = 0;						  // initial value of timer is zero
	TCCR1A = 0;						  // To ensure time is not on any other mode
	TCCR1B |= 1<<CS10 | 1<<ICES1;     // detect rising edge
	TIFR |= 1<<ICF1;				  // clear ICU flag bit
	
	while(READBIT(TIFR,ICF1) == 0 );  // wait until first rising edge detect
	t1 = ICR1;                        // store value of first rising edge
	CLRBIT(TCCR1B, ICES1);          // uncomment to get the first pulse
	TIFR |= 1<<ICF1;                  // clear IC flag
	
	while(READBIT(TIFR,ICF1) == 0);   // wait until 2nd rising edge detect
	t2 = ICR1;                        // store value of second rising edge
	TIFR |= 1<<ICF1;                  // clear IC flag
	
	TCCR1B = 0;                       // stop timer 1
	ICR1 = 0;
	TCNT1 = 0;
	return (t2 - t1)/16.0;
}
