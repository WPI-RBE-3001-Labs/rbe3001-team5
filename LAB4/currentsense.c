/*
 * currentsense.c
 *
 *  Created on: Feb 28, 2017
 *      Author: Matias
 */


#include "RBELib/RBELib.h"
#include "main.h"

float getCurrent(char joint){
  float ADCval = 0;
  //get ADC for each channel of joint
  switch(joint){
  case 'H':
    initADC(ADC0D);
    changeADC(ADC0D);
    ADCval = getADC(ADC0D);
    break;
  case 'L':
    initADC(ADC1D);
    changeADC(ADC1D);
    ADCval = getADC(ADC1D);
    break;
  }
  //float current = (ADCval * (5.0) / 1023) - (2.5/(20*0.05));
  //current = 1000*current;
  double current = (double)((ADCval - 511)/205)*1000;//current sense for the arm moving forward
  return current;
}

void current_sense(){
float currentl = 0;
float currenth = 0;

currentl = getCurrent('L');
currenth = getCurrent('H');

//printf("Current Low Link: %f  \n\r", currentl);
//printf("Current High Link: %f  \n\r", currenth);

}
