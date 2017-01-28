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
 * @todo Create the corresponding function to initialize the ADC
 * using the channel parameter.
 */
void initADC(int channel){
	//Power Reduction Register
	PRR0 = 0x00;
	//Enable ADC
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	//set ref voltage and multiplexer port 7
	ADMUX = (1 << REFS0)|(1 << MUX0) | (1 << MUX2);
	//ADC in Free Running mode
	//ADCSRB &= 0b11111000;

}

/**
 * @brief Disables ADC functionality and clears any saved values (globals).
 *
 * @param channel  The ADC channel to disable.
 *
 * @todo Create the corresponding function to clear the last ADC
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
 * @todo Create the corresponding function to obtain the value of the
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
 * @todo Create a way to switch ADC channels if you are using interrupts.
 */
void changeADC(int channel){


}

