/*
 * main.h
 *
 *  Created on: Jan 21, 2017
 *      Author: ewillcox
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "RBELib/RBELib.h" //RBELib
#include "function_prototypes.h"
#include "avr/io.h"
//#include "globals.h"
//#include "timers.h"

void logPot();
void logPot2();
void sawtoothWave();
void readCurrentSense();
void PIDarmControl();

extern struct Potentiometer{
	int ADCVal; //the value from 0-1023
	float voltage; //the analog voltage from 0 to 5V
	float angle; //the angle of the potentiometer form 0-270 degrees
};

#endif /* MAIN_H_ */
