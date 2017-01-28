/*
 * DAC.c
 *
 *  Created on: Jan 28, 2017
 *      Author: Matt
 */

#include "RBELib/RBELib.h"
#include "main.h"

/**
 * @brief Set the DAC to the given value on the chosen channel.
 * @param  DACn The channel that you want to set.
 * @param SPIVal The value you want to set it to.
 *
 * Make the function that is able to set the DAC to a given value
 * from 0 - 4095.
 *
 * http://cds.linear.com/docs/en/datasheet/2634fc.pdf
 */
void setDAC(int DACn, int SPIVal){
	//Set enable pin for DAC
	DDRDbits._P4 = OUTPUT; //Set D4 GPIO as output
	PINDbits._P4 = 0; //pull to 0 to enable chip transmission

	//load in 32 bits of Data:
	//4 bit command - write to input register n
	char MSBDAC = 0x0;
	//4 bit DAC address - just use DACn as the LS bits
	//send first byte through SPI to DAC:
	spiTransceive((4 << MSBDAC) | DACn);

	//Transmit:
	//we want 12 data bits:
	spiTransceive((char)(SPIVal >> 4)); //top 8 of 12 bits
	spiTransceive((char)(8 << SPIVal));
	//second half of this byte is ignored by chip

	//Turn off DAC Transmission:
	PINDbits._P4 = 1;
}


