/*
 * ADC.c
 *
 * Created: 10/23/2023 12:11:25 PM
 *  Author: Ali
 */ 

#include "ADC_Interface.h"

void ADC_init(void){
	// 1. Disable peripherals before config
	CLRBIT(ADCSRA, ADEN);
	// 2. AVCC -> 5V :: REFS1, REFS0 = 0, 1
	SETBIT(ADMUX, REFS0); 
	CLRBIT(ADMUX, REFS1); 
	// 3. Right adjustment +
	//CLRBIT(ADMUX, ADLAR);
	// 4. Prescaler -> 128
	ADCSRA |= 0b111;
	// 5. Disable interrupt +
	//CLRBIT(ADCSRA, ADIE);
	// 6. Clear ADC flag by setting it +
	//SETBIT(ADCSRA, ADIF);
	// 7. Enable ADC
	SETBIT(ADCSRA, ADEN);
	
}

void ADC_read(uint8 channel, uint16 *Value){
	// 1. Select channel
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	// Start conversion
	SETBIT(ADCSRA, ADSC);
	// Wait for flag
	while(READBIT(ADCSRA, ADSC));
	// clear flag
	//SETBIT(ADCSRA, ADIF);
	// return data
	*Value = ADC;
	
}