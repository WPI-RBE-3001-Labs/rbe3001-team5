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
#include <math.h>
#include "Encoder.h"
//#include "globals.h"
//#include "timers.h"

void logPot();
void logPot2();
void sawtoothWave();
void driveMotors();
void readCurrentSense();
void PIDarmControl();
void ENCODER();

extern struct Potentiometer{
	int ADCVal; //the value from 0-1023
	int voltage; //the analog voltage from 0 to 5V
	int angle; //the angle of the potentiometer form 0-270 degrees
};

extern struct Current{
	int ADCVal;
	float voltage;
	float current;
};

extern struct coord{
	float x;
	float y;
};

#endif /* MAIN_H_ */
