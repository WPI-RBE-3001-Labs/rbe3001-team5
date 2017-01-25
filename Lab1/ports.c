/*
 * portb.c
 *
 *  Created on: Jan 21, 2017
 *      Author: ewillcox
 */

#include "main.h"

void initPB(){
DDRB = PORT_OUTPUT;
}

void initPA(){
	DDRD = 0x0000;
	PORTD = 0xFF;
}

void blinkAll(double timeDelay){
PORTB = 0xFF;
_delay_ms(timeDelay);
PORTB = 0x00;
_delay_ms(timeDelay);
}

int button_state(){
	if (PIND == 0xFF){
		return 0;
	}
	else{
		return 1;
	}
}

