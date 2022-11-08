/*
 * output_display.c
 *
 *  Created on: Oct 23, 2022
 *      Author: LENOVO
 */


#include "output_display.h"

int led_buffer[4] = {5,3,3,5};
int led_fake[4] = {0,0,0,0};
int index_led = 0;
int mem = 3;
int remember[4] = {0,0,0,0};

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin, RESET);
			HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin|seg1_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg5_Pin|seg2_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg1_Pin|seg2_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg4_Pin|seg5_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg2_Pin|seg5_Pin|seg6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg2_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg4_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, SET);
			break;
	}
}

void adisplay7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg1_Pin|aseg2_Pin|aseg3_Pin|aseg4_Pin|aseg5_Pin, RESET);
			HAL_GPIO_WritePin(aseg6_GPIO_Port, aseg6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg3_Pin|aseg4_Pin|aseg5_Pin|aseg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, aseg1_Pin|aseg2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg3_Pin|aseg4_Pin|aseg1_Pin|aseg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, aseg5_Pin|aseg2_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg3_Pin|aseg1_Pin|aseg2_Pin|aseg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, aseg4_Pin|aseg5_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg3_Pin|aseg4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, aseg1_Pin|aseg2_Pin|aseg5_Pin|aseg6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg3_Pin|aseg2_Pin|aseg5_Pin|aseg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, aseg1_Pin|aseg4_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg2_Pin|aseg3_Pin|aseg4_Pin|aseg5_Pin|aseg6_Pin, RESET);
			HAL_GPIO_WritePin(aseg1_GPIO_Port, aseg1_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, aseg3_Pin|aseg4_Pin|aseg5_Pin|aseg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg1_Pin|aseg2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg1_Pin|aseg2_Pin|aseg3_Pin|aseg4_Pin|aseg5_Pin|aseg6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, aseg0_Pin|aseg1_Pin|aseg2_Pin|aseg3_Pin|aseg5_Pin|aseg6_Pin, RESET);
			HAL_GPIO_WritePin(aseg4_GPIO_Port, aseg4_Pin, SET);
			break;
	}
}

void update7SEG (int index) {
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(q0_GPIO_Port, q0_Pin, RESET);
			HAL_GPIO_WritePin(q1_GPIO_Port, q1_Pin, SET);
			HAL_GPIO_WritePin(q2_GPIO_Port, q2_Pin, SET);
			HAL_GPIO_WritePin(q3_GPIO_Port, q3_Pin, SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(q0_GPIO_Port, q0_Pin, SET);
			HAL_GPIO_WritePin(q1_GPIO_Port, q1_Pin, RESET);
			HAL_GPIO_WritePin(q2_GPIO_Port, q2_Pin, SET);
			HAL_GPIO_WritePin(q3_GPIO_Port, q3_Pin, SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(q0_GPIO_Port, q0_Pin, SET);
			HAL_GPIO_WritePin(q1_GPIO_Port, q1_Pin, SET);
			HAL_GPIO_WritePin(q2_GPIO_Port, q2_Pin, RESET);
			HAL_GPIO_WritePin(q3_GPIO_Port, q3_Pin, SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(q0_GPIO_Port, q0_Pin, SET);
			HAL_GPIO_WritePin(q1_GPIO_Port, q1_Pin, SET);
			HAL_GPIO_WritePin(q2_GPIO_Port, q2_Pin,	SET);
			HAL_GPIO_WritePin(q3_GPIO_Port, q3_Pin, RESET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}

void updateVal7SEG() {
	  if (timer5_flag == 1) {
		  if (status == MAN_RED || status == MAN_GREEN || status == MAN_YELLOW || status == INIT) {
			  led_buffer[0] = led_buffer[2] = led_buffer[3] = 0;
			  led_buffer[1] = 2;
		  }
		  else for (int i = 0; i < 4; i++) --led_buffer[i];
		  setTimer5(1000);
	  }
}

void scan7SEG() {
	  if (timer4_flag == 1) {
		  if (index_led >= 4) index_led = 0;
		  remember[index_led] = led_buffer[index_led]%10;
		  led_buffer[index_led] > 9 ? display7SEG(remember[index_led++]): update7SEG(index_led++);
		  setTimer4(200);
	  }
}

void blinkyLed(int led) {
	if (timer2_flag) {
		switch (led) {
			case LED_RED:
				HAL_GPIO_TogglePin(GPIOA, output0_Pin | output3_Pin);
				break;

			case LED_GREEN:
				HAL_GPIO_TogglePin(GPIOA, output2_Pin | output5_Pin);
				break;

			case LED_YELLOW:
				HAL_GPIO_TogglePin(GPIOA, output1_Pin | output1_Pin);
				break;

			default:
				break;
		}
	}
	setTimer2(500);
}
