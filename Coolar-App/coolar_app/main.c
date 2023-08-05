/*
 * coolar_app.c
 *
 * Created: 3/30/2023 1:58:45 AM
 * Author : Ali
 */ 

#include "LCD.h"
#include "PWM.h"
#include "ADC.h"

int main(void)
{
	// Initializations
	PWM1_OC1A_init();
	ADC_init();
	LCD_init();
	/* Enable the motor (PORTD 3 to 5)
	IN1 -> PD5 (PWM already enables when PWM1 is initialized)
	IN2 -> PD4
	ENA -> PD3
	*/
	DDRD |= (1<<PD4) | (1<<PD5); 
	SETBIT(PORTD, PD3);
	CLRBIT(PORTD, PD4);
	// PWM value calculation variables
	int8_t temperature_value;
	uint16_t voltage_value;
	uint8_t PWM_value;

    while (1) 
    {
		
		
		voltage_value = ADC_read(0);
		
		temperature_value = (voltage_value/308.0)*205 - 55; // mapping from voltage (0--1023) to temp (-55--150 C)
		
		
		// Mapping the temp value from 20 to 40 degrees to 0 to 100 duty cycle
		if(temperature_value < 30){
			PWM_value = 0;
			LCD_write_command(1);
			LCD_write_string((uint8_t *)"Cond1: v= ");
			LCD_write_number(voltage_value);
			LCD_write_command(0xc0); 
			LCD_write_string((uint8_t *)"Temp:");
			LCD_write_number(temperature_value);
			LCD_write_string((uint8_t *)" PWM:");
			LCD_write_number(PWM_value);
		}
		else if(temperature_value > 60){
			PWM_value = 100;
			LCD_write_command(1);
			LCD_write_string((uint8_t *)"Cond2:  v= ");
			LCD_write_number(voltage_value);
			LCD_write_command(0xc0);
			LCD_write_string((uint8_t *)"Temp:");
			LCD_write_number(temperature_value);
			LCD_write_string((uint8_t *)" PWM:");
			LCD_write_number(PWM_value);
		}
		else{
			PWM_value = ((temperature_value - 30)/30.0) * 100;  // FROM 30--60 to 0--100
			LCD_write_command(1);
			LCD_write_string((uint8_t *)"Cond3:  v= ");
			LCD_write_number(voltage_value);
			LCD_write_command(0xc0);
			LCD_write_string((uint8_t *)"Temp:");
			LCD_write_number(temperature_value);
			LCD_write_string((uint8_t *)" PWM:");
			LCD_write_number(PWM_value);
		}
		PWM1_OC1A_duty(PWM_value);

		_delay_ms(100);
    }
}

