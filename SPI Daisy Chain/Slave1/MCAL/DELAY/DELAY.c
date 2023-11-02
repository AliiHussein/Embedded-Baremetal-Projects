/*
 * DELAY.c
 *
 * Created: 10/24/2023 7:22:02 PM
 *  Author: Ali
 */ 

#include "std_macros.h"
#include "DELAY.h"

void delay_s(uint32 seconds){
	uint32 counts = seconds * (F_CPU / 10);
	for(uint32 i = 0; i < counts; i++);
}

void delay_ms(uint32 milliseconds){
	uint32 counts = milliseconds * (F_CPU / 10000UL);  
	for(uint32 i = 0; i < counts; i++);
}

void delay_us(uint32 microseconds){
	uint32 counts = microseconds * ((F_CPU * 100UL) / 10000000UL);
	counts = counts / 100;
	for(uint32 i = 0; i < counts; i++);  
	                                   
}