/*
 * Kinematics.h
 *
 *  Created on: Feb 15, 2017
 *      Author: Matias
 */

#ifndef KINEMATICS_H_
#define KINEMATICS_H_

int angleToADCLow(int angle);
int angleToADCHigh(int angle);
void updatePIDLink(char link,int setPoint);


#endif /* KINEMATICS_H_ */
