/*
 * SevenSeg.c
 *
 * Created: 10/21/2023 9:54:51 AM
 *  Author: Ali
 */ 

#include "std_macros.h"

#include "SevenSeg.h"
#include "SevenSeg_CFG.h"


void sevenseg_init(){
	SEVEN_SEG_INIT_PORTS();
	
}

void sevenseg_write(uint8 value, uint8 ss_num){
	
	EN1_DIS();EN2_DIS();
	
	switch(ss_num){
		case 1: EN1_EN(); break;
		case 2: EN2_EN(); break;
	}
	
	switch(value){
		case 0: CLRBIT(PORTC, 7); CLRBIT(PORTC, 6); CLRBIT(PORTC, 5); CLRBIT(PORTC, 4); break;
		case 1: CLRBIT(PORTC, 7); CLRBIT(PORTC, 6); CLRBIT(PORTC, 5); SETBIT(PORTC, 4); break;
		case 2: CLRBIT(PORTC, 7); CLRBIT(PORTC, 6); SETBIT(PORTC, 5); CLRBIT(PORTC, 4); break;
		case 3: CLRBIT(PORTC, 7); CLRBIT(PORTC, 6); SETBIT(PORTC, 5); SETBIT(PORTC, 4); break;
		case 4: CLRBIT(PORTC, 7); SETBIT(PORTC, 6); CLRBIT(PORTC, 5); CLRBIT(PORTC, 4); break;
		case 5: CLRBIT(PORTC, 7); SETBIT(PORTC, 6); CLRBIT(PORTC, 5); SETBIT(PORTC, 4); break;
		case 6: CLRBIT(PORTC, 7); SETBIT(PORTC, 6); SETBIT(PORTC, 5); CLRBIT(PORTC, 4); break;
		case 7: CLRBIT(PORTC, 7); SETBIT(PORTC, 6); SETBIT(PORTC, 5); SETBIT(PORTC, 4); break;
		case 8: SETBIT(PORTC, 7); CLRBIT(PORTC, 6); CLRBIT(PORTC, 5); CLRBIT(PORTC, 4); break;
		case 9: SETBIT(PORTC, 7); CLRBIT(PORTC, 6); CLRBIT(PORTC, 5); SETBIT(PORTC, 4); break;
	}	
	delay_ms(1);
}

void sevenseg_write_four(uint32 value){
	
	sevenseg_write(value%10, 1);
	value/=10;
	sevenseg_write(value%10, 2);
	value/=10;
	sevenseg_write(value%10, 3);
	value/=10;
	sevenseg_write(value%10, 4);
}

void sevenseg_write_two(uint8 value){
	
	sevenseg_write(value%10, 1);
	value/=10;
	sevenseg_write(value%10, 2);
}