/*
 * EXT_Interface.h
 *
 * Created: 10/22/2023 1:59:20 PM
 *  Author: Ali
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

#include "EXT_Private.h"
#include "EXT_CFG.h"
#include "std_types.h"

void EXT_init(uint8 EXT_num, uint8 EXT_sens);
void EXT_callback(void (*PTR)(void) ,uint8 EXT_num);

#endif /* EXT_INTERFACE_H_ */