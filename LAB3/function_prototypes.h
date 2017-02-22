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
void part1();
void part2();
void part3();
void part4();
void nukeWDT();
void part5();
void part6();
void part7();
//struct coord forwardKinematics(int lowerTheta, int upperTheta);

#endif /* PORTB_H_ */
