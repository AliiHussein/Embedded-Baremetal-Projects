/*
 * ADC_Interface.h
 *
 * Created: 10/23/2023 12:16:30 PM
 *  Author: Ali
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_CFG.h"
#include "ADC_Private.h"
#include "std_macros.h"

void ADC_init(void);
void ADC_read(uint8 channel, uint16 *Value);

#endif /* ADC_INTERFACE_H_ */