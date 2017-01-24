/*
 * globals.h
 *
 *  Created on: Jan 21, 2017
 *      Author: joest
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

typedef struct {
	double timeCount;
	double blinkDelay;
	volatile unsigned char state;
} Globals;

extern Globals globals; // declaration

void initGlobals();

#endif /* GLOBALS_H_ */
