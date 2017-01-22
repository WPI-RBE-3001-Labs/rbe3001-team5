/*
 * main.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Matt
 */
#include "RBELib/RBELib.h"

void part1();
void part2();
void part3();
void WDT_off();

int main(){
	//Common setup here:
	WDT_off();

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

}

//This does the second part of the lab
/*
3. Write a program that:
a. Outputs a square wave using a timer interrupt to establish accurate frequency. Use the
pushbuttons to select a frequency (1Hz, 20Hz, and 100Hz).
b. Adjusts the duty cycle from 0% ‐ 100% based upon the potentiometer position.
c. Prints the duty cycle, frequency, state, and pot value to the serial port

4. Connect the digital output to the oscilloscope and run the above program. Save screenshots and serial
port data for each frequency at 25% and 70% duty cycles. Be sure to save and label the collected data
files.
 */
void part2(){

}

/*
 * 5. Set up the signal generator at your lab workstation to output a 0‐5V waveform (be sure to have a
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
void part3(){

}

void WDT_off(){
	__disable_interrupt();
	__watchdog_reset();
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/*Turn off WDT */
	WDTCSR = 0x00;
	__enable_interrupt();
}
