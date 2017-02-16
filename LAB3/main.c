/*
 * main.c
 *	Group 5 LAB 3
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"
#include "Accel.h"
#include <stdlib.h>
#include <avr/io.h>

#define Arm0ADCPort 2
#define Arm1ADCPort 3

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};

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

	printf("TEST \n\r");
	initSPI();
	initTimer(0,0,0);
	initEncoder();


	//TODO Interchange the correct part of the lab
	while(1){
		//test_accel(sample_flag);
		ENCODER();
	}

//	int cnt = 0;
//	while(1) {
//		_delay_ms(20);
//		cnt = EncoderCounts(0);
//		printf("A %d \n\r", cnt);
//	}

	return 1;
} /* End main */


ISR(TIMER0_OVF_vect) {
	count++;

	if (count >= maxCount) {
		//printf("in");
		sample_flag = 1;
		count = 0;
	}

}

//Code Written by Calum to read the Encoders
void ENCODER(){

	ENCODER_SS_0_ddr = 1;
	ENCODER_SS_0 = 1;
	ENCODER_SS_1_ddr = 1;
	ENCODER_SS_1 = 1;

	int cnt0 = 0;
	int cnt1 = 0;
	printf("TEST \n\r");
	resetEncoder(0);
	resetEncoder(1);
	while(1) {
		_delay_ms(1000);
		cnt0 = EncoderCounts(0);
		cnt1 = EncoderCounts(1);
		printf("Encoder 0 :%f degrees \n\r", cnt0*0.19);
		printf("Encoder 1 :%f degrees \n\r", cnt1*0.12);

		//resetEncoder();
	}
}
