/*
 * Timer0.h
 *
 * Created: 3/19/2023 1:55:10 PM
 *  Author: Ali
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_macros.h"

void Timer0_normal_init(void);
void Timer0_CTC_init(uint8_t max);
void Timer0_freq_gen_init(uint8_t max);

#endif /* TIMER0_H_ */