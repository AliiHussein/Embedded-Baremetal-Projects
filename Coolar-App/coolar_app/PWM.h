/*
 * PWM.h
 *
 * Created: 12/2/2022 11:24:30 AM
 *  Author: safifi
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "std_macros.h"


void PWM1_OC1A_init(void);
void PWM1_OC1A_duty(uint8_t duty_cycle);

#endif /* PWM_H_ */