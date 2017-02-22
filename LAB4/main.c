/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};
struct IR ir1 = {IR_PORT1,0,0};
struct IR ir2 = {IR_PORT2,0,0};

unsigned char interruptToggle = 0;

int main(){
	//Common setup here:
//	nukeWDT(); //Disable Watchdog Timer

	sei(); // Enable Global Interrupts

	initRBELib();//Enable printf() and setServo()

	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);

	//TODO ensure correct timer configuration
	initTimer(0,0,0);

	//start up the SPI
	initSPI();

	//TODO Make sure that the DAC is ON/OFF properly
	//disable DAC for doing potentiometer stuff
	DAC_SS = 1;

	//TODO make sure that the IR's are setup correctly
	setupIR(3);
	setupIR(4);

	while(1){
		if(interruptToggle){
			//This is move the arm in real time

			interruptToggle = 0;
		}
	} // end while(1)

	return 1;
} /* End main */

//TODO finish 100 Hz Timer ISR
unsigned int beltTimer = 0; //timing of picking up block
ISR(TIMER0_OVF_vect){
	interruptToggle = 1;
	if (beltTimer == IR_TIMER){
		//pick up block
	}
}
