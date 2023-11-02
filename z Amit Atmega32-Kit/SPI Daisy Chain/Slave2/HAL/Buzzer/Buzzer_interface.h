/*
 * Buzzer_interface.h
 *
 * Created: 10/24/2023 6:39:25 PM
 *  Author: Ali
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "MCAL/DIO/DIO.h"

void Buzzer_init();
void Buzzer_on();
void Buzzer_off();
void Buzzer_toggle();



#endif /* BUZZER_INTERFACE_H_ */