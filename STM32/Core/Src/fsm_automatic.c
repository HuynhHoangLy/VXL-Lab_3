/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: LENOVO
 */


#include "fsm_automatic.h"

int time4Run[3] = {3, 2, 5}; // do->xanh , xanh->vang, vang->do

void fsm_automatic_run() {

	switch (status) {
		case INIT:
			clearLight();
			status = AUTO_RED;
			setTimer1((time4Run[2])*1000);
			break;

		case AUTO_RED:
			turnLightOn(LED_RED);
			if (isButtonPressed(0)) {
				status = MAN_RED;
				clearLight();
				anotherstatus = MAN_RED;
				anotherclearLight();
			}
			updateVal7SEG();
			if (timer1_flag == 1) {
				status = AUTO_GREEN;
				led_buffer[0] = led_buffer[3] = time4Run[0];
				setTimer1((time4Run[0])*1000);
			}
			break;

		case AUTO_GREEN:
			turnLightOn(LED_GREEN);
			if (isButtonPressed(0)) {
				status = MAN_RED;
				clearLight();
				anotherclearLight();
				anotherstatus = MAN_RED;
			}
			updateVal7SEG();
			if (timer1_flag == 1) {
				status = AUTO_YELLOW;
				led_buffer[0] = led_buffer[3] = time4Run[1];
				setTimer1((time4Run[1])*1000);
			}
			break;

		case AUTO_YELLOW:
			turnLightOn(LED_YELLOW);
			if (isButtonPressed(0)) {
				status = MAN_RED;
				clearLight();
				anotherclearLight();
				anotherstatus = MAN_RED;
			}
			updateVal7SEG();
			if (timer1_flag == 1) {
				status = AUTO_RED;
				led_buffer[0] = led_buffer[3] = time4Run[2];
				setTimer1((time4Run[2])*1000);
			}
			break;

		default:
			break;
	}

	switch (anotherstatus) {
		case INIT:
			anotherclearLight();
			anotherstatus = AUTO_GREEN;
			setTimer3(time4Run[0]*1000);
			break;

		case AUTO_RED:
			anotherturnLightOn(LED_RED);
			updateVal7SEG();
			if (timer3_flag == 1) {
				anotherstatus = AUTO_GREEN;
				led_buffer[1] = led_buffer[2] = time4Run[0];
				setTimer3(time4Run[0]*1000);
			}
			break;

		case AUTO_GREEN:
			anotherturnLightOn(LED_GREEN);
			updateVal7SEG();
			if (timer3_flag == 1) {
				anotherstatus = AUTO_YELLOW;
				led_buffer[1] = led_buffer[2] = time4Run[1];
				setTimer3(time4Run[1]*1000);
			}
			break;

		case AUTO_YELLOW:
			anotherturnLightOn(LED_YELLOW);
			updateVal7SEG();
			if (timer3_flag == 1) {
				anotherstatus = AUTO_RED;
				led_buffer[1] = led_buffer[2] = time4Run[2];
				setTimer3(time4Run[2]*1000);
			}
			break;

		default:
			break;
	}
}
