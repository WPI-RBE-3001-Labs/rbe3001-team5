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
