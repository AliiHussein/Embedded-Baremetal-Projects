/*
 * PWM.h
 *
 * Created: 5/9/2023 3:23:51 PM
 *  Author: Ali
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "std_macros.h"

void PWM0_OC0_init(void);
void PWM0_OC0_duty(uint8_t duty_cycle);

void PWM1_OC1A_init(void);
void PWM1_OC1A_duty(uint8_t duty_cycle);

void PWM2_OC2_init(void);
void PWM2_OC2_duty(uint8_t duty_cycle);

#endif /* PWM_H_ */