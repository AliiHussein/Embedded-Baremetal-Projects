/*
 * UART_CFG.h
 *
 * Created: 10/30/2023 9:08:57 AM
 *  Author: Ali
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/* BAUD RATE: 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, 76800, 115200, 230400, 250000 */
#define BAUD_RATE 9600

/* STOP bit: 1 or 2  */
#define STOP_BIT 1

/*
PARITY bits: 
0 => disable, 
1 => Enable parity odd, 
2 => Disable parity even
*/
#define UART_PARITY 0

/* UART DATA SIZE: 5, 6, 7, 8, 9 */
#define UART_DATA_SIZE 8

#endif /* UART_CFG_H_ */