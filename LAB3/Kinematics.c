/*
 * Kinematics.c
 *
 *  Created on: Feb 15, 2017
 *      Author: Matias
 */
#include "RBELib/RBELib.h"
#include "main.h"

volatile int offSetlow = 250;
volatile double adctoanglelow = 3.66;

volatile int offSethigh = 250;
volatile double adctoanglehigh = 4.16;


int angleToADCLow(int angle){

	//double offsetadclow = angle + offSetlow ;
	double adclow =  ( angle * adctoanglelow)+ offSetlow;

	return adclow;
}


int angleToADCHigh(int angle){
	// Takes in angle and returns adc value for higher link 0-180
	//double offsetadclow = angle + offSetlow ;
	double adchigh =  (angle * adctoanglehigh)+ offSethigh;

	return adchigh;
}


void updatePIDLink(char link,int setPoint){

switch(link){
case 'H':
	//1000 to 250
	if (FALSE){
		setDAC(2, 0);
		setDAC(3, 0);
	}
	else{
		long pidNum = calcPID('H', setPoint, getADC(3));
		//printf("H \n\r");
		//printf(" ADC: %d,Set: %d",getADC(3),setPoint);
		//printf(" MotorPower: %ld, \n\r",pidNum);
		if (pidNum >= 0){
			setDAC(2, pidNum);
			setDAC(3, 0);
		}
		else{
			setDAC(2,0);
			setDAC(3, -pidNum);
		}
	}
	break;
case 'L':
	//1000 to 250
	if (FALSE){
		setDAC(0, 0);
		setDAC(1, 0);
	}
	else{
		long pidNum = calcPID('L', setPoint, getADC(2));
		//printf("L \n\r");
		//printf(" ADC: %d,Set: %d",getADC(2),setPoint);
		//printf(" MotorPower: %ld, \n\r",pidNum);
		if (pidNum >= 0)		{
			setDAC(0, 0);
			setDAC(1, pidNum);
		}
		else{
			setDAC(0,-pidNum);
			setDAC(1, 0);
		}
	}
	break;
	}
}



