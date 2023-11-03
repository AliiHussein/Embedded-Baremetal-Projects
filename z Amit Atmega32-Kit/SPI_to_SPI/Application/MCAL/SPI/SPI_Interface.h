/*
 * SPI_Interface.h
 *
 * Created: 10/31/2023 2:39:08 PM
 *  Author: Ali
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_master_init(void);
void SPI_slave_init(void);
void SPI_send(uint8 value);
void SPI_recieve(uint8 * value);
uint8 SPI_RX_TX(uint8  data);

#endif /* SPI_INTERFACE_H_ */