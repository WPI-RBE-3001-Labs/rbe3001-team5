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
	//_delay_ms(20);

	//
	ENCODER_SS_0 = 1;
	ENCODER_SS_0 = 0;

	//First byte: command byte
	//input is 4 for 4 bytes of data
	spiTransceive(0b01001000);

	//byte 2 -5 data bytes
	i = (24 << spiTransceive(0)) |
			(16 << spiTransceive(0))|
			(8 << spiTransceive(0))|
			spiTransceive(0);

	ENCODER_SS_0 = 0;
	ENCODER_SS_0 = 1;

	return ((int) i);
}

int GetAccelerationH48C ( int __axis ) {
return 1;
}
