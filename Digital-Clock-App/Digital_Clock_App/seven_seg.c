/*
 * seven_seg.c
 *
 * Created: 3/9/2023 10:56:03 PM
 *  Author: Ali
 */ 

#include "seven_seg.h"

uint8_t ss_data [] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
	
void seven_seg_init(void){
	SEVEN_SEG_INIT_PORTS();
	uint8_t i = 0;
	/* convert array element from cathode to anode*/
	#ifdef SS_ANODE
	for(i = 0; i < 10; i++){
		ss_data[i] ^= 0b01111111;
	}
	#endif
}

void seven_seg_write(uint8_t num, uint8_t ss_num){ 
	EN1_DIS();EN2_DIS();EN3_DIS();EN4_DIS();EN5_DIS();EN6_DIS();
	switch(ss_num){
		case 1: EN1_EN(); DP_OFF(); break;
		case 2: EN2_EN(); DP_ON(); break;
		case 3: EN3_EN(); DP_OFF(); break;
		case 4: EN4_EN(); DP_ON(); break;
		case 5: EN5_EN(); DP_OFF(); break;
		case 6: EN6_EN(); DP_OFF(); break;
	}
	SS_PORT &= 0b10000000;
	SS_PORT |= ss_data[num];
	_delay_ms(1);
}
