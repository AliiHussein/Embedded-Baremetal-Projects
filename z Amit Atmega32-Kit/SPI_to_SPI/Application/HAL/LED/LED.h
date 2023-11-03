/*
 * LED.h
 *
 * Created: 10/20/2023 12:14:30 PM
 *  Author: Ali
 */ 


#ifndef LED_H_
#define LED_H_

#include "std_macros.h"
#include "MCAL/DIO/DIO.h"

void led_init(uint8 copy_u8PortID, uint8 copy_u8PinID);
void led_on(uint8 copy_u8PortID, uint8 copy_u8PinID);
void led_off(uint8 copy_u8PortID, uint8 copy_u8PinID);
void led_toggle(uint8 copy_u8PortID, uint8 copy_u8PinID);




#endif /* LED_H_ */