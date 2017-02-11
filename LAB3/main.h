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
//#include "globals.h"
//#include "timers.h"

void readEncoders();
void readAccelerometer();

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

typedef union accAxis{
	int ticks;
	float acc;
}xAxis, yAxis, zAxis;

typedef struct acceleration{
	union xAxis;
	union yAxis;
	union zAxis;
}acc;


#endif /* MAIN_H_ */
