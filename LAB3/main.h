<<<<<<< HEAD
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


extern struct acceleration{
	int xTicks;
	int yTicks;
	int zTicks;
	float xAcc;
	float yAcc;
	float zAcc;
}acc;


#endif /* MAIN_H_ */
=======
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
#include "Accel.h"
#include "Kinematics.h"


void logPot();
void logPot2();
void sawtoothWave();
void driveMotors();
void readCurrentSense();
void PIDarmControl();
void ENCODER();
void button_move();

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
>>>>>>> 15dff2f92fe738ae57b2acaf38f964bd09b63238
