/*
 * SevenSeg.h
 *
 * Created: 10/21/2023 9:55:01 AM
 *  Author: Ali
 */ 


#ifndef SEVENSEG_H_
#define SEVENSEG_H_


void sevenseg_init(void);
void sevenseg_write(uint8 value, uint8 ss_num);
void sevenseg_write_four(uint32 value);
void sevenseg_write_two(uint8 value);


#endif /* SEVENSEG_H_ */