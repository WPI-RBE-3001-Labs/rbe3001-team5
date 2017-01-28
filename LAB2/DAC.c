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
 * @todo Make the function that is able to set the DAC to a given value
 * from 0 - 4095.
 */
void setDAC(int DACn, int SPIVal){
	//SPI Control Register 0
	SPCR = (0 << SPIE)| //Disable SPI interrupt
			(1 << SPE)| //enable SPI 0
			(0 << DORD)| //MSB is transmitted first
			(1 << MSTR)| //This is the Master device
			(0 << CPOL)| //set SCK idle to low
			(0 << CPHA)| //sample at rising edge
			//TODO check the frequency with the DAC chip
			(0 << SPR1)| //set frequency to fosc/4
			(0 << SPR0); //set frequency to fosc/4

	//SPI Status Register 0
	SPSR = (0 << SPIF)| //Don't want to set interrupts
		   (0 << WCOL)|	//don't need write collision flag
		   (0 << SPI2X); //don't need double speed

	//TODO set enable pin for DAC

	//TODO make sure that I am send data to the correct registe
	//SPI Data Register 0
	//SPDR

	//TODO check if it was MSB or LSB first
	//Start Transmission
	//MSB first
	SPDR = (SPIVal >> 8);
	//wait for transmission to finish
	while(!(SPSR & (1<<SPIF)));

	//LSB transmit
	SPDR = (SPIVal & 8);
	while(!(SPSR & (1<<SPIF)));
}


