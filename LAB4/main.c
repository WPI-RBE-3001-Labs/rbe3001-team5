/*
 * main.c
 *	Group 5 LAB 2
 *  Created on: FEB 1st, 2017
 */


#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"
#include "stdlib.h"

unsigned char interruptToggle = 0;
unsigned char armPos = HOME;
volatile unsigned long systemTime = 0;
volatile unsigned long timerCounter;
volatile unsigned long intTime;
volatile double timerCountVal = 9; //9 for ms system time
volatile double timerCountVal2 = 100;
volatile double grasptime = 0;
volatile double grasptime2 = 0;
volatile double graspval = 460;
volatile double graspval2 = 550;
volatile double graspval3 = 575;
volatile double massval = 700;
volatile int count = 0;
volatile int sample_flag = 0;
volatile int WAIT_timer = 0;
volatile int grasp_time = 0;
volatile int GOGETIT = 0;
volatile int GOGETIT2 = 0;
volatile int GOGETIT3 = 0;
volatile int MASSIT = 0;

long int count2 = 0;
int maxCount = 1000;
int hAngle = 0;
int lAngle = 0;

#define Arm0ADCPort 2
#define Arm1ADCPort 3

char inchar; //character for receiving serial data
unsigned long lowADC = 0;
unsigned long highADC = 0;
unsigned long pot1Ang=0;
unsigned long potAngInt;
unsigned long mV=0;
int potHZero = 645;
int potLZero = 580;

volatile unsigned long timerCounter;
volatile unsigned long intTime;

volatile long highLinkErr;
volatile long lowLinkErr;


volatile int buttonState = 7;
volatile int highSetP;
volatile int lowSetP;

struct IR ir1 = {IR_PORT1,0,0};
struct IR ir2 = {IR_PORT2,0,0};


volatile int offSetlow = 250;
volatile double adctoanglelow = 3.66;

volatile int offSethigh = 250;
volatile double adctoanglehigh = 4.16;

float high_treshold = 150;
float low_treshold = 250;
float treshold = 350;
float current = 0;

int treshold_distance = 150;
int distance = 0;

int grasp_flag = 0;
volatile int distance2block;

