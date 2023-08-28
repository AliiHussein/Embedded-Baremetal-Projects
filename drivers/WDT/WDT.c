/*
 * WDT.c
 *
 * Created: 3/25/2023 1:43:53 PM
 *  Author: Ali
 */ 

#include "WDT.h"

void WDT_on(){
	WDTCR = (1<<WDP2) | (1<<WDP1) | (1<<WDE); //prescale set to 1 second, enable wdt
}
void WDT_off(){
	WDTCR = (1<<WDTOE) | (1<<WDE);
	WDTCR = 0;
}