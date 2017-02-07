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
	nukeWDT(); //Disable Watchdog Timer

	sei(); // Enable Global Interrupts

	initRBELib();//Enable printf() and setServo()

	//initialize USART 1 for transmission to Putty
	debugUSARTInit(115200);

	//initTimer(0,0,0);

	//TODO Make sure that the DAC is ON/OFF properly
	//disable DAC for doing potentiometer stuff
	DAC_SS = 1;

	//TODO Interchange the correct part of the lab
	sawtoothWave();

	return 1;
} /* End main */

//This does the first part of the lab
//It outputs the analog values of the arm pot
//it will be set at 0 and 90 degrees

#define Arm0ADCPort 2
#define Arm1ADCPort 3

void logPot2(){
	//initialize ADC to correct channel
	initADC(Arm1ADCPort);
	initADC(Arm0ADCPort);

	while(1){
		//read pot value for upper and lower joints
		upperJoint.ADCVal = getADC(Arm0ADCPort);
		lowerJoint.ADCVal = getADC(Arm1ADCPort);

		//Calculate Angle and Voltage Upper Joint
		upperJoint.voltage = potVolts(upperJoint.ADCVal);
		upperJoint.angle = potAngle(upperJoint.ADCVal);

		//Calculate Angle and Voltage Lower Joint
		lowerJoint.voltage = potVolts(lowerJoint.ADCVal);
		lowerJoint.angle = potAngle(lowerJoint.ADCVal);

		//Printing in CSV format Use Excel Filters to separate UJ from LJ
		// Printing Values in Columns ADCValue[counts], Voltage[mV], Angle[deg]
		printf(" Upper Joint:  "); printf(",");
		printf(" %d ", (int) upperJoint.ADCVal); printf(",");
		printf(" %d ", (int) upperJoint.voltage); printf(",");
		printf(" %d ", (int) upperJoint.angle); printf(",");
		//printf("\n\r");
		printf(" Lower Joint:  "); printf(",");
	    printf(" %d ", (int) lowerJoint.ADCVal); printf(",");
		printf(" %d ", (int) lowerJoint.voltage); printf(",");
		printf(" %d ", (int) lowerJoint.angle); printf(",");
		printf("\n\r");

	} //End while(1)

}//end LogPot()

//globals for t
int counter0 = 0;
signed char counter0Dir = 1;
int counter1 = 4095;
signed char counter1Dir = -1;
BOOL flag = 1;
char LEDON = 0;

void sawtoothWave(){
	//DDRA = (1 << DDA5);
	//disable IO port B
	//DDRB = 0;
	//setup the SPI bus
	initSPI();
	//will output waves between channels 0 and 1
	//setup Timer
	//initTimer(0,0,0);
	//setCompValue(0, 16);

	while(1){
//		if(flag){
//			PORTAbits._P5 = LEDON;
//			//printf("DAC Val: %d \n\r", counter0);
//			//printf("DAC Val: %d \n\r", counter1);
//			setDAC(0, counter0);
//			setDAC(1, counter1);
//			flag = 0;
//		}
//			//PINAbits._P7 = 0;
		setDAC(0, counter0);
		setDAC(1, counter1);

		if (counter0 > 4095 || counter0 < 0 ){ //If it is out of bounds
			counter0Dir *= -1; //change direction
		}
		counter0 += counter0Dir;

		//Counter 1
		if (counter1 > 4095 || counter1 < 0 ){ //If it is out of bounds
			counter1Dir *= -1; //change direction
		}
		counter1 += counter1Dir;

		printf("DAC0 %d ", (int) counter0); printf(", \n\r");
		printf("DAC1 %d ", (int) counter1); printf(", \n\r");
	}
}
//ISR for timer
//ISR(TIMER0_OVF_vect){
//	//Counter 0
//	if (counter0 > 4095 || counter0 < 0 ){ //If it is out of bounds
//		counter0Dir *= -1; //change direction
//	}
//	counter0 += counter0Dir;
//
//	//Counter 1
//	if (counter1 > 4095 || counter1 < 0 ){ //If it is out of bounds
//		counter1Dir *= -1; //change direction
//	}
//	counter1 += counter1Dir;
//	//printf("DAC Val: %d \n\r", flag);
//	flag = 1;
//	LEDON = 1 - LEDON;
//	TIFR0 = (1 << TOV0);
//	//sei();
//}


//TODO
void driveMotors(){

}

#define CurrentSense0Port 0
#define CurrentSense1Port 1
#define noLoadCurrent 553
#define voltageScaler 2
//readCurrentSense() funciton
void readCurrentSense(){
	//Initialize ADC first
	initADC(CurrentSense0Port);
	struct Current current0 = {0,0,0};
	while(1){
		current0.ADCVal = getADC(CurrentSense0Port);
		current0.ADCVal -= noLoadCurrent;
		current0.voltage *= voltageScaler;
		printf("Current Sensor %d ", (int) current0.ADCVal); printf(", \n\r");
	}
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
