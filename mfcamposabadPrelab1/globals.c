/*
 * globals.c
 *
 *  Created on: Jan 21, 2017
 *      Author: joest
 */

#include "globals.h"
	Globals globals;

void initGlobals() {
	globals.timeCount = 0;
	globals.blinkDelay = 100;
	globals.state = 0;
}
