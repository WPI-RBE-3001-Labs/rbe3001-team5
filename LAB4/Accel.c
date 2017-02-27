/*
 * Accel.c
 *
 *  Created on: Feb 13, 2017
 *      Author: Matias
 */
#include "RBELib/RBELib.h"
#include <avr/io.h>
#include <math.h>
#include "Accel.h"
#include "main.h"

float vref = 5;
float GfCnv = 0.22;
float Cnt2Mv = 0.80586;

unsigned int getAcceleration(int channel){
// x axxis = 0
// y axxis = 1
// z axxis = 2

//Reads 12bit data from the H48C Accelerometer
unsigned int ret = 0;
unsigned int temp_1;
unsigned int temp_2;
char axxis = (channel << 6);


PORTD &= ~(1 << PIN7);

spiTransceive(0b00000110);
temp_1 = spiTransceive(axxis);
temp_1 = (temp_1 <<8);
temp_2 = spiTransceive(0x00);

ret = temp_1 | temp_2;

PORTD |= (1 << PIN7);

return ret;


}

void test_accel(int sample_flag){
float xval = 0;
float yval = 0;
float zval = 0;

float xgs = 0;
float ygs = 0;
float zgs = 0;

float xvolt = 0;
float yvolt = 0;
float zvolt = 0;

xval = getAcceleration(0);
yval = getAcceleration(1);
zval = getAcceleration(2);

xvolt = Val2Volt(xval);
yvolt = Val2Volt(yval);
zvolt = Val2Volt(zval);

xgs = Volt2Gforce(xvolt);
ygs = Volt2Gforce(yvolt);
zgs = Volt2Gforce(zvolt);




printf("X Gs: %f ; \n\r",(double)xgs);
printf("Y Gs: %f ; \n\r",(double) ygs);
printf("Z Gs: %f ; \n\r", (double)zgs);

}


float Val2Volt( float accelValue) {
	float mv = 0;
	mv = pow(accelValue, Cnt2Mv);
	//printf("milliVolts: %f \n\r", (double)mv);
	return mv;
}

float Volt2Gforce(float accelValue) {
	float gForce = 0;

	if (accelValue >= vref) {
		gForce = pow(accelValue - vref, GfCnv);
	} else {
		gForce = -pow(vref - accelValue, GfCnv);

	}
	//printf("GForce: %f\n\r",(double)gForce);
	return gForce;
}



