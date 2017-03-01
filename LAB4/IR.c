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
    	//printf(" IR1: %d  \n\r", (int) ir1.millimeters);
		printf(" IR2: %d  \n\r", (int) ir2.millimeters);


}

//read IR sensor, return ADC value
int getIRValue(char port){
	int irADCval = getADC(port);
	int irmm = adcToMillimeters(irADCval);
	return irmm;
}

//converts and IR ADC value to a distance in millimeters
#define IR_SCALAR 0.3546 // the scale from IR ticks to millimeters
#define IR_TICKS_OFFEST 289 //the offset for the number of IR ticks
int adcToMillimeters(int adc){
	return  ((int)IR_TICKS_OFFEST - ((float)(IR_SCALAR * adc)));
}
