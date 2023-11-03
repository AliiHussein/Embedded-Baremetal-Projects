/*
 * EXT_Private.h
 *
 * Created: 10/22/2023 1:59:31 PM
 *  Author: Ali
 */ 


#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_

#define GICR *((volatile uint8 *)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define MCUCR *((volatile uint8 *)0x55)
#define ISC11 3 
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define MCUCSR *((volatile uint8 *)0x54)
#define ISC2 6

#endif /* EXT_PRIVATE_H_ */