int main(){
	//Common setup here:
	//	nukeWDT(); //Disable Watchdog Timer

	initRBELib();//Enable printf() and setServo()
	debugUSARTInit(115200);	//initialize USART 1 for transmission to Putty


	struct IR ir1 = {IR_PORT1,0,0};
	struct IR ir2 = {IR_PORT2,0,0};
	setupIR(ir1, 3);
	setupIR(ir2, 4);

	initSPI();//start up the SPI

	struct Potentiometer upperJoint = {0,0,0};
	struct Potentiometer lowerJoint = {0,0,0};


	initTimer(0,0,0);//Start Timer0 in Normal Mode

	  setConst('H',20.0,0.01,0.1);
	  setConst('L',20.0,0.01,0.1);

	DAC_SS = 1;//disable DAC for doing potentiometer stuff

	//setServo(1, 200);
	//setServo(0, 200);

	sei(); // Enable Global Interrupts

	printf("InitComplete");
	setServo(5,10);

	double xyangleh = 0;
	double xyanglel = 0;

	while(1){
		if(sample_flag){
			//State machine for arm positions
			switch(armPos){
			case HOME:
				printf("State: HOME \n\r");
				printf("Switch S0 to Start \n\r");
				lowSetP=angleToADCLow(45);
				highSetP=angleToADCHigh(45);
				setServo(0, 0);
				cli();


				if(!PINBbits._P0){
				//START ASSEMBLY LINE
				armPos = WAIT;
				sei();
				}

				break;

			case WAIT://Waits for the block to get to Griping position
				printf("State: WAIT \n\r");
				distance2block = getIRValue(4);
				printf("%d", distance2block);
				if(distance2block <= treshold_distance){
					armPos = GRASP;
			   }
				else{

					lowSetP=angleToADCLow(90);
					highSetP=angleToADCHigh(0);
				}

				break;
			case GRASP: //grasp block
				printf("GRASP \n\r");
				grasp_flag = 1;
				int xDist = D_BELT  - distance2block + 170;
				xyangleh = getLowerAngle(xDist, 20);
				xyanglel = getUpperAngle(xDist, 20);
//				printf("X distance: %d  ", xDist);
//				printf("H Angle: %f  ", (double)xyangleh);
//				printf("L Angle: %f  ", (double)xyanglel);
				if(!GOGETIT){
				lowSetP=angleToADCLow(35);
				highSetP=angleToADCHigh(35);

				}
				else if(!GOGETIT2){
				lowSetP=angleToADCLow(12);
				highSetP=angleToADCHigh(15);

				}
				else if (!GOGETIT3)
				setServo(0, 180);

				else
				armPos = WHICH_MASS;

				break;
			case WHICH_MASS:
				//torque sense
				printf("WHICH_MASS \n\r");
				lowSetP=angleToADCLow(45);
				highSetP=angleToADCHigh(45);
				current = getCurrent('H');
				printf("Current: %f \n\r", (double)current);
				if(MASSIT){
				if (abs(current)<= 220){
					armPos = DROP_LIGHT;

					printf("Light Weight \n\r");
					}
				else{
					armPos = DROP_HEAVY;

				    printf("Heavy Weight \n\r");
				}

				break;
				}

			case DROP_LIGHT:
				//move arm to position to drop light block
				 printf("DROP_LIGHT \n\r");
					lowSetP=angleToADCLow(90);
					highSetP=angleToADCHigh(0);
				break;

			case DROP_HEAVY:
				//move arm to position to drop heavy block
				 printf("DROP_HEAVY \n\r");
					lowSetP=angleToADCLow(0);
							highSetP=angleToADCHigh(90);
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

ISR(TIMER0_OVF_vect)
{
	timerCounter++;
	//counts to make 1ms timer
	if (timerCounter >=timerCountVal)
	{
	timerCounter=0;
	systemTime++;
	intTime++;
	sample_flag = 1;
	current_sense();
	//sampleIR(ir1, ir2);
	//button_move();
	// sets 100 hz
	if(grasp_flag)
			grasptime++;
	}
	if (intTime>=10)
	{
		updatePIDLink('H',highSetP);
		updatePIDLink('L',lowSetP);
	}
	if (grasptime >= graspval){
		GOGETIT =1;
	}
	if (grasptime >= graspval2){
		GOGETIT2 = 1;
	}
	if(grasptime >= graspval3){
		GOGETIT3 = 1;
	}
	if(grasptime >= massval){
		MASSIT = 1;
		grasp_flag = 0;
		grasptime = 0;
	}


}
int angleToPot(char link, double angle) {
	int pot;
	// 240: 90, 645: 0
	if(link == 'H') {
		pot = (int)((((90 - angle) * 405)/90) + (potHZero-405));
		return pot;
	}
	// 190: 90, 580: 0
	if(link == 'L'){
		pot = (int)((((90 - angle) * 390)/90) + (potLZero-390));
		return pot;
	}
	return 645;
}

void button_move(){

	volatile int buttonState = 7;

//PID run at the interrupt
	DDRB &= ~(1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);
	PORTC &= ~(1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3);

		if (!PINBbits._P0)
			buttonState = 7;
		else if (!PINBbits._P1)
			buttonState = 6;
		else if (!PINBbits._P2)
			buttonState = 5;
		else if (!PINBbits._P3)
			buttonState = 4;
		else
			buttonState = 8;

		//printf("button: %d \n\r",buttonState);

		switch(buttonState){

		case 4:
			potHZero = getADC(Arm1ADCPort);
			potLZero = getADC(Arm0ADCPort);
			lowSetP = angleToADCLow(10);
			highSetP= angleToADCHigh(10);

			break;
		case 5:
			setServo(0, 180);
			break;
		case 6:
			setServo(0, 0);
			break;
		case 7:
			lowSetP=angleToADCLow(90);
			highSetP=angleToADCHigh(0);
			break;
		case 8:
			lowSetP=angleToADCLow(45);
			highSetP=angleToADCHigh(45);
			break;
		}
	}



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


void updatePIDLink(char link,int setPoint)
{
switch(link){
case 'H':
	//1000 to 250
	if (FALSE){
		setDAC(2, 0);
		setDAC(3, 0);
	}
	else{
		long pidNum = calcPID('H', setPoint, getADC(3));
//		printf("H \n\r");
//		printf(" ADC: %d,Set: %d",getADC(3),setPoint);
//		printf(" PId: %ld, \n\r",pidNum);
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
//		printf("L \n\r");
//		printf(" ADC: %d,Set: %d",getADC(2),setPoint);
//		printf(" PId: %ld, \n\r",pidNum);
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

double getUpperAngle(int x, int y){
//	double theta1 = 0.0;
//	theta1 = -1.0 * acos((double)(square(x) + square(((double)y - L0)) - square(L1) + square(L2))/(((double)2 * L1 * L2)));
//	theta1 = theta1 / 3.141596 * 180.0;
	double theta1;
	double c2 = ((double)((y + L0) * (y + L0) + x * x - L1 * L1 - L2 * L2))/((double)(2 * L1 * L2));
	double s2 = sqrt(1 - (c2*c2));
	theta1 = atan2(s2,c2);
	theta1 *= (180/M_PI);
	theta1 += 10; //offset to try to get it to work
	return theta1;
}

double getLowerAngle(int x, int y){
//	double theta0 = 0.0;
//	double beta = 0.0;
//	double gamma = 0.0;
//	beta = atan2(x,y);
//	gamma = acos((square(x)+square(y-L0)+square(L1)+square(L2))/(2*L1*sqrt(square(x)+square(y-L0))));
//	theta0 = beta + gamma;
//	theta0 = theta0 / 3.141596 * 180.0;
	//double theta0;
	double c2 = ((y + L0) * (y + L0) + x * x - L1 * L1 - L2 * L2)/((double)(2 * L1 * L2));
	double s2 = sqrt(1 - (c2*c2));
	double k1 = L1 + (L2 * c2);
	double k2 = L2*s2;

	double atanPart1 = atan2(y + L0,x);
	double atanPart2 = atan2(k1,k2);

	double theta0 = -1*(atanPart1-atanPart2);
	theta0 *= (180/M_PI);
	//theta0 += 10; //manual offset
	return 0 - theta0;
}
