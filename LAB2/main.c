/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

struct Potentiometer upperJoint = {0,0,0};

int main(){
	//Common setup here:
	nukeWDT(); //Disable Watchdog Timer
	sei(); // Enable Global Interrupts
	initRBELib();//Enable printf() and setServo()
	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);
	//TODO Make sure that the DAC is ON/OFF properly
	//dissable DAC for doing potentiometer stuff
	//DAC_SS = 1;

	//TODO Interchange the correct part of the lab
	sawtoothWave();

	return 1;
} /* End main */

//This does the first part of the lab
//It outputs the analog values of the arm pot
//it will be set at 0 and 90 degrees

#define Arm0ADCPort 2
#define Arm1ADCPort 3

void logPot(){
	//initialize ADC to correct channel
	initADC(Arm0ADCPort);

	while(1){
		//read pot value
		upperJoint.ADCVal = getADC(Arm0ADCPort);
		//Log Pot Value
		printf("PotValue: %d \n\r", (int) upperJoint.ADCVal);
	} //End while(1)

}//end LogPot()

void logPot2(){
	//initialize ADC to correct channel
	initADC(Arm0ADCPort);

	while(1){
		//read pot value
		upperJoint.ADCVal = getADC(Arm0ADCPort);

		//Calculate other Values
		upperJoint.voltage = potVolts(upperJoint.ADCVal);
		upperJoint.angle = potAngle(upperJoint.ADCVal);
		//TODO fix output formatting to be exported as CSV
		printf("PotValue: %d \n\r", (int) upperJoint.ADCVal);
		printf("PotVoltage: %d \n\r", (int) upperJoint.voltage);
		printf("PotAngle: %d \n\r", (int) upperJoint.angle);

	} //End while(1)

}//end LogPot()

//globals for this
int counter0 = 0;
char counter0Dir = 0;
int counter1 = 0;
char counter1Dir = 1;

void sawtoothWave(){
	//setup the SPI bus
	initSPI();
	//will output waves between channels 0 and 1
	//setup Timer
	initTimer(0,0,0);
	setCompValue(0, 20);

	while(1){
		//printf("PotAngle: %d \n\r", (int) counter0);
		//printf("PotAngle: %d \n\r", (int) counter1);
		setDAC(0, counter0);
		setDAC(1, counter1);
	}
}
//ISR for timer
ISR(TIMER0_OVF_vect){
	//Counter 0
	if (counter0 <= 4095){ //make sure is doesn't overflow
		if(!counter0Dir){ //first it goes forwards
			counter0++;
		}else{
			counter0--;
		}
	} else{
		counter0 = 0;
		if(!counter0Dir){ //first it goes forwards
			counter0Dir = 1;
		}else{
			counter0Dir = 0;
		}
	}
	//Counter 1
	if (counter1 <= 4095){ //make sure is doesn't overflow
		if(counter1Dir){ //first this one goes backwards
			counter1++;
		}else{
			counter1--;
		}
	} else {
		counter1 = 0;
		if(!counter1Dir){ //first it goes forwards
			counter1Dir = 1;
		}else{
			counter1Dir = 0;
		}
	}
}

//TODO
void driveMotors(){

}

//TODO readCurrentSense() funciton
void readCurrentSense(){

}
//TODO button arm control thing
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
