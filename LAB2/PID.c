/*
 * PID.c
 *
 *  Created on: Jan 30, 2017
 *      Author: Matt
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

typedef struct pid{
	int LAST_PROCESS_VALUE;
	int SUM_ERROR;
	float P_FACTOR;
	float I_FACTOR;
	float D_FACTOR;
	int MAX_ERROR;
	int MAX_SUM_ERROR;
};
	struct pid link1;
/**
 * @brief Sets the Kp, Ki, and Kd values for 1 link.
 * @details to set the values, use the following style
 * @code pidConst.Kp = 1.3; @endcode
 * @param link The link you want to set the values for (H or L).
 * @param Kp Proportional value.
 * @param Ki Integral value.
 * @param Kd Derivative value.
 *
 * @todo Create a function to the the PID constants for a given link.
 */
void setConst(char link, float Kp, float Ki, float Kd){


	link1.P_FACTOR = Kp;
	link1.I_FACTOR = Ki;
	link1.D_FACTOR = Kd;
}

/**
 * @brief Calculate the PID value.
 * @param  link Which link to calculate the error for (Use 'U' and 'L').
 * @param setPoint The desired position of the link.
 * @param actPos The current position of the link.
 *
 * @todo Make a function to calculate the PID value for a link.
 */
signed int calcPID(char link, int setPoint, int actPos){

	int velocity = actPos - link1.LAST_PROCESS_VALUE;
	link1.LAST_PROCESS_VALUE = actPos;

	int proportion = setPoint - actPos;
	if(proportion < link1.MAX_ERROR && (proportion + link1.SUM_ERROR) < link1.MAX_SUM_ERROR)
		link1.SUM_ERROR += proportion;

	return (proportion * link1.P_FACTOR) + (velocity * link1.D_FACTOR) + (link1.SUM_ERROR * link1.I_FACTOR);


}

