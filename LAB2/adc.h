/*
 * ADC.h
 *
 *  Created on: Jan 24, 2017
 *      Author: Matias
 */

#ifndef ADC_H_
#define ADC_H_

#include "main.h"

void initADC(int channel);
void clearADC(int channel);
unsigned short getADC(int channel);


#endif /* ADC_H_ */
