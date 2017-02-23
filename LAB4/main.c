/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

//macros arm switch statements
#define HOME 0
#define WAIT 1
#define GRASP 2
#define TORQUE_SENSE 3
#define DROP_LIGHT 4
#define DROP_HEAVY 5


unsigned char interruptToggle = 0;
unsigned char armPos = HOME;

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
			//This is to do stuff

			//sample IR's
			ir1.adcVal = getIRValue(ir1.port);
			ir2.adcVal = getIRValue(ir2.port);

			//Convert IR's
			ir1.millimeters = adcToMillimeters(ir1.adcVal);
			ir2.millimeters = adcToMillimeters(ir2.adcVal);

			// Print IR Data
			printf(" IR Distance:  ");
			printf(" IR1: %d  \n\r", (int) ir1.millimeters);
			printf(" IR2: %d  \n\r", (int) ir2.millimeters);

			//TODO sample potentiometers

			//State machine for arm positions
			switch(armPos){
			case HOME:
				//move arm to home

				break;
			case WAIT:
				//move arm to wait

				break;
			case GRASP:
				//grasp block

				break;
			case TORQUE_SENSE:
				//torque sense

				break;
			case DROP_LIGHT:
				//move arm to position to drop light block

				break;
			case DROP_HEAVY:
				//move arm to position to drop heavy block

				break;
			default:
				//This is bad
				return 1;
				break;
			} //end switch(armPos)

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
