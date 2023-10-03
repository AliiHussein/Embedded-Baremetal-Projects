/*
 * coolar_app.c
 *
 * Created: 3/30/2023 1:58:45 AM
 * Author : Ali
 */ 

#include "LCD.h"
#include "PWM.h"
#include "ADC.h"

// Magic Numbers
#define min_temp 35
#define max_temp 50
#define min_pwm 50
#define max_pwm 100

// Function Prototype
void display(int t, int p);

int main(void)
{
	// Initializations
	PWM1_OC1A_init();
	ADC_init();
	LCD_init();
	
	/* Enable the motor (PORTD 3 to 5)
	ENA -> PD5 (PWM already enables when PWM1 is initialized)
	IN1 -> PD4
	IN2 -> PD3
	*/
	DDRD |= (1<<PD3) | (1<<PD4); 
	SETBIT(PORTD, PD3);
	CLRBIT(PORTD, PD4);
	/* Enable LED*/
	DDRB |= (1<<PB0); // PB0 output
	CLRBIT(PORTB, PB0); // Initially off
	
	// Variables initializations
	int value;
	int temp = 0;
	int prev_temp;
	int pwm_value = 0;
    while (1) 
    {
		value = ADC_read(0);
		prev_temp = temp;
		temp = value / 10.23;
		
		if(prev_temp != temp){
			
			if(temp >= min_temp && temp <= max_temp){
				pwm_value = min_pwm + ((temp-min_temp)*(max_pwm-min_pwm))/(max_temp-min_temp) ;
				//pwm_value = 50 + ((temp-35)/(50-35)) * (100-50);
				PWM1_OC1A_duty(pwm_value);
				SETBIT(PORTB, PB0); // LED ON
			}
			else if(temp > max_temp){
				pwm_value = 100;
				PWM1_OC1A_duty(pwm_value);
				SETBIT(PORTB, PB0); // LED ON
			}
			else{
				pwm_value = 0;
				PWM1_OC1A_duty(pwm_value);  // Motor off
				CLRBIT(PORTB, PB0); // LED OFF
			}
			
			display(temp, pwm_value);
			
		}
		
		_delay_ms(100);
		
    }
	
	
}

void display(int t, int p){
	// Temperature display
	LCD_write_command(0x80);
	LCD_write_string((uint8_t*)"Temp=    ");
	LCD_write_command(0x86);
	LCD_write_number(t);
	
	// PWM display
	LCD_write_command(0xc0);
	LCD_write_string((uint8_t*)"PWM =    ");
	LCD_write_command(0xc6);
	LCD_write_number(p);
}

