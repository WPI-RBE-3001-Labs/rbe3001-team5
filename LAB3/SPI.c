/*
 * SPI.c
 *
 *  Created on: Jan 28, 2017
 *      Author: Matt
 */
#include "RBELib/RBELib.h"
#include "main.h"

/**
 * @brief Initializes the SPI bus for communication with all of your
 * SPI devices.
 *
 * Create the function that will allow you to initialize the SPI
 * in a mode compatible with all devices.  Do not forget to deassert all
 * of your SS lines!
 */
void initSPI(){
	DDRDbits._P7 = OUTPUT;
	PORTDbits._P7 = HIGH;
	SPI_MOSI_DDR = OUTPUT;
	SPI_MISO_DDR = INPUT;
	SPI_SCK_DDR = OUTPUT;
	SPI_MASTER_SS = HIGH;
	DAC_SS_ddr = OUTPUT;
	//SPI Control Register 0
	SPCR = (0 << SPIE)| // Enable SPI interrupt
			(1 << SPE)| //enable SPI 0
			(0 << DORD)| //MSB is transmitted first
			(1 << MSTR)| //This is the Master device
			(0 << CPOL)| //set SCK idle to low
			(0 << CPHA)| //sample at rising edge
			(1 << SPR1)| //set frequency to fosc/4
			(1 << SPR0); //set frequency to fosc/4
			//Note, the DAC can take up to 50MHz so this is OK

	//SPI Status Register 0
	SPSR = (0 << SPIF)| //Don't want to set interrupts
			(0 << WCOL)|	//don't need write collision flag
			(0 << SPI2X); //don't need double speed
}

/**
 * @brief Send and receive a byte out of the MOSI line.
 *
 * Please note that even if you do not want to receive any data back
 * from a SPI device, the SPI standard requires you still receive something
 * back even if it is junk data.
 *
 * @param data The byte to send down the SPI bus.
 * @return value The byte shifted in during transmit
 *
 * Make a function that will send a byte of data through the SPI
 * and return whatever was sent back.
 */
unsigned char spiTransceive(BYTE data){
	//Start Transmission
	SPDR = data;
	//wait for transmission to finish
	while(!(SPSR & (1<<SPIF)));

	//TODO see if the incoming is in the same register
	return SPDR;
}


