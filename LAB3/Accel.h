/*
 * Accel.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Matias
 */

#ifndef ACCEL_H_
#define ACCEL_H_

unsigned int getAcceleration(int axxis);
void test_accel();
float Val2Volt(float accelValue);
float Volt2Gforce(float accelValue);


#endif /* ACCEL_H_ */
