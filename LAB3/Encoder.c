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


	ENCODER_SS_0 = 0;


	spiTransceive(0x60);


	i = (spiTransceive(0) << 24) |
		(spiTransceive(0) << 16)|
		(spiTransceive(0) << 8 )|
	    spiTransceive(0);


	ENCODER_SS_0 = 1;

	return i;





}

void initEncoder() {

	ENCODER_SS_0 = 0;
	spiTransceive(0x88); // Write to MDR0
	//spiTransceive(0x03);
	ENCODER_SS_0 = 1;
}

void resetEncoder() {

	ENCODER_SS_0 = 0;
	spiTransceive(0x20); //index_rest_CNTR
	ENCODER_SS_0 = 1;
}

int GetAccelerationH48C ( int __axis ) {
return 1;
}
