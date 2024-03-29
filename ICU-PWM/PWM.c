/*
 * PWM.c
 *
 * Created: 5/9/2023 3:23:09 PM
 *  Author: Ali
 */ 
#include "PWM.h"


void PWM0_OC0_init(void){
	SETBIT(DDRB,3);        // OC0 output
	TCNT0 = 0;             // set initial timer0 value to 0
	TCCR0 = (1<<FOC0) | (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00); // Fast PWM, Non-inverted, no prescaler
}
void PWM0_OC0_duty(uint8_t duty_cycle){
	if(duty_cycle > 100){
		duty_cycle = 100;
	}
	
	OCR0 = duty_cycle * 2.55;
}

/*****************************************************************************
* Function Name: PWM1_OC1A_init
* Purpose      : init timer1 pin oc1a PWM (fast freq, 10bit, non inverting, no prescaler)
* Parameters   : void
* Return value : void
*****************************************************************************/

void PWM1_OC1A_init(void){
	SETBIT(DDRD,5);        // OC1A output
	TCNT1 = 0;             // set initial timer1 value to 0
	SETBIT(TCCR1A,COM1A1); // set non inverting mode
	SETBIT(TCCR1A,WGM10);  // set FAST freq 10bit
	SETBIT(TCCR1A,WGM11);  // set FAST freq 10bit
	SETBIT(TCCR1B,WGM12);  // set FAST freq 10bit
	SETBIT(TCCR1B,CS10);   // No prescaler	
	
	
}

/*****************************************************************************
* Function Name: PWM1_OC1A_duty
* Purpose      : Determine the duty cycle of the PWM (0% to 100%)
* Parameters   : duty_cycle (The duty cycle of the pulse)
* Return value : void
*****************************************************************************/
void PWM1_OC1A_duty(uint8_t duty_cycle){
	
	if(duty_cycle > 100){
		duty_cycle = 100;
	}
	
	// duty_cycle = OCR/1023 * 100
	
	OCR1A = duty_cycle * 10.23;
}

void PWM2_OC2_init(void){
	SETBIT(DDRD, 7);        // OC2 output
	TCNT2 = 0;             // set initial timer2 value to 0
	TCCR2 = (1<<FOC2) | (1<<WGM21) | (1<<WGM20) | (1<<COM21) | (1<<CS20); // Fast PWM, Non-inverted, no prescaler
}

void PWM2_OC2_duty(uint8_t duty_cycle){
	if(duty_cycle > 100){
		duty_cycle = 100;
	}
	
	OCR2 = duty_cycle * 2.55;
}




