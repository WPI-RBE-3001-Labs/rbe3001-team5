/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

float ticksToG(int ticks);

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};

int main(){
	//Common setup here:
//	nukeWDT(); //Disable Watchdog Timer

	sei(); // Enable Global Interrupts

	initRBELib();//Enable printf() and setServo()

	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);

	//initTimer(0,0,0);

	initSPI(); //start up the SPI

	//TODO Make sure that the DAC is ON/OFF properly
	//disable DAC for doing potentiometer stuff
	DAC_SS = 1;

	//TODO Interchange the correct part of the lab
	readAccelerometer();

	return 1;
} /* End main */

void readEncoders(){

	while(1){

	}//end while(1)

}//end readEncoders()

BOOL sample = 0; //global toggle variable
void readAccelerometer(){
	//Begin Timer Interrupt.
	//Need to sample at 1000Hz, so 1ms timer
	//Timer 0, standard config, 1 ms time
	initTimer(0,0,1);
	struct acceleration acc = {0,0,0,0,0,0};
	while(1){
		if(sample){
			//Get the data
			acc.xTicks = spiTransceive(0);
			acc.yTicks = spiTransceive(0);
			acc.zTicks = spiTransceive(0);

			//convert it
			acc.xAcc = ticksToG(acc.xTicks);
			acc.yAcc = ticksToG(acc.yTicks);
			acc.zAcc = ticksToG(acc.zTicks);

			//print it
			printf(" Acceleration:  "); printf(",");
			printf(" X: %d ", (int) acc.xAcc);
			printf(",");
			printf(" Y: %d ", (int) acc.yAcc);
			printf(",");
			printf(" Z: %d ", (int) acc.zAcc);
			printf(",");


			//toggle the signal
			sample = 0;
		}//end if

	}//end while(1)

}//end readAccerlometer()

float ticksToG(int ticks){
	return ((ticks * 1.0) / 4095) * (3.3/0.3663);
}//end ticksToG()
