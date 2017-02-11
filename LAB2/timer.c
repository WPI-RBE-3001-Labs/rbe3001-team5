<<<<<<< HEAD
#include "RBELib/RBELib.h"
#include "main.h"

/**
 * @brief Initializes the specified timer in the specified mode. This
 * header file provides constants for NORMAL operation mode and
 * CTC operation mode, however there are many more modes of operation
 * for the Timers that can be experimented with.
 *
 * @param timer The number of the timer to be initialized (0-2).
 * @param mode The mode to initialize the specified timer in.
 * @param comp Only used in CTC mode. The value that the
 * timer counts to before it triggers an interrupt and resets.
 *
 * @todo Create a function that initializes the desired timer in a given mode and set the compare value
 * (as appropriate).
 */
void initTimer(int timer, int mode, unsigned int comp){
	if(!timer){
		/*Clear Counter  */
		//TCNT0 = 0x00;
		//timer 0 - 8 bit
		/* Timer clock = I/O clock / 1024 */
		TCCR0B = 0b00000000;//(1<<CS02)|(1<<CS00);
		TCCR0A = 0b00000010;//(0<<WGM01)|(0<<WGM00);
		/* Clear overflow flag */
		TIFR0 |= (1<<TOV0);
		/* Enable Overflow Interrupt */
		TIMSK0 = 0b00000001;//(1<<TOIE0);

	}
}
	//}else if(timer == 1){
		//timer 1 - 16 bit

	//}else if(timer == 2){
		//timer 2 - 8 bit
		/* Timer clock = I/O clock / 1024 */
		//TCCR2B = (1<<CS02)|(1<<CS00);
		/* Clear overflow flag */
		//TIFR2 = 1<<TOV2;
		/* Enable Overflow Interrupt */
		//TIMSK2 = 1<<TOIE2;
	//}else{
		//error
	//}
//}

//}
/**
 * @brief Only used when the specified timer is in CTC mode. Changes
 * the value of the comparison register to the new specified value.
 *
 * @param timer The timer comparison value to change (0-2).
 * @param comp The value to set the comparison register to.
 *
 * @todo Create a function that will set a new compare value for the given timer.
 */
void setCompValue(unsigned char timer, unsigned short int comp){

}
=======
/*
 * timer.c
 *
 *  Created on: Aug 24, 2016
 *      Author: joest
 */

#include <RBELib/RBELib.h>



//currently only timer 0
//currently only normal mode =0 and CTC mode = 4

void initTimer(int timer, int mode, unsigned int comp)
{
	//if (timer == 0)
//	{
		//Enables Timer0 Interrupt overflow mode
		//TIMSK0 = 0x01;
		TIMSK0|=(1<<TOIE0);
		sei();
		//TCNT0=0x00;
		//Sets 256 prescalar
		TCCR0B |= (1 << CS01);//|(1 << CS00);

		//Sets all bits LOW
		//OCR0A = 0x00;

		//Sets Clock with no prescaling
		//TCCR0B = 0x01;
		// prescale 256
		//TCCR0B = (1 << CS01)|(1 << CS00);




//	}
}

/*
void initTimer(int timer, int mode, unsigned int comp)
{
	switch(timer)
	{
	case 0:
		comp &= 0xFF;
		if (mode == 0x00) //normal mode
		{
			TCCR0A = 0x00;
			TCCR0B = (1 << CS01);	//prescalar is 8
			TIMSK0 = (1 << TOIE0);
		}
		else if(mode == 0x01) // CTC Phase Corrected PWM mode
		{
			TCCR0A = (1 << COM0A0)| (1 << WGM00); //Use toggling outpit pin of OC0A only OC0B is disconnected
			TCCR0B = (1 << WGM02) | (1 << CS01); //Use toggling on output and 8 prescalar
			TIMSK0 = (1 << OCIE0A);
			OCR0A = comp;
		}
		else if (mode == 0x2) //CTC mode
		{
			TCCR0A = (1 << WGM01);
		}
		break;
	case 1: //timer1
		break;
	default: //timer 2
		break;
	}
}
*/

void setCompValue(unsigned char timer, unsigned short int comp)
{
	// For using Timer 0
	if (timer == 0){

		// Sets an 8-bit value for the clock to count to
		OCR0A = comp;
	}
}
/*
 * void setCompValue(unsigned char timer, unsigned short int comp)
{
	switch(timer)
	{
	case 0:
		comp &= 0xFF;
		OCR0A = comp;
		break;
	case 1:
		OCR1A = comp;
		break;
	default:
		comp &= 0xFF;
		OCR2A = comp;
		break;
	}
}
*/
>>>>>>> c647a692f4acbf2a6ff0ec4a7c58ccf19f03b9be
