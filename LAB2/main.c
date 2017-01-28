/*
 * main.c
 *	Group 5 Lab 1
 *  Created on: Jan 17, 2017
 */
//test for commit
//#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"
#include <avr/io.h>
#include "main.h"

int main(){
	//Common setup here:
	nukeWDT();
	sei();
	//Enable printf() and setServo()
	initRBELib();
	//Interchange the correct part of the lab


	return 1;
} /* End main */

void calibrateArmPot(){

}

void logPot(){

}

void triangleWave(){

}

void sendToDAC(){

}

void readCurrentSense(){

}

void moveArmWithButton(){

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
