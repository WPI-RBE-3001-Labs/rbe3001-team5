/*
 * Accel.c
 *
 *  Created on: Feb 13, 2017
 *      Author: Matias
 */
#include "RBELib/RBELib.h"

int getAcceleration(int axxis){
// x axxis = 0
// y axxis = 1
// z axxis = 2

//Reads 12bit data from the H48C Accelerometer
unsigned int ret = 0;
int temp_1 = 0;
int temp_2 = 0;

spiTransceive(0b00000110);

temp_1 = spiTransceive(axxis << 6);
temp_1 = ((temp_1 & 0x0F)<<8);
temp_2 = spiTransceive(0x00);

ret = temp_1 + temp_2;

return ret;
//if (axxis = 0){//x axxis
//
//}
//else if(axxis = 1){// y axxis
//
//}
//else if (axxis = 2){// z axxis
//
//}
//else{



void test_accel(){
int xgs = 0;
int ygs = 0;
int zgs = 0;

xgs = getAcceleration(0);
ygs = getAcceleration(1);
zgs = getAcceleration(2);

printf("X Gs: %d", xgs); printf(";"); printf("\n\r");
printf("Y Gs: %d", ygs); printf(";"); printf("\n\r");
printf("Z Gs: %d", zgs); printf(";"); printf("\n\r");


}

}


