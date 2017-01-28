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
			(0 << SPR1)| //set frequency to fosc/4
			(0 << SPR0); //set frequency to fosc/4

	//SPI Status Register 0
	//SPSR0

	//SPI Data Register 0
	//SPDR0



}


