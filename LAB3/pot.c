/*
 * pot.c
 *
 *  Created on: Jan 29, 2017
 *      Author: Matt
 */

#include "RBELib/RBELib.h"
#include "main.h"

#define TICKS_TO_MILLIVOLTS 2.169 //
#define TICKS_TO_DEGREE 4.411 //

/**
 * @brief Find the angle of the given potentiometer.
 * @param  pot The pot to check.
 * @return angle Angle of the potentiometer.
 *
 * Calculate the angle using the ADC reading.
 */
#define ANGLE_OFFSET 243
int potAngle(int pot){
	return (int)((pot - ANGLE_OFFSET) / TICKS_TO_DEGREE);
}

/**
 * @brief Find the voltage value of the given potentiometer.
 * @param  pot The pot to get the value of.
 * @return volts Voltage of  potentiometer.
 *
 *Convert the ADC value into a voltage in mV (so no floats needed).
 */

#define MILLIVOLT_OFFSET 113
int potVolts(int pot){
	return (int)(pot * TICKS_TO_MILLIVOLTS + MILLIVOLT_OFFSET);
}
