<<<<<<< HEAD
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

=======
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
 * Initializes the ADC using the channel parameter.
 *
 */
void initADC(int channel){
	//Bits 7 - 6: Coupling capacitor at AREF
	//Bit 5: No left adjustment
	//Bits 4 - 0: Channel selection (0 - 7 for single ended)
	ADMUX = (0x40) | channel;

	//Bit 7: Enable ADC
	//Bit 6: Starts conversions
	//Bit 5: Auto trigger enable
	//Bit 4: Interrupt flag telling conversions are complete
	//Bit 3: Interrupt enable
	//Bits 2 - 0: Prescaler of 128 (18432000 / 128 = 144kHz)
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescalar to 128 - 125KHz sample rate @ 16MHz

	ADCSRA |= (1 << ADEN);  // Enable ADC
	ADCSRA |= (1 << ADSC);  // Start A2D Conversions
	//ADCSRA = 0xFF;

	//Bit 7: Reserved
	//Bit 6: Analog Comparator Multiplexer Enable (ACME) - leave at 1
	//Bit 5 - 3: Reserved
	//Bit 2 - 0: Free running mode
	ADCSRB = 0x40;

	//Testing with port 7
	DDRA = 0x00;
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
	//untested, BAsically never needed
	ADMUX = (0x40) & channel;
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
	// select the corresponding channel 0~7
	// ANDing with '7' will always keep the value
	// of 'channel' between 0 and 7
	channel &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|channel;     // clears the bottom 3 bits before ORing

	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);

	// wait for conversion to complete
	// till then, run loop continuously
	while(!(ADCSRA & (1<<ADIF)));
	//Clear ADIF by writing one to it
	ADCSRA|=(1<<ADIF);

	return (ADC);
}

/**
 * @brief Change the channel the ADC is sampling if using interrupts.
 *
 * @param channel  The ADC channel to switch to.
 *
 * Create a way to switch ADC channels if you are using interrupts.
 */
void changeADC(int channel){
	//Change the channel using the same setting from initADC()
	ADMUX = (0x40) | channel;
}

>>>>>>> c647a692f4acbf2a6ff0ec4a7c58ccf19f03b9be
