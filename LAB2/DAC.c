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
 */
void setDAC(int DACn, int SPIVal){
	//TODO set enable pin for DAC

	//TODO make sure that I am send data to the correct registe
	//SPI Data Register 0
	//SPDR


}


