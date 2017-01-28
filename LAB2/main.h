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
#include "adc.h"
#include "avr/io.h"
//#include "globals.h"
//#include "timers.h"

void calibratePot();
void logPot();
void sawtoothWave();
void readCurrentSense();
void PIDarmControl();

#endif /* MAIN_H_ */
