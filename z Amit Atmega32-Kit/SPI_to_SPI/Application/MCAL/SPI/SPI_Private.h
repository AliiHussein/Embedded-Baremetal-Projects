/*
 * SPI_Private.h
 *
 * Created: 10/31/2023 2:39:21 PM
 *  Author: Ali
 */ 

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR *((volatile uint8 *)0x2D)
#define SPIE 7 
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPSR *((volatile uint8 *)0x2E)
#define SPIF  7
#define WCOL  6
#define SPI2X 0

#define SPDR *((volatile uint8 *)0x2F)

#endif /* SPI_PRIVATE_H_ */