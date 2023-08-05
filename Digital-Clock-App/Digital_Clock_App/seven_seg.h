/*
 * seven_seg.h
 *
 * Created: 3/9/2023 10:56:15 PM
 *  Author: Ali
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "seven_seg_cfg.h"
#include "std_macros.h"

void seven_seg_init(void);
void seven_seg_write(uint8_t num, uint8_t ss_num);


#endif /* SEVEN_SEG_H_ */