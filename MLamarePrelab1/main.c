/*
 * main.c
 * Matthew Lamare's Lab 1 Pre-Lab
 *  Created on: Jan 17, 2017
 *      Author: Matt
 */
#include "RBELib/RBELib.h"
#include <avr/io.h>

void part5();
void part6();
void part7();
void nukeWDT();

int main(){
	//Common setup code here:
	nukeWDT(); //Disable watchdog timer
	sei();
	//Interchange the correct part of the Pre-lab
	part6();
	//should never get here but if it does: error
	return 0;
} /* End main */

//This does the first code part of the Pre-lab
void part5(){
	volatile unsigned char buttonstate = 0x00;
	PORTB |= 0xFF;
	PORTD |= 0x00;
	DDRB |= 0xFF; //configure port B as output for LED's
	DDRD &= 0x00; //configure port D as input for switches

	while(1){
		buttonstate = PIND; //reads buttons
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
unsigned char state = 0; //accessed in ISR so must be a global

void part7(){
	DDRBbits._P7 = OUTPUT;
	initTimer(0, 0, 1000);
	while(1){
		switch(state){
		case 0:
			//the is the off case
			PINBbits._P7 = 1;
			break;
		case 1:
			//this is the on case
			PINBbits._P7 = 0;
			break;
		}
	}
}

//My ISR for part 7:
ISR (TIMER0_OVF_vect){
	if(!state){
		state = 1;
	}else{
		state = 0;
	}
}

//Note originally called for enabling and disabling interrupts within this function.
//builder didn't like that so I got rid of it
void nukeWDT(){
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/*Turn off WDT */
	WDTCSR = 0x00;
}

