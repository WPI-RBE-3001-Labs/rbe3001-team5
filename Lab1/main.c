/*
 * main.c
 *	Group 5 Lab 1
 *  Created on: Jan 17, 2017
 */
//test for commit
//#include "main.h"//File containing all the includes
#include "RBELib/RBELib.h"
#include <avr/io.h>

void part1();
void part2();
void part3();
void nukeWDT();

int main(){
	//Common setup here:
	nukeWDT();

	//Interchange the correct part of the lab
	part1();

	return 1;
} /* End main */

//This does the first part of the lab
/*
 * Connect the potentiometer to an ADC input and write a C program to read the potentiometer value
(Be sure not to exceed a 5V input, have a member of the lab staff verify your settings – incorrect settings
WILL damage your ADC). Write a program to transmit the timestamp, ADC value in counts, Pot output in
millivolts, and pot angle in degrees over the serial port to the screen in the Terminal (Using Putty or
equivalent) such that it can be logged and imported into Matlab. The program should start transmitting
upon receipt of a serial command from the PC. Use a consistent format that is straightforward to import
into Matlab (hint: csv file) – you will use this code again in later labs.
 *
 */
void part1(){
	//Setup ADC
	DDRA &= 0x00;//Sets Port A Pin 7 for Input
	//PORTA &= (0<<PA7);//Turn Pull-up resistor off
	initADC(7);

	//Setup Serial Transmission
	debugUSARTInit(115200);

	//Setup LED Port
	initPB();

	unsigned int potValue;
	while(1){
		//Read ADC, store as potValue
		potValue = getADC(7);
		if(potValue > 100){
			PORTB = 0x00;
		}
		else{
			PORTB = 0xFF;
		}
		//Send potValue over serial
		putCharDebug((char)potValue);
		putCharDebug('\n');


	}
}

//This does the second part of the lab
/*
3. Write a program that:
a. Outputs a square wave using a timer interrupt to establish accurate frequency. Use the
pushbuttons to select a frequency (1Hz, 20Hz, and 100Hz).
b. Adjusts the duty cycle from 0%100% based upon the potentiometer position.
c. Prints the duty cycle, frequency, state, and pot value to the serial port

4. Connect the digital output to the oscilloscope and run the above program. Save screenshots and serial
port data for each frequency at 25% and 70% duty cycles. Be sure to save and label the collected data
files.
 */
unsigned char waveToggle;
unsigned int numTicks;
unsigned int switchHightoLow;
unsigned int switchLowtoHigh;
void part2(){
	//setup timer to a fixed 100 Hz frequency:


	//setup a pin to output
	DDRBbits._P7 = OUTPUT;

	//setup buttons:
	unsigned char buttonState;


	//setup ADC
	unsigned int potVal;

	while(1){
		switch(waveToggle){
		case 0:
			//output High
			PINBbits._P7 = HIGH;
			break;
		default:
			//output Low
			PINBbits._P7 = LOW;
			break;
		}
		//read buttons

		//Update frequency

		//read pot

		//update high and low count to reflect period of high and low and frequency
	}
}

//COMMENT THIS OUT WHEN DOING THE NEXT PART
//ISR for part 2, just toggles waveTogglfor whether high or low
//first it will incrimate the number of ticks, then see if enough have passed to toggle
ISR(TIMER0_OVF_vect){
 	numTicks++;
	if(numTicks >= switchHightoLow && waveToggle){
		//set to low
		waveToggle = 0;
	}
	if(numTicks >= switchLowtoHigh && !waveToggle){
		//set to high
		waveToggle = 1;
	}
}


/*
 * 5. Set up the signal generator at your lab workstation to output a 5V waveform (be sure to have a
member of the lab staff verify your settings – incorrect settings WILL damage your ADC). Confirm
operation by connecting it to the oscilloscope.
6. Configure the program you wrote in Step 2 above to use a timer interrupt to sample at 225Hz for 1
second when a button is pressed and pass a timestamp and the actual output at each time step to the
PC. Note that you may need to reduce the amount of information transmitted, increase the serial port
baud rate, or cache the data to RAM to achieve the appropriate sample rate. You should confirm the
correct sample rate by pulsing a digital output each cycle and viewing it on the scope.
7. Connect the analog output of the lab signal generator to the ADC. For each of square, triangle and sine
waves collect data for 20, 125, and 140Hz. Be sure to collect screen captures of the signal generator
output on the oscilloscope for each waveform and collect serial data from the AVR for each sample rate
for each waveform.
 *
 */
unsigned char shouldSample;
unsigned char IsbuttonPressed;
unsigned char sampleCount = 225;
void part3(){
	unsigned int ADCVal;
	//setup ADC

	//setup serial transmission

	while(1){
		if(shouldSample){
			//read ADC

			//output to Serial
		}
	}
}

//COMMENT THIS OUT WHEN DOING THE SECOND PART
//ISR for part 3
/*
 * ISR(TIMER0_OVF_vect){
 * 		if(IsButtonPressed && samplecount > 0 && samplecount < 226){
 * 			shouldSample = 1;
 * 			samplecount--;
 * 		} else {
 * 			shouldSample = 0;
 * 			samplecount == 0;
 * 		}
 * }
 */

//Note originally called for enabling and disabling interrupts within this function.
//builder didn't like that so I got rid of it
void nukeWDT(){
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/*Turn off WDT */
	WDTCSR = 0x00;
}
