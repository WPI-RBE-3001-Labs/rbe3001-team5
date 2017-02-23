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
//TODO implement this - just analog read and sset the port parameter in the struct
void setupIR(struct IR ir, char port){
	initADC(port);
	ir.port = port;
}

//read IR sensor, return ADC value
//TODO implement this
int getIRValue(char port){
	return 0;
}

//converts and IR ADC value to a distance in millimeters
//TODO
int adcToMillimeters(int adc){
	return 0;
}
