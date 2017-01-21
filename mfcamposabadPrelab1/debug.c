/*
 *
 * USART.c
 *
 *  Created on: Jan 26, 2015
 *      Author: joest
 */


#include "RBELib/RBELib.h"
#include <avr/io.h>

void debugUSARTInit(unsigned long baudrate){
	//Borrowed Example from data sheet:
	/*Set baud rate */
	UBRR1H = (unsigned char)(baudrate>>8);
	UBRR1L = (unsigned char)baudrate;
	/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS1)|(3<<UCSZ00);
}

void putCharDebug(char byteToSend){
	//Borrowed Example from data sheet:
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1 << UDRE1)));

	/* Put data into buffer, sends the data */
	UDR1 = byteToSend;
}

unsigned char getCharDebug(void) {
	/* Wait for data to be received */
	while ( !(UCSR1A & (1 << RXC1)));

	/* Get and return received data from buffer */
	return UDR1;

}


