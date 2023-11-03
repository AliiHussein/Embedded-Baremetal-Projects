/*
 * UART_Private.h
 *
 * Created: 10/30/2023 9:08:43 AM
 *  Author: Ali
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR   *((volatile uint8 *)0x2C)

#define UCSRA *((volatile uint8 *)0x2B)
#define RXC  7 
#define TXC  6
#define UDRE 5
#define FE   4
#define DOR  3
#define PE   2
#define U2X  1
#define MPCM 0

#define UCSRB *((volatile uint8 *)0x2A)
#define RXCIE 7 
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2
#define RXB8  1
#define TXB8  0

#define UCSRC *((volatile uint8 *)0x40)
#define URSEL 7
#define UMSEL 6
#define UPM1  5
#define UPM0  4
#define USBS  3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0

#define UBRRL *((volatile uint8 *)0x29)

#define UBRRH *((volatile uint8 *)0x40) 




#endif /* UART_PRIVATE_H_ */