/*
 * main.c
 *
 *  Created on: Jan 21, 2017
 *      Author: ewillcox
 */

#include "main.h"

#include "main.h"

void initializations(){
initPB();
initPA();
initGlobals();
initTimer(0, 0, 1000);
}

int main(){
initializations();
sei();
while(1){
part7();
}
return 0;
}

void part5(){

if (button_state() == 1){
blinkAll(globals.blinkDelay);
}
else{
	PORTB = 0xFF;
}
}

void part6(){
	//Structure borrowed from MLamare
	debugUSARTInit(DEFAULT_BAUD); //112500
	unsigned char package = 0;

	while(1){
		package = getCharDebug(); //recieve a character
		//only transmit when the chip has something to transmit
		if(package){
			putCharDebug(package);
		}
	}
}

void part7(){

	while(1){
		switch(globals.state){
		case 0:
			//the is the off case
			PORTB = 0x00;
			break;
		case 1:
			//the on case
			PORTB = 0xFF;
			break;
		}
	}
}

ISR (TIMER0_OVF_vect){
	if(!globals.state){
		globals.state = 0;
		//TIFR0 &= 0<<TOV0;
	}else{
		globals.state = 1;
		//TIFR0 &= 0<<TOV0;
	}
}
