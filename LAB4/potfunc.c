/*
 * potfunc.c
 *
 *  Created on: Feb 27, 2017
 *      Author: mfcamposabad
 */

#include "RBELib/RBELib.h"
#include "main.h"

#define Arm0ADCPort 2
#define Arm1ADCPort 3

struct Potentiometer upperJoint = {0,0,0};
struct Potentiometer lowerJoint = {0,0,0};


void samplePot(struct Potentiometer upperJoint, struct Potentiometer lowerjoint){
			//read pot value for upper and lower joints
			upperJoint.ADCVal = getADC(Arm0ADCPort);
			lowerJoint.ADCVal = getADC(Arm1ADCPort);

			//Calculate Angle and Voltage Upper Joint
			upperJoint.voltage = potVolts(upperJoint.ADCVal);
			upperJoint.angle = potAngle(upperJoint.ADCVal);

			//Calculate Angle and Voltage Lower Joint
			lowerJoint.voltage = potVolts(lowerJoint.ADCVal);
			lowerJoint.angle = potAngle(lowerJoint.ADCVal);

			printf(" Upper Joint Angle %d \n\r", (int) upperJoint.angle);

			printf(" Lower Joint Angle: %d \n\r", (int) lowerJoint.angle);

}



