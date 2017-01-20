/*
 * main.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Matt
 */
#include "RBELib/RBELib.h"

void part5();
void part6();
void part7();
void WDT_off();

int main(){
	//Common setup code here:
	WDT_off(); //Disable watchdog timer

	//Interchange the correct part of the Pre-lab
	part5();
	//should never get here but if it does: error
	return 0;
} /* End main */

//This does the first code part of the Pre-lab
void part5(){
	volatile unsigned char buttonstate;
	DDRB |= 0xFF; //configure port A as output for LED's
	DDRA &= 0x00; //configure port B as input

	while(1){
		buttonstate = PORTA; //reads buttons
		PORTB = buttonstate; //writes to LEDS
	}
}

//This does the second code part of the Pre-lab
void part6(){
	debugUSARTInit(DEFAULT_BAUD); //112500
	unsigned char package = 0;

	while(1){
		package = getCharDebug(); //recieve a character
		//only transmit when the chip has something to transmit
		if(package){
			putCharDebug(package);
		}
	}
}

//This does the third code part of the Pre-lab
void part7(){
	unsigned char state = 0;
	DDRBbits._P4 = OUTPUT;

	while(1){
		switch(state){
		case 0:
			//the is the off case
			PINBbits._P4 = 0;
			break;
		case 1:
			//this is the on case
			PINBbits._P4 = 1;
			break;
		}
	}
}

void WDT_off(){
	__disable_interrupt();
	__watchdog_reset();
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/*Turn off WDT */
	WDTCSR = 0x00;
	__enable_interrupt();
}

