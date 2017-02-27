/*
 * ir.c
 *
 *  Created on: Feb 22, 2017
 *      Author: Matt
 */

#include "RBELib/RBELib.h"
#include "main.h"

//setup IR function
//setups up the analog IR values
void setupIR(struct IR ir, char port){
	initADC(port);
	ir.port = port;
}


void sampleIR(struct IR ir1, struct IR ir2){

	//sample IR's
		ir1.adcVal = getIRValue(ir1.port);
		ir2.adcVal = getIRValue(ir2.port);

		//Convert IR's
		ir1.millimeters = adcToMillimeters(ir1.adcVal);
		ir2.millimeters = adcToMillimeters(ir2.adcVal);

		// Print IR Data
		printf(" IR Distance:  ");
		printf(" IR1: %d  \n\r", (int) ir1.millimeters);
		printf(" IR2: %d  \n\r", (int) ir2.millimeters);

}

//read IR sensor, return ADC value
int getIRValue(char port){
	return getADC(port);
}

//converts and IR ADC value to a distance in millimeters
//TODO determine the value of these #defines
#define IR_SCALAR 5 // the scale from IR ticks to millimeters
#define IR_TICKS_OFFEST 300 //the offset for the number of IR ticks
int adcToMillimeters(int adc){
	return IR_SCALAR * (adc - IR_TICKS_OFFEST);
}
