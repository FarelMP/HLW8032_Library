/*
 * HLW8032.h
 *
 *  Created on: Dec 19, 2024
 *      Author: FarelMP
 */

#ifndef INC_HLW8032_H_
#define INC_HLW8032_H_

#include "main.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

uint8_t buffer[25];
int indx = 0;
bool headerFound = false;
uint8_t check =0;

typedef struct{
	float Voltage;
	float Current;
	float PF;
	float activePower;
	float apparentPower;
}Param;

typedef struct{
	uint32_t VparamReg;
	uint32_t VReg;
	uint32_t IparamReg;
	uint32_t IReg;
	uint32_t PowparamReg;
	uint32_t PowReg;
	uint32_t PF;
}dataMerge;

void dataParse(uint8_t data);
void dataProcess(void);

#endif /* INC_HLW8032_H_ */
