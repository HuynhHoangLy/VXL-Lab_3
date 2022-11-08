/*
 * traffic.c
 *
 *  Created on: Oct 14, 2022
 *      Author: LENOVO
 */
#include "traffic.h"

void turnLightOn(int led){
	switch(led){
		case LED_RED:
			HAL_GPIO_WritePin(output1_GPIO_Port, output1_Pin, SET);
			HAL_GPIO_WritePin(output0_GPIO_Port, output0_Pin, RESET);
			break;
		case LED_GREEN:
			HAL_GPIO_WritePin(output2_GPIO_Port, output2_Pin, RESET);
			HAL_GPIO_WritePin(output0_GPIO_Port, output0_Pin, SET);
			break;
		case LED_YELLOW:
			HAL_GPIO_WritePin(output1_GPIO_Port, output1_Pin, RESET);
			HAL_GPIO_WritePin(output2_GPIO_Port, output2_Pin, SET);
			break;
		default:
			break;
	}
}

void anotherturnLightOn(int led) {
	switch(led){
		case LED_RED:
			HAL_GPIO_WritePin(output4_GPIO_Port, output4_Pin, SET);
			HAL_GPIO_WritePin(output3_GPIO_Port, output3_Pin, RESET);
			break;
		case LED_GREEN:
			HAL_GPIO_WritePin(output5_GPIO_Port, output5_Pin, RESET);
			HAL_GPIO_WritePin(output3_GPIO_Port, output3_Pin, SET);
			break;
		case LED_YELLOW:
			HAL_GPIO_WritePin(output4_GPIO_Port, output4_Pin, RESET);
			HAL_GPIO_WritePin(output5_GPIO_Port, output5_Pin, SET);
			break;
		default:
			break;
	}
}

void clearLight(){
	HAL_GPIO_WritePin(GPIOA, output0_Pin|output1_Pin|output2_Pin, SET);
}

void anotherclearLight(){
	HAL_GPIO_WritePin(GPIOA, output3_Pin|output4_Pin|output5_Pin, SET);
}
