#include "RBELib/RBELib.h"

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
		//timer 0 - 8 bit
		/* Timer clock = I/O clock / comp */
		TCCR0A |= (1 << CS00);
		/* Clear overflow flag */
		TIFR0 |= 1<<TOV0;
		/* Enable Overflow Interrupt */
		TIMSK0 |= 1<<TOIE0;

		TCNT0 = 0x00;

	}else if(timer == 1){
		//timer 1 - 16 bit

	}else if(timer == 2){
		//timer 2 - 8 bit
		/* Timer clock = I/O clock / comp */
		TCCR2B = comp;
		/* Clear overflow flag */
		TIFR2 = 1<<TOV2;
		/* Enable Overflow Interrupt */
		TIMSK2 = 1<<TOIE2;
	}else{
		//error
	}
}

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
