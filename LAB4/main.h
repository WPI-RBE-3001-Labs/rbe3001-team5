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

#define IR_PORT1 3 //IR port for the first sensor
#define IR_PORT2 4 //IR port for the second sensor

//macros arm switch statements
#define HOME 0
#define WAIT 1
#define GRASP 2
#define TORQUE_SENSE 3
#define DROP_LIGHT 4
#define DROP_HEAVY 5

void readEncoders();
void readAccelerometer();
void setupIR(char port);
int getIRValue(char port);
int adcToMillimeters(int adc);

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
};

extern struct pid{
	int LAST_PROCESS_VALUE;
	int SUM_ERROR;
	float P_FACTOR;
	float I_FACTOR;
	float D_FACTOR;
	int MAX_ERROR;
	int MAX_SUM_ERROR;
};

#endif /* MAIN_H_ */
