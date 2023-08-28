/*
 * uart.h
 *
 * Created: 8/28/2023 12:43:01 PM
 *  Author: Ali
 */ 


#ifndef UART_H_
#define UART_H_
#include "std_macros.h"

/*****************************************************************************
* Function Name: Uart_init
* Purpose      : init uart with one stop bit, no parity, baud rate 9600 and 8 bit data
* Parameters   : void
* Return value : void
*****************************************************************************/
void Uart_init(void);

/*****************************************************************************
* Function Name: Uart_Transmit
* Purpose      : Send 8-bit data and make sure the data is out
* Parameters   : uint8_t  data to send 
* Return value : void
*****************************************************************************/
void Uart_Transmit(uint8_t);

/*****************************************************************************
* Function Name: Uart_Read
* Purpose      : wait until receiving 1 byte (sync function)
* Parameters   : void
* Return value : data recieved 
*****************************************************************************/
uint8_t Uart_Receive(void);


#endif /* UART_H_ */