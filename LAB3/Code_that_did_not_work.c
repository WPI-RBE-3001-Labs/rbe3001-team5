///*
// * Code_that_did_not_work.c
// *
// *  Created on: Feb 15, 2017
// *      Author: Matias
// */
//
//
////Note originally called for enabling and disabling interrupts within this function.
////builder didn't like that so I got rid of it
//
//void nukeWDT(){
//	/* Clear WDRF in MCUSR */
//	MCUSR &= ~(1<<WDRF);
//	/* Write logical one to WDCE and WDE */
//	/* Keep old prescaler setting to prevent unintentional time-out */
//	WDTCSR |= (1<<WDCE) | (1<<WDE);
//	/*Turn off WDT */
//	WDTCSR = 0x00;
//}
//
//
////TODO button arm control thing
//#define testAngle 20
//void PIDarmControl(){
//	DDRDbits._P4 = OUTPUT;
//	PINDbits._P4 = 1;
//	//Setup PID
//	setConst(0, 120, 0.1, 0.1);
//
//	//Setup SPI
//	initSPI();
//
//	while(1){
//		upperJoint.ADCVal = getADC(Arm0ADCPort);
//		upperJoint.angle = potAngle(upperJoint.ADCVal);
//
//		signed int motorVal = calcPID(0, testAngle, upperJoint.angle);
//		driveLink(0, motorVal);
//	}
//}
//
//
//void driveMotors(){
//
//}
//
//#define CurrentSense0Port 0
//#define CurrentSense1Port 1
//#define noLoadCurrent 553
//#define voltageScaler 2
////readCurrentSense() funciton
//void readCurrentSense(){
//	//Initialize ADC first
//	initADC(CurrentSense0Port);
//	struct Current current0 = {0,0,0};
//	//enable it:
//	DDRAbits._P0 = OUTPUT;
//	PINAbits._P0 = 1;
//	DDRAbits._P1 = OUTPUT;
//	PINAbits._P1 = 1;
//	while(1){
//		current0.ADCVal = getADC(CurrentSense0Port);
//		current0.ADCVal -= noLoadCurrent;
//		current0.voltage *= voltageScaler;
//		printf("Current Sensor %d ", (int) current0.voltage); printf(", \n\r");
//		driveLink(0, 100);
//	}
//}
//
//
////struct coord forwardKinematics(int lowerTheta, int upperTheta){
////	struct coord ret = {0,0};
////	float c1 = cos(lowerTheta);
////	float c2 = cos(upperTheta);
////	float s1 = sin(lowerTheta);
////	float s2 = sin(upperTheta);
////	ret.x = (-1) * l1 * (c1*s2 - s1*c2) + l2 * s2;
////	ret.y = l1 * (c1*c2 - s1*s2) + l2*c2 + l0;
////	return ret;
////}
//
////globals for t
//int counter0 = 0;
//signed char counter0Dir = 1;
//int counter1 = 4095;
//signed char counter1Dir = -1;
//BOOL flag = 1;
//char LEDON = 0;
//
//void sawtoothWave(){
//	//DDRA = (1 << DDA5);
//	//disable IO port B
//	//DDRB = 0;
//	//setup the SPI bus
//	initSPI();
//	//will output waves between channels 0 and 1
//	//setup Timer
//	//initTimer(0,0,0);
//	//setCompValue(0, 16);
//
//	while(1){
////		if(flag){
////			PORTAbits._P5 = LEDON;
////			//printf("DAC Val: %d \n\r", counter0);
////			//printf("DAC Val: %d \n\r", counter1);
////			setDAC(0, counter0);
////			setDAC(1, counter1);
////			flag = 0;
////		}
////			//PINAbits._P7 = 0;
//		setDAC(0, counter0);
//		setDAC(1, counter1);
//
//		if (counter0 > 4095 || counter0 < 0 ){ //If it is out of bounds
//			counter0Dir *= -1; //change direction
//		}
//		counter0 += counter0Dir;
//
//		//Counter 1
//		if (counter1 > 4095 || counter1 < 0 ){ //If it is out of bounds
//			counter1Dir *= -1; //change direction
//		}
//		counter1 += counter1Dir;
//
//		printf("DAC0 %d ", (int) counter0); printf(", \n\r");
//		printf("DAC1 %d ", (int) counter1); printf(", \n\r");
//
//		//trying to slow it down
//		float j;
//		for (volatile unsigned int i = 0; i <= 60000; i++){
//			j = 3.1462 / 6.356;
//		}
//	}
//}
////ISR for timer
////ISR(TIMER0_OVF_vect){
////	//Counter 0
////	if (counter0 > 4095 || counter0 < 0 ){ //If it is out of bounds
////		counter0Dir *= -1; //change direction
////	}
////	counter0 += counter0Dir;
////
////	//Counter 1
////	if (counter1 > 4095 || counter1 < 0 ){ //If it is out of bounds
////		counter1Dir *= -1; //change direction
////	}
////	counter1 += counter1Dir;
////	//printf("DAC Val: %d \n\r", flag);
////	flag = 1;
////	LEDON = 1 - LEDON;
////	TIFR0 = (1 << TOV0);
////	//sei();
////}
//
//
//void logPot2(){
//	//initialize ADC to correct channel
//	initADC(Arm1ADCPort);
//	initADC(Arm0ADCPort);
//
//	//struct coord coord1 = {0,0};
//
//	while(1){
//		//read pot value for upper and lower joints
//		upperJoint.ADCVal = getADC(Arm0ADCPort);
//		lowerJoint.ADCVal = getADC(Arm1ADCPort);
//
//		//Calculate Angle and Voltage Upper Joint
//		upperJoint.voltage = potVolts(upperJoint.ADCVal);
//		upperJoint.angle = potAngle(upperJoint.ADCVal);
//
//		//Calculate Angle and Voltage Lower Joint
//		lowerJoint.voltage = potVolts(lowerJoint.ADCVal);
//		lowerJoint.angle = potAngle(lowerJoint.ADCVal);
//
//		//Printing in CSV format Use Excel Filters to separate UJ from LJ
//		// Printing Values in Columns ADCValue[counts], Voltage[mV], Angle[deg]
//		printf(" Upper Joint:  "); printf(",");
//		//printf("X Position %d ", (int) coord1.x); printf(",");
//		//printf("Y Position %d ", (int) coord1.y); printf(",");
////		printf(" %d ", (int) upperJoint.ADCVal); printf(",");
////		printf(" %d ", (int) upperJoint.voltage); printf(",");
//		printf(" %d ", (int) upperJoint.angle); printf(",");
//		//printf("\n\r");
//		printf(" Lower Joint:  "); printf(",");
////	    printf(" %d ", (int) lowerJoint.ADCVal); printf(",");
////		printf(" %d ", (int) lowerJoint.voltage); printf(",");
//		printf(" %d ", (int) lowerJoint.angle); printf(",");
//		printf("\n\r");
//
//	} //End while(1)
//
//}//end LogPot()
//	  while(1)
//	  {
//
//		  if (PINCbits._P0 == 1)
//			  button_state = 7;
//		  else if (PINCbits._P6 == 1)
//			  button_state = 6;
//		  else if (PINCbits._P4 == 1)
//			  button_state = 5;
//		  else if (PINCbits._P2 == 1)
//			  button_state = 4;
//		  else
//			  button_state = 8;
//
//switch(button_state){
//
//	case 4:
//		lowSetP=angleToADCLow(45);
//		highSetP=angleToADCHigh(45);
//		break;
//	case 5:
//		lowSetP=angleToADCLow(30);
//		highSetP=angleToADCHigh(60);
//		break;
//	case 6:
//		lowSetP=angleToADCLow(60);
//		highSetP=angleToADCHigh(30);
//		break;
//	case 7:
//		lowSetP=angleToADCLow(90);
//		highSetP=angleToADCHigh(0);
//		break;
//	case 8:

//
//struct Potentiometer upperJoint = {0,0,0};
//struct Potentiometer lowerJoint = {0,0,0};
