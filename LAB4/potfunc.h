/*
 * potfunc.h
 *
 *  Created on: Feb 27, 2017
 *      Author: mfcamposabad
 */

#ifndef POTFUNC_H_
#define POTFUNC_H_

extern struct Potentiometer{
	int ADCVal; //the value from 0-1023
	int voltage; //the analog voltage from 0 to 5V
	int angle; //the angle of the potentiometer form 0-270 degrees
};

int angleToPot(char link, double angle);
void samplePot(struct Potentiometer upperJoint, struct Potentiometer lowerjoint);


#endif /* POTFUNC_H_ */
