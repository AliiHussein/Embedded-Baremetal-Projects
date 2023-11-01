/*
 * Button.h
 *
 * Created: 10/20/2023 2:20:42 PM
 *  Author: Ali
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "std_macros.h"
#include "MCAL/DIO/DIO.h"

void button_init(uint8 copy_u8PortID, uint8 copy_u8PinID);
uint8 button_read(uint8 copy_u8PortID, uint8 copy_u8PinID);




#endif /* BUTTON_H_ */