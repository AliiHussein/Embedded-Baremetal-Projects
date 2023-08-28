/*
 * uart.c
 *
 * Created: 8/28/2023 12:42:19 PM
 *  Author: Ali
 */ 
#include "UART.h"
void Uart_init(){
	// baud rate
	UBRRL = 103;// baud rate 9600, F_CPU = 16Mhz
	SETBIT(UCSRB,RXEN);
	SETBIT(UCSRB,TXEN);
}

void Uart_Transmit(uint8_t data){
	//while(READBIT(UCSRA,UDRE) == 0);
	UDR = data;
	while(READBIT(UCSRA,TXC) == 0);
}


uint8_t Uart_Receive(){
	while(READBIT(UCSRA,RXC) == 0);
	return UDR;
}