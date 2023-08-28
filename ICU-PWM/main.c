/*
 * drivers.c
 *
 * Created: 8/19/2023 6:46:37 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "LCD.h"
#include "PWM.h"
#include "ICU.h"

int main(void)
{	
	// Initializing LCD
	LCD_init();
	// Initialize the PWM
	PWM0_OC0_init();
	uint16_t duty = 90;
	
    while (1) 
    {
		
		PWM0_OC0_duty(duty);
		LCD_write_command(0x80);
		LCD_write_string("PWM= ");
		LCD_write_number(duty);
		LCD_write_string("%");
		LCD_write_command(0xc0);
		LCD_write_string("ICU= ");
		LCD_write_number(timer1_init_input_capture_usec());
		LCD_write_string(" usec");
		duty = duty - 20;
		
		if(duty == 10){
			break;
		}
		_delay_ms(500);
		
		
    }
}

/*
ISR(TIMER0_COMP_vect){
	static uint16_t count = 0;
	count++;
	if(count == 40000){
		TOGBIT(PORTB, 0);
		count = 0;
	}
}
*/

/* 
	To get the count value:
	Timer_counts = (Required_time / timer_count_time) - 1
	count = Timer_counts / max_timer_counts

ISR(TIMER0_OVF_vect){
	static uint16_t count = 0;
	count++;
	if(count == 625){
		TOGBIT(PORTB, 0);
		count = 0;
	}
}
*/

