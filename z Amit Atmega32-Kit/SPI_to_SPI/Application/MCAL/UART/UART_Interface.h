/*
 * UART_Interface.h
 *
 * Created: 10/30/2023 9:08:30 AM
 *  Author: Ali
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void Uart_init(void);
void Uart_Transmit(uint8 Value);
void Uart_Receive(uint8 * Value);

#endif /* UART_INTERFACE_H_ */