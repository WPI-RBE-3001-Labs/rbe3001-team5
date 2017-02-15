/* main.c
 *
 *  Created on: August 20, 2016
 *      Author: Joe st. Germain
 */


#include "RBELib/RBELib.h"
//For use of abs()
#include <stdlib.h>



int testPID();
int testSPI();
char inchar;
unsigned long lowADC = 0;
unsigned long highADC = 0;
unsigned long pot1Ang=0;
unsigned long potAngInt;
unsigned long mV=0;
volatile unsigned long systemTime = 0;
volatile unsigned long timerCounter;
volatile unsigned long intTime;
volatile double timerCountVal = 9; //9 for ms system time
volatile long highLinkErr;
volatile long lowLinkErr;

volatile int button_state = 7;
volatile int highSetP;
volatile int lowSetP;

volatile int offSetlow = 250;
volatile double adctoanglelow = 3.66;

volatile int offSethigh = 250;
volatile double adctoanglehigh = 4.16;
/*
 * Timer 0 ISR triggered on overflow
 */

// Takes in angle and returns adc value for lower link 0-180
int angleToADCLow(int angle)
{
	//double offsetadclow = angle + offSetlow ;
	double adclow =  ( angle * adctoanglelow)+ offSetlow;

	return adclow;
}

// Takes in angle and returns adc value for higher link 0-180
int angleToADCHigh(int angle)
{
	//double oSffsetadclow = angle + offSetlow ;
	double adchigh =  ( angle * adctoanglehigh)+ offSethigh;

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
		//printf("H \n\r");
		//printf(" ADC: %d,Set: %d",getADC(3),setPoint);
		//printf(" PId: %ld, \n\r",pidNum);
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
		//printf(" PId: %ld, \n\r",pidNum);
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


ISR(TIMER0_OVF_vect)
{
	timerCounter++;
	//counts to make 1ms timer
	if (timerCounter >=timerCountVal)
	{
	//Port C pin 0 flip for prelab part 8
	//PORTC ^= (1 << 0);
	timerCounter=0;
	systemTime++;
	intTime++;
	// Sets PID at 100hz
	if (intTime>=10)
	{
		 // updatePIDLink('H',calcPID('H',90,getADC(2)));
		 // updatePIDLink('L',calcPID('L',90,getADC(3)));
		updatePIDLink('H',highSetP);
		updatePIDLink('L',lowSetP);

	}
	}

}

int main(void)
{
	  //Enable printf() and setServo()
	  initRBELib();

	  // Write the USARTDebug.c file using the function prototypes in the H file to enable the usart
	  //Set the baud rate of the UART
	  debugUSARTInit(115200);
	  initADC(0);
	  initSPI();
	  // printf uses a fair amount of memory to be included but makes serial printing much easier
	  printf("PutCharDebug is complete \n\r");

	  // Runs once per ms
	  //Also runs PID once per 100 ms
	  initTimer(0, 0, 0);
	  //Set PID constants
	  //setConst('H',20.0,0.01,0.1);
	  //setConst('L',20.0,0.01,0.1);

	  DDRC = 0x00;
	  //PORTC = 0xFF;
	  //testPID();
	  testSPI();

}
int testSPI() {


	int i = 0;
	//First byte: command byte
	//input is 4 for 4 bytes of data
	while(1){
		ENCODER_SS_0 = 0;
		i = spiTransceive(0b01001000);
		ENCODER_SS_0 = 1;

		printf("%d \n\r", i);
	}

	return 0;
}
int testPID() {

  while(1)
  {

	  if (PINCbits._P0 == 1)
		  button_state = 7;
	  else if (PINCbits._P6 == 1)
		  button_state = 6;
	  else if (PINCbits._P4 == 1)
		  button_state = 5;
	  else if (PINCbits._P2 == 1)
		  button_state = 4;
	  else
		  button_state = 8;

	  switch(button_state){

	  	  case 4:
	  		  lowSetP=angleToADCLow(45);
			highSetP=angleToADCHigh(45);
			break;
	  	  case 5:
			lowSetP=angleToADCLow(30);
			highSetP=angleToADCHigh(60);
			break;
	  	  case 6:
			lowSetP=angleToADCLow(60);
			highSetP=angleToADCHigh(30);
			break;
	  	  case 7:
			lowSetP=angleToADCLow(90);
			highSetP=angleToADCHigh(0);
			break;
	  	  case 8:

		  //PID run in interupt
		  lowSetP=angleToADCLow(90);
		  highSetP=angleToADCHigh(45);

		  printf("adcL: %d\n\r",lowSetP);
		  printf("adcH: %d \n\r",highSetP);
		 // _delay_ms(2000);


		  lowSetP=angleToADCLow(90);
		  highSetP=angleToADCHigh(0);
		  printf("adcL: %d\n\r",lowSetP);
		  printf("adcH: %d\n\r",highSetP);

		  // _delay_ms(2000);
	  }
  }
  return 0;
}



