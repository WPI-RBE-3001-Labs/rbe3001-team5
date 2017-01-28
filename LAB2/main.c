/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

struct Potentiometer{
	int ADCVal; //the value from 0-1023
	float voltage; //the analog voltage from 0 to 5V
	float angle; //the angle of the potentiometer form 0-270 degrees
} upperJoint;

int main(){
	//Common setup here:
	nukeWDT(); //Disable Watchdog Timer
	sei(); // Enable Global Interrupts
	initRBELib();//Enable printf() and setServo()

	//Interchange the correct part of the lab


	return 1;
} /* End main */

//This does the first part of the lab
//It outputs the analog values of the arm pot
//it will be set at 0 and 90 degrees

#define Arm0ADCPort 2
#define Arm1ADCPort 3

void logPot(){
	//initialize ADC to correct channel
	initADC(Arm0ADCPort); //TODO find pot channel for arm link

	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);

	while(1){
		//read pot value
		upperJoint.ADCVal = getADC(Arm0ADCPort);
		//print pot values
		//LSB:
		putCharDebug(upperJoint.ADCVal);
		//MSB:
		putCharDebug(upperJoint.ADCVal >> 8);
	} //End while(1)

}//end LogPot()


void sawtoothWave(){
	//setup the SPI buss
	initSPI();
}

void readCurrentSense(){

}

void PIDarmControl(){

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
