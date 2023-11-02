/*
 * DIO.h
 *
 * Created: 10/20/2023 10:57:36 AM
 *  Author: Ali
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "std_macros.h"

typedef enum {portA = 'A', portB, portC, portD}PORTS;
typedef enum {INPUT = 0, OUTPUT}DIR;
typedef enum {LOW = 0, HIGH}LOGIC;

void DIO_voidSetPortDirection(uint8 copy_u8PortID, uint8 copy_u8PortDir);
void DIO_voidSetPortValue(uint8 copy_u8PortID, uint8 copy_u8PortVal);

void DIO_voidSetPinDirection(uint8 copy_u8PortID, uint8 copy_u8PinID, uint8 Copy_u8PinDir);
void DIO_voidSetPinValue(uint8 copy_u8PortID, uint8 copy_u8PinID, uint8 Copy_u8PinValue);

uint8 DIO_voidGetBitValue(uint8 copy_u8PortID, uint8 copy_u8PinID);

#endif /* DIO_H_ */