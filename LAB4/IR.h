/*
 * IR.h
 *
 *  Created on: Feb 26, 2017
 *      Author: mfcamposabad
 */

#ifndef IR_H_
#define IR_H_

extern struct IR{
	char port;
	int adcVal;
	int millimeters;
};

int getIRValue(char port);
int adcToMillimeters(int adc);
void setupIR(struct IR ir, char port);
void sampleIR(struct IR ir1, struct IR ir2);

#endif /* IR_H_ */
