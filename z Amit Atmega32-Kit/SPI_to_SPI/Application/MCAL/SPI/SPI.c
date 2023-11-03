/*
 * SPI.c
 *
 * Created: 10/31/2023 2:38:54 PM
 *  Author: Ali
 */ 

#include "Bit_math.h"
#include "std_types.h"
#include "memMap.h"

#include "SPI_CFG.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"

void SPI_master_init(void){
	 // 0. MOSI as OUTPUT |  MISO as INPUT | SS OUTPUT | CLK OUTPUT
	 SETBIT(DDRB, 5); CLRBIT(DDRB, 6); SETBIT(DDRB, 4); SETBIT(DDRB, 7);
	 uint8 temp_SPCR = 0;
	 // 1. SPI Enable
	 SETBIT(temp_SPCR, SPE);
	 // 2. Data order -> LSB first
	 //SETBIT(temp_SPCR, DORD);
	 // 3. Master select
	 SETBIT(temp_SPCR, MSTR);
	 // 4. Clock Polarity & Phase (0, 0)
	 CLRBIT(temp_SPCR, CPOL); CLRBIT(temp_SPCR, CPHA);
	 // 5. Clock Rate freq/16
	 CLRBIT(temp_SPCR, SPR1); SETBIT(temp_SPCR, SPR0); // SPI2X = 0
	 
	 SPCR = temp_SPCR;
}

void SPI_slave_init(void){
	// 0. MOSI as OUTPUT |  MISO as INPUT | SS OUTPUT | CLK OUTPUT
	CLRBIT(DDRB, 5); SETBIT(DDRB, 6); CLRBIT(DDRB, 4); CLRBIT(DDRB, 7);
	uint8 temp_SPCR = 0;
	// 1. SPI Enable
	SETBIT(temp_SPCR, SPE);
	// 2. Data order -> LSB first
	//SETBIT(temp_SPCR, DORD);
	// 3. Master select
	CLRBIT(temp_SPCR, MSTR);
	// 4. Clock Polarity & Phase (0, 0)
	CLRBIT(temp_SPCR, CPOL); CLRBIT(temp_SPCR, CPHA);
	// 5. Clock Rate freq/16
	CLRBIT(temp_SPCR, SPR1); SETBIT(temp_SPCR, SPR0); // SPI2X = 0
	
	SPCR = temp_SPCR;
}

void SPI_send(uint8 value){
	// 1. Start transmission
	SPDR = value;
	// 2. wait
	while(READBIT(SPSR, SPIF) == 0);
}

void SPI_recieve(uint8 * value){
	// 1. wait for data
	while(READBIT(SPSR, SPIF) == 0);
	// 2. Return data
	*value = SPDR;	
}

uint8 SPI_RX_TX(uint8 data){
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}