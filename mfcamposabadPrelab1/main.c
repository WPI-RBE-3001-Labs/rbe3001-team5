/*
* main.c
*
* Created on: Aug 6, 2014
* Author: ewillcox
*/
#include "RBELib/RBELib.h" //RBELib
#include "avr/io.h"

int main(void){
	initRBELib(); //Setup printf() and setServo()
	debugUSARTInit(115200); //Initialize UART
	DDRB = 0xFF; //Set Port as output
	while (1){
		PORTB = 0xFF; //Turn port on
		_delay_ms(500); //Delay .5 sec
		PORTB = 0x00; //Turn port off
		_delay_ms(500); //Delay .5 sec
		printf("Hello\n\r"); //Print “Hello”
	}
	return 0;
}
