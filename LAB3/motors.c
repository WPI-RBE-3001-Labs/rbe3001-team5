/*
 * motors.c
 *
 *  Created on: Jan 28, 2017
 *      Author: Matt
 */
#include "main.h"
#include <math.h>
#include "RBELib/motors.h"

/**
 * @brief Helper function to stop the motors on the arm.
 *
 * @todo Create way to stop the motors using the DAC.
 */
void stopMotors(){

}

/**
 * @brief Drive the arm to a desired angle
 *
 * @param lowerTheta The desired angle for the lower link.
 * @param upperTheta The desired angle for the upper link.
 *
 * @todo Make a way to drive the links to a desired angle.
 */
#define l0 6
#define l1 6
#define l2 6

void gotoAngles(int lowerTheta, int upperTheta){
//	struct coord ret = {0,0};
//	float c1 = cos(lowerTheta);
//	float c2 = cos(upperTheta);
//	float s1 = sin(lowerTheta);
//	float s2 = sin(upperTheta);
//	ret.x = (-1) * l1 * (c1*s2 - s1*c2) + l2 * s2;
//	ret.y = l1 * (c1*c2 - s1*s2) + l2*c2 + l0;

	//TODO drive motor to positions
}

/**
 * @brief Drive the end effector of the arm to a desired X and Y position in the workspace.
 *
 * @param x The desired x position for the end effector.
 * @param y The desired y position for the end effector.
 *
 * @todo Use kinematic equations to move the end effector to the desired position.
 */
void gotoXY(int x, int y){

}

/**
 * @brief Drive a link (upper or lower) in a desired direction.
 *
 * @param link Which link to control.
 * @param dir Which way to drive the link.
 *
 * @todo Create a way to drive either link in any direction.
 */
void driveLink(int link, int dir){
	//first determine link
	if(!link){
		//link 0
		//second determine the polarity
		if (dir >= 0){
			//power A, B to zero
			setDAC(0, 0);
			setDAC(1, dir);
		}else{
			//power B, A to zero
			setDAC(1, 0);
			setDAC(0, dir * -1);
		}
	}else{
		//link 1
		//second determine the polarity
		if (dir >= 0){
			//power A, B to zero
			setDAC(3, 0);
			setDAC(2, dir);
		}else{
			//power B, A to zero
			setDAC(2, 0);
			setDAC(3, dir);
		}
	}

}

/**
 * @brief Drive the arm to a "home" position using the potentiometers.  This
 * should be called before using the encoders and just goes to a default position.
 * Once this has been called once, you can initialize/clear the encoders.
 *
 * @todo Drive the arm to a known position using the potentiometers.
 */
void homePos(){

}

