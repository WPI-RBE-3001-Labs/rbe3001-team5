/*
 * portb.h
 *
 *  Created on: Jan 21, 2017
 *      Author: ewillcox
 */

#ifndef PORTB_H_
#define PORTB_H_

#include "main.h"
#define PORT_OUTPUT 0xFF
void initPB();
void initPA();
void blinkAll(double timeDelay);
int button_state();
void part5();
void part6();
void part7();

#endif /* PORTB_H_ */
