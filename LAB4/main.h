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

//Macros for arm dimensions:
//TODO make sure to get actual values
#define D_BELT 8 //distance to the belt in inches
#define W_BELT 5 //width of belt in inches

//Y distance from the optimal position to pick up the block
//to the Y position of the first joint
#define L0 3
#define L1 6 //length of first moving link joint-joint
#define L2 6 //length of second link joint to end of arm tooling origin

//The number of 100th's of a second it takes the block to reach the arm
//from the time the first IR sensor sees the block
//TODO calculate this
#define IR_TIMER 50

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


extern struct acceleration{
	int xTicks;
	int yTicks;
	int zTicks;
	float xAcc;
	float yAcc;
	float zAcc;
}acc;

extern struct IR{
	char port;
	int adcVal;
	int millimeters;
}ir1, ir2;

#endif /* MAIN_H_ */
