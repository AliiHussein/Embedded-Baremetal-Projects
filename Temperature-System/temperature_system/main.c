/*
 * temperature_system.c
 *
 * Created: 5/5/2023 4:39:14 PM
 * Author : Ali
 */ 

#include "LCD.h"
#include "ADC.h"

int main(void)
{
    ADC_init();
	LCD_init();
	
	LCD_write_string("Temperature:");
	
	// DIO config
	SETBIT(DDRD, 0); // PD0 output
	SETBIT(DDRD, 1); // PD1 output
	
	
	uint16_t temp;
	uint16_t volt;
    while (1) 
    {
		
		volt = ADC_read(0);
		temp = (volt * 150lu) / 1023;
		
		if(temp < 25){
			SETBIT(PORTD, 0); // HEATER ON
			CLRBIT(PORTD, 1); // AIR COND OFF
		}
		else if(temp > 30){
			SETBIT(PORTD, 1); // AIR COND ON
			CLRBIT(PORTD, 0); // HEATER OFF
		}
		else{
			CLRBIT(PORTD, 0); // HEATER OFF
			CLRBIT(PORTD, 1); // AIR COND OFF
		}
		
		
		
		LCD_write_command(0x8c);
		LCD_write_string("    ");
		LCD_write_command(0x8c);
		LCD_write_number(temp);
		LCD_write_string(" C");
		
		_delay_ms(500);
    }
}

