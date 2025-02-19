/*
 * HLW8032.h
 *
 *  Created on: Dec 19, 2024
 *      Author: FarelMP
 */
#include "HLW8032.h"

Param calc;
Param *ptr = &calc;

dataMerge merge;
dataMerge *addr = &merge;

void dataParse(uint8_t data) {
	if(data == 0x55){
		buffer[0] = data;
	}else if(data == 0x5a){
		buffer[1] = data;
		indx = 2;
	}else if(indx>= 2 && indx <24){
		buffer[indx] = data;
		indx++;
	}
	if(indx == 24){
		dataProcess();
		indx=0;
	}
}

void dataProcess(void) {
	addr->VparamReg 	= (buffer[2]  << 16) | (buffer[3]  <<8) | buffer[4];			//V Param REG merge bytes
	addr->VReg 		= (buffer[5]  << 16) | (buffer[6]  <<8) | buffer[7];			//V REG merge bytes
	addr->IparamReg 	= (buffer[8]  << 16) | (buffer[9]  <<8) | buffer[10];			//I Param REG merge bytes
	addr->IReg 		= (buffer[11] << 16) | (buffer[12] <<8) | buffer[13];			//I REG merge bytes
	addr->PowparamReg 	= (buffer[14] << 16) | (buffer[15] <<8) | buffer[16];			//P Param REG merge bytes
	addr->PowReg 		= (buffer[17] << 16) | (buffer[18] <<8) | buffer[19];			//P REG merge bytes
	addr->PF 		= (buffer[21] <<  8) |  buffer[22];

	ptr->Voltage 		= (float) addr->VparamReg * 1.88 / addr->VReg;				//Vrms
	ptr->Current 		= (float) addr->IparamReg * 1.88 / addr->IReg;				//Irms
	ptr->activePower 	= (float) addr->PowparamReg*1.88 / addr->PowReg;			//Active Power
	ptr->apparentPower 	= (float) ptr->Voltage * ptr->Current;					//Apaprent Power
	ptr->PF 		= (float) ptr->activePower / ptr->apparentPower;			//PF
}

