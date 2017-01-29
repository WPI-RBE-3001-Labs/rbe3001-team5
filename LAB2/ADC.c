/*
 * ADC.c
 *
 *  Created on: Jan 23, 2017
 *      Author: Group 5
 */

#include "RBELib/RBELib.h"
#include "main.h"

/**
 * @brief Initializes the ADC and make one channel active.
 * You can choose to use either interrupts or polling to read
 * the desired channel.
 *
 * @param channel The ADC channel to initialize.
 *
 * Create the corresponding function to initialize the ADC
 * using the channel parameter.
 */
void initADC(int channel){
	//Power Reduction Register
	PRR0 = 0x00;


	//Enable ADC
	// ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	ADCSRA =     (1 << ADEN) |
				 (0 << ADSC) |
				 (0 << ADATE)|
				 (0 << ADIF) |
				 (0 << ADIE) |
				 (1 << ADPS2)|
				 (1 << ADPS1)|
				 (1 << ADPS0);
	//set ref voltage and multiplexer port 7



	//Info can be found on page 319 of ATmega644P data sheet
	ADMUX =     (0 << REFS1)| // Table 25-3
				(1 << REFS0)| // Table 25-3
				(1 << ADLAR)| // 1 to left Adjust data, 0 to right Adjust data
				(0 << MUX4) | // Table 25-4
				(0 << MUX3) | // Table 25-4
				(0 << MUX2) | // Table 25-4
				(0 << MUX1) | // Table 25-4
				(0 << MUX0);  // Table 25-4
	if(channel <= 7 && channel >= 0) // select ADC channel, overwrites MUX, MUX2, MUX1 if valid channel selection
		ADMUX |= channel;
	//ADC in Free Mode
	//ADCSRB &= 0b11111000

}

/**
 * @brief Disables ADC functionality and clears any saved values (globals).
 *
 * @param channel  The ADC channel to disable.
 *
 * Create the corresponding function to clear the last ADC
 * calculation register and disconnect the input to the ADC if desired.
 */
void clearADC(int channel){
	//clear ADC register
	ADCSRA = 0x00;
	//disconnect input
}

/**
 * @brief Run a conversion on and get the analog value from one ADC
 * channel if using polling.
 *
 * @param channel  The ADC channel to run a conversion on.
 * @return adcVal The 8-10 bit value returned by the ADC
 * conversion.  The precision depends on your settings and
 * how much accuracy you desire.
 *
 * Create the corresponding function to obtain the value of the
 * last calculation if you are using polling.
 */
unsigned short getADC(int channel){
	unsigned short ADCVal = 0;
	//start conversion
	ADCSRA |= (1 << ADSC);
	//wait for conversion:
	while(ADCSRA & (1<<ADSC)){

	}
	//get it in there
	ADCVal = ADCL;
	ADCVal += (ADCH<<8);
	return ADCVal;
}

/**
 * @brief Change the channel the ADC is sampling if using interrupts.
 *
 * @param channel  The ADC channel to switch to.
 *
 * Create a way to switch ADC channels if you are using interrupts.
 */
void changeADC(int channel){
	if(channel <= 7 && channel >= 0)
		// select ADC channel, overwrites MUX0, MUX2, MUX1 if valid channel selection
		ADMUX |= channel;
}

