/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};

int main(){
	//Common setup here:
//	nukeWDT(); //Disable Watchdog Timer

	sei(); // Enable Global Interrupts

	initRBELib();//Enable printf() and setServo()

	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);

	initTimer(0,0,0); //TODO ensure correct configuration

	initSPI(); //start up the SPI

	//TODO Make sure that the DAC is ON/OFF properly
	//disable DAC for doing potentiometer stuff
	DAC_SS = 1;

	//TODO Interchange the correct part of the lab
	while(1){

	} // end while(1)

	return 1;
} /* End main */

//TODO finish 100 Hz Timer ISR
unsigned int beltTimer = 0; //timing of picking up block
ISR(TIMER0_OVF_VECTOR){
	if (beltTimer == IR_TIMER){
		//pick up block
	}
}
