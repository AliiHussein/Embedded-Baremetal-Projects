/*
 * SevenSeg_CFG.h
 *
 * Created: 10/21/2023 10:19:45 AM
 *  Author: Ali
 */ 


#ifndef SEVENSEG_CFG_H_
#define SEVENSEG_CFG_H_

/*
	Decoder
	1. PB0 -> output
	2. PB1 -> output
	3. PB2 -> output
	4. PB4 -> output
	
	Enables (VCC)
	1. PA3 -> output
	2. PA2 -> output

*/

#define SEVEN_SEG_INIT_PORTS() DDRC = 0b11111100; PORTC = 0b11110000;

#define EN1_EN()   CLRBIT(PORTC,3);
#define EN1_DIS()  SETBIT(PORTC,3);
#define EN2_EN()   CLRBIT(PORTC,2);
#define EN2_DIS()  SETBIT(PORTC,2);



#endif /* SEVENSEG_CFG_H_ */