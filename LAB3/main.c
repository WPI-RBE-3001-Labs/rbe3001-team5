/*
 * main.c
 *	Group 5 LAB 3
 *  Created on: FEB 1st, 2017
 */

#include "main.h" //File containing all the includes
#include "RBELib/RBELib.h"
#include <stdlib.h>
#include <avr/io.h>

#define Arm0ADCPort 2
#define Arm1ADCPort 3

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};


char inchar; //character for receiving serial data
unsigned long lowADC = 0;
unsigned long highADC = 0;
unsigned long pot1Ang=0;
unsigned long potAngInt;
unsigned long mV=0;
volatile unsigned long systemTime = 0;
volatile unsigned long timerCounter;
volatile unsigned long intTime;
volatile double timerCountVal = 9; //9 for ms system time
volatile double timerCountVal2 = 100;
volatile long highLinkErr;
volatile long lowLinkErr;
int cnt0 = 0;
int cnt1 = 0;
int stop_flag = 0;
long int count2 = 0;

volatile int buttonState = 7;
volatile int highSetP;
volatile int lowSetP;

volatile int count = 0;
volatile int sample_flag = 0;
int maxCount = 1000;

int main(){
	//Common setup here:
	//nukeWDT(); //Disable Watchdog Timer
	sei(); // Enable Global Interrupts
	initRBELib();//Enable printf() and setServo()
	debugUSARTInit(115200);//initialize USART 1 for transmission to Putty
	initTimer(0,0,0);
	initADC(0);

	printf("TEST \n\r");
	initSPI();
	initEncoder();

	setConst('H',20.0,0.01,0.1);
	setConst('L',20.0,0.01,0.1);


	//TODO Interchange the correct part of the lab
	while(1){

	}

	//	int cnt = 0;
	//	while(1) {
	//		_delay_ms(20);
	//		cnt = EncoderCounts(0);
	//		printf("A %d \n\r", cnt);
	//	}

	return 1;
} /* End main */


ISR(TIMER0_OVF_vect) {//Sets sampling Rate and Updates PID
	count++;
	count2++;

	if (count >= maxCount) {
		//printf("in");
		sample_flag = 1;
		count = 0;
	}


	timerCounter++;
	//counts to make 1ms timer
	if (timerCounter >=timerCountVal)
	{
		timerCounter=0;
		systemTime++;
		intTime++;
		// Sets PID at 100hz
		if (intTime>=10)
		{
			// updatePIDLink('H',calcPID('H',90,getADC(2)));
			// updatePIDLink('L',calcPID('L',90,getADC(3)));
			updatePIDLink('H',highSetP);
			updatePIDLink('L',lowSetP);
			test_accel();
			logPot2();
			ENCODER();
			button_move();

			intTime = 0;

		}
	}


}

//Code Written by Calum to read the Encoders
void ENCODER(){

	ENCODER_SS_0_ddr = 1;
	ENCODER_SS_0 = 1;
	ENCODER_SS_1_ddr = 1;
	ENCODER_SS_1 = 1;

	if(!stop_flag){
	resetEncoder(0);
	resetEncoder(1);
	stop_flag = 1;
	}
	else if(stop_flag){
		cnt0 = EncoderCounts(0);
		cnt1 = EncoderCounts(1);


		printf("Encoder 0 :%f degrees \n\r", cnt0*0.19);
		printf("Encoder 1 :%f degrees \n\r", cnt1*0.12);
		printf("Encoder 0 :%f speed \n\r", (double)(cnt0*600)/(42*360));
		//printf("Encoder 1 :%f speed \n\r", (double)(cnt1*600)/(42*360));
	}
		//resetEncoder();
	}

void button_move(){
//PID run at the interrupt
	DDRB &= ~(1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);
	PORTC &= ~(1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);

		if (!PINBbits._P0)
			buttonState = 7;
		else if (!PINBbits._P1)
			buttonState = 6;
		else if (!PINBbits._P2)
			buttonState = 5;
		else if (!PINBbits._P3)
			buttonState = 4;
		else
			buttonState = 8;

		printf("button: %d \n\r",buttonState);

		switch(buttonState){

		case 4:
			lowSetP=angleToADCLow(90);
			highSetP=angleToADCHigh(0);
			resetEncoder(0);
			resetEncoder(1);
			cnt1 = 0;
			cnt1 = 0;
			break;
		case 5:
			lowSetP=angleToADCLow(-60);
			highSetP=angleToADCHigh(-30);
			break;
		case 6:
			lowSetP=angleToADCLow(60);
			highSetP=angleToADCHigh(30);
			break;
		case 7:
			lowSetP=angleToADCLow(90);
			highSetP=angleToADCHigh(90);
			break;
		case 8:
			lowSetP=angleToADCLow(45);
			highSetP=angleToADCHigh(45);
		}
	}


void logPot2(){
			//read pot value for upper and lower joints
			upperJoint.ADCVal = getADC(Arm0ADCPort);
			lowerJoint.ADCVal = getADC(Arm1ADCPort);

			//Calculate Angle and Voltage Upper Joint
			upperJoint.voltage = potVolts(upperJoint.ADCVal);
			upperJoint.angle = potAngle(upperJoint.ADCVal);

			//Calculate Angle and Voltage Lower Joint
			lowerJoint.voltage = potVolts(lowerJoint.ADCVal);
			lowerJoint.angle = potAngle(lowerJoint.ADCVal);

			printf(" Upper Joint Angle %d \n\r", (int) upperJoint.angle);

			printf(" Lower Joint Angle: %d \n\r", (int) lowerJoint.angle);

}
