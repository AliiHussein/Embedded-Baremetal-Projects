/*
 * KEYPAD_cfg.h
 *
 * Created: 3/7/2023 3:13:46 PM
 *  Author: Ali
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "std_macros.h"

#define INIT_KEYPAD_PINS() DDRC = 0xf0;

#define COL1() READBIT(PINC, 3)
#define COL2() READBIT(PINC, 2)
#define COL3() READBIT(PINC, 1)
#define ROW1(x) if(x == 1) SETBIT(PORTC, 7); else CLRBIT(PORTC, 7)
#define ROW2(x) if(x == 1) SETBIT(PORTC, 6); else CLRBIT(PORTC, 6)
#define ROW3(x) if(x == 1) SETBIT(PORTC, 5); else CLRBIT(PORTC, 5)
#define ROW4(x) if(x == 1) SETBIT(PORTC, 4); else CLRBIT(PORTC, 4)


#endif /* KEYPAD_CFG_H_ */