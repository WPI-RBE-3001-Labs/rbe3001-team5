/*
 * pot.c
 *
 *  Created on: Jan 29, 2017
 *      Author: Matt
 */

#include "RBELib/RBELib.h"
#include "main.h"

/**
 * @brief Find the angle of the given potentiometer.
 * @param  pot The pot to check.
 * @return angle Angle of the potentiometer.
 *
 * @todo Calculate the angle using the ADC reading.
 */
#define TICKS_TO_VOLTS 200 //todo get the actual value
#define VOLTS_TO_ANGLE 0.25 //todo get actual value
#define TICKS_TO_ANGLE (VOLTS_TO_ANGLE * TICKS_TO_VOLTS 200)

int potAngle(int pot){
	return 0;
}

/**
 * @brief Find the voltage value of the given potentiometer.
 * @param  pot The pot to get the value of.
 * @return volts Voltage of  potentiometer.
 *
 * @todo Convert the ADC value into a voltage in mV (so no floats needed).
 */


int potVolts(int pot){
	return 0;
}
