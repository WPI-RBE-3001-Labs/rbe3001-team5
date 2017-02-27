/*
 * Encoder.h
 *
 *  Created on: Feb 13, 2017
 *      Author: crbriggs
 */

#ifndef ENCODER_H_
#define ENCODER_H_


int EncoderCounts( int __chan );
void initEncoder();
void resetEncoder(int __chan);
int GetAccelerationH48C ( int __axis );
void ENCODER();

#endif /* ENCODER_H_ */

