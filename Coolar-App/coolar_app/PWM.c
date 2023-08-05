/*
 * PWM.c
 *
 * Created: 12/2/2022 11:24:18 AM
 *  Author: safifi
 */ 
#include "PWM.h"
/*****************************************************************************
* Function Name: PWM1_OC1A_init
* Purpose      : init timer1 pin oc1a PWM (fast freq, 10bit, non inverting, no prescaler)
* Parameters   : void
* Return value : void
*****************************************************************************/

void PWM1_OC1A_init(void){
	SETBIT(DDRD,5);        // make OC1A output
	SETBIT(TCCR1A,COM1A1); // set non inverting mode
	SETBIT(TCCR1A,WGM10);  // set FAST frq 10bit
	SETBIT(TCCR1A,WGM11);  // set FAST frq 10bit
	SETBIT(TCCR1B,WGM12);  // set FAST frq 10bit
	SETBIT(TCCR1B,CS10);   // No prescaler	
}
/*
duty_cycle = OCR/1023 * 100
*/
void PWM1_OC1A_duty(uint8_t duty_cycle){
	OCR1A = duty_cycle * 10.23;
}

