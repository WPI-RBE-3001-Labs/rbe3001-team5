/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */

#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"

unsigned char interruptToggle = 0;
unsigned char armPos = HOME;
volatile unsigned long systemTime = 0;
volatile unsigned long timerCounter;
volatile unsigned long intTime;
volatile double timerCountVal = 9; //9 for ms system time
volatile double timerCountVal2 = 100;
volatile int count = 0;
volatile int sample_flag = 0;
long int count2 = 0;
int maxCount = 1000;

int main(){
	//Common setup here:
	//	nukeWDT(); //Disable Watchdog Timer

	sei(); // Enable Global Interrupts
	initRBELib();//Enable printf() and setServo()
	debugUSARTInit(115200);	//initialize USART 1 for transmission to Putty
	initTimer(0,0,0);//Start Timer0 in Normal Mode
	initSPI();//start up the SPI

	struct IR ir1 = {IR_PORT1,0,0};
	struct IR ir2 = {IR_PORT2,0,0};
	struct Potentiometer upperJoint = {0,0,0};
	struct Potentiometer lowerJoint = {0,0,0};

	setupIR(ir1, 3);
	setupIR(ir2, 4);

	setConst('H',25.0,0.1, -0.1);
	setConst('L',25.0,0.1, -0.1);

	DAC_SS = 1;//disable DAC for doing potentiometer stuff

	setServo(1, 200);
	setServo(0, 200);

	while(1){
		if(interruptToggle){
			sampleIR(ir1, ir2);
			samplePot(upperJoint, lowerJoint);

			//State machine for arm positions
			switch(armPos){
			case HOME:
				//move arm to home

				break;
			case WAIT:
				//move arm to wait

				break;
			case GRASP:
				//grasp block

				break;
			case TORQUE_SENSE:
				//torque sense

				break;
			case DROP_LIGHT:
				//move arm to position to drop light block

				break;
			case DROP_HEAVY:
				//move arm to position to drop heavy block

				break;
			default:
				//This is bad
				return 1;
				break;
			} //end switch(armPos)

			interruptToggle = 0;
		}// end if

		//do nothing between interrupts

	} // end while(1)

	return 1;
} /* End main */

////TODO finish 100 Hz Timer ISR
//unsigned int beltTimer = 0; //timing of picking up block
//ISR(TIMER0_OVF_vect){
//	interruptToggle = 1;
//	if (beltTimer == IR_TIMER){
//		//pick up block
//	}
//}

//TODO Finish timer implementation
ISR(TIMER0_OVF_vect) {//Sets sampling Rate and Updates PID
		// Sets PID at 100hz
	count++;
	count2++;

	if (count >= maxCount) {
		sample_flag = 1;
		count = 0;
	}


	timerCounter++;
	//counts to make 1ms timer
	if (timerCounter >=timerCountVal){

		timerCounter=0;
		systemTime++;
		intTime++;
		interruptToggle = 1;


	if (intTime>=10)
		{
			interruptToggle = 1;
			//update PID

			intTime = 0;

		}
	}

}
