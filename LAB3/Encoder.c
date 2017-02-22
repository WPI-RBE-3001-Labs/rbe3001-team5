/*
 * Encoder.c
 *
 *  Created on: Feb 13, 2017
 *      Author: crbriggs
 */
#include "RBELib/RBELib.h"
#include "main.h"

int EncoderCounts( int __chan ) {

	long i = 0;
	switch(__chan) {
		case 0:

		ENCODER_SS_0 = 0;
		spiTransceive(0x60);
		i = (spiTransceive(0) << 24) |
			(spiTransceive(0) << 16)|
			(spiTransceive(0) << 8 )|
			spiTransceive(0);
		ENCODER_SS_0 = 1;
		return i;

		case 1:
		ENCODER_SS_1 = 0;
		spiTransceive(0x60);
		i = (spiTransceive(0) << 24) |
			(spiTransceive(0) << 16)|
			(spiTransceive(0) << 8 )|
			spiTransceive(0);
		ENCODER_SS_1 = 1;
		return i;
	}
	return 0;
}

void initEncoder() {

	ENCODER_SS_0 = 0;
	spiTransceive(0x88); // Write to MDR0
	//spiTransceive(0x03);
	ENCODER_SS_0 = 1;

	ENCODER_SS_1 = 0;
	spiTransceive(0x88); // Write to MDR0
	//spiTransceive(0x03);
	ENCODER_SS_1 = 1;
}

void resetEncoder(int __chan) {

	switch(__chan) {
		case 0:
		ENCODER_SS_0 = 0;
		spiTransceive(0x20); //index_rest_CNTR
		ENCODER_SS_0 = 1;
		break;
		case 1:
		ENCODER_SS_1 = 0;
		spiTransceive(0x20); //index_rest_CNTR
		ENCODER_SS_1 = 1;
		break;
	}
}

int GetAccelerationH48C ( int __axis ) {
return 1;
}

//sei(); // Enable Global Interrupts
//
//	initRBELib();//Enable printf() and setServo()
//
//	//initialize USART 1 for transmission to Putty
//	debugUSARTInit(115200);
//
//	ENCODER_SS_0_ddr = 1;
//	ENCODER_SS_0 = 1;
//	ENCODER_SS_1_ddr = 1;
//	ENCODER_SS_1 = 1;
//	//initTimer(0,0,0);
//
//	//TODO Make sure that the SS is ON/OFF properly
//	//disable SS for doing potentiometer stuff
//
//	initSPI();
//	initEncoder();
//	//TODO Interchange the correct part of the lab
//
//	int cnt0 = 0;
//	int cnt1 = 0;
//	printf("TEST \n\r");
//	resetEncoder(0);
//	resetEncoder(1);
//	while(1) {
//		_delay_ms(1000);
//		cnt0 = EncoderCounts(0);
//		cnt1 = EncoderCounts(1);
//		printf("Encoder 0 :%f degrees \n\r", cnt0*0.19);
//		printf("Encoder 1 :%f degrees \n\r", cnt1*0.12);
//
//		//resetEncoder();
//	}
