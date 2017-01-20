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
	DDRA |= 0xFF; //configure port A as output for LED's
	DDRB &= 0x00; //configure port B as input

	//Interchange the correct part of the Pre-lab
	part5();
	return 1;
} /* End main */

//This does the first code part of the Pre-lab
void part5(){
	volatile unsigned char buttonstate;

	while(1){
		buttonstate = PORTA; //reads buttons
		PORTB = buttonstate; //writes to LEDS
	}
}

//This does the second code part of the Pre-lab
void part6(){

}

//This does the third code part of the Pre-lab
void part7(){

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

