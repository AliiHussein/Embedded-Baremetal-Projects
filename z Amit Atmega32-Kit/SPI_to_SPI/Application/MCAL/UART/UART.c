/*
 * UART.c
 *
 * Created: 10/30/2023 9:08:14 AM
 *  Author: Ali
 */ 

#include "std_macros.h"

#include "UART_CFG.h"
#include "UART_Interface.h"
#include "UART_Private.h"

// Baud Rate = UBRR = (Fosc/16* Baud) -1

void Uart_init(void){
	// Baud Rate = 9600
	UBRRL = 103;
	
	// 0. Enable Receive and Transmission
	SETBIT(UCSRB, RXEN); SETBIT(UCSRB, TXEN);
	// Set one as input the other as output
	SETBIT(DDRD, 1); CLRBIT(DDRD, 0);
	// 1. Normal mode - No double speed
	CLRBIT(UCSRA, U2X);
	// 2. Asynchronous
	uint8 temp_UCSRC = 0;
	SETBIT(temp_UCSRC, URSEL); CLRBIT(temp_UCSRC, UMSEL);
	// 3. No parity
	CLRBIT(temp_UCSRC, UPM1); CLRBIT(temp_UCSRC, UPM0);
	// 4. 1 stop bit
	CLRBIT(temp_UCSRC, USBS);
	// 5. 8 bit data
	CLRBIT(temp_UCSRC, UCSZ1); CLRBIT(temp_UCSRC, UCSZ0); SETBIT(UCSRB, UCSZ2);
	// Assign all to UCSRC
	UCSRC = temp_UCSRC;
	
		
}

void Uart_Transmit(uint8 Value){
	while(READBIT(UCSRA, UDRE) == 0);
	UDR = Value;
	while(READBIT(UCSRA, TXC) == 0);
	// Clear the flag by writing one
	SETBIT(UCSRA, TXC);
}

void Uart_Receive(uint8 * Value){
	while(READBIT(UCSRA,RXC) == 0);
	
	*Value = UDR;
	
}