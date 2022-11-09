/*
 * mode2.c
 *
 *  Created on: Nov 8, 2022
 *      Author: LENOVO
 */

#include "mode2.h"

void mode2() {
	switch (status) {
		case MAN_RED:

			setTimer2(10);
			updateVal7SEG();
			blinkyLed(LED_RED);
			led_buffer[1] = led_fake[1] = 2;

			if (isButtonPressed(0) || isButtonLPressed(0)) status = MAN_YELLOW;
			if (isButtonPressed(1) || isButtonLPressed(1)) {
				if (led_fake[3] >= 9) {
					++led_fake[2];
					led_fake[3] = 0;
				}
				if (led_fake[2] >= 9) {
					led_fake[2] = 0;
					led_fake[3] = 1;
				}
				else ++led_fake[3];
			}
			if (led_fake[2] != 0) led_buffer[2] = led_fake[2];
			if (led_fake[3] != 0) led_buffer[3] = led_fake[3];
			if (isButtonPressed(2) || isButtonLPressed(2)) {
				status = INIT;
				if (led_fake[2] != 0 || led_fake[3] != 0) time4Run[2] = led_fake[2]*10 + led_fake[3];
				for (int i = 0; i < 4; i++) led_fake[i] = 0;
				status = INIT;
				anotherstatus = INIT;
				led_buffer[0] = led_buffer[3] = time4Run[2];
				led_buffer[1] = led_buffer[2] = time4Run[0];
			}
			break;

		case MAN_GREEN:

			setTimer2(10);
			clearLight();
			updateVal7SEG();
			anotherclearLight();
			blinkyLed(LED_GREEN);
			led_buffer[1] = led_fake[1] = 4;

			if (isButtonPressed(0) || isButtonLPressed(0)) status = INIT;
			if (isButtonPressed(1) || isButtonLPressed(1)) {
				if (led_fake[3] >= 9) {
					++led_fake[2];
					led_fake[3] = 0;
				}
				if (led_fake[2] >= 9) {
					led_fake[2] = 0;
					led_fake[3] = 1;
				}
				else ++led_fake[3];
			}
			if (led_fake[2] != 0) led_buffer[2] = led_fake[2];
			if (led_fake[3] != 0) led_buffer[3] = led_fake[3];
			if (isButtonPressed(2) || isButtonLPressed(2)) {
				status = INIT;
				if (led_fake[2] != 0 || led_fake[3] != 0) time4Run[0] = led_fake[2]*10 + led_fake[3];
				for (int i = 0; i < 4; i++) led_fake[i] = 0;
				status = INIT;
				anotherstatus = INIT;
				led_buffer[0] = led_buffer[3] = time4Run[2];
				led_buffer[1] = led_buffer[2] = time4Run[0];
			}
			break;

		case MAN_YELLOW:

			setTimer2(10);
			clearLight();
			anotherclearLight();
			blinkyLed(LED_YELLOW);
			led_buffer[1] = led_fake[1] = 3;

			if (isButtonPressed(0) || isButtonLPressed(0)) status = MAN_GREEN;
			if (isButtonPressed(1) || isButtonLPressed(1)) {
				if (led_fake[3] >= 9) {
					++led_fake[2];
					led_fake[3] = 0;
				}
				if (led_fake[2] >= 9) {
					led_fake[2] = 0;
					led_fake[3] = 1;
				}
				else ++led_fake[3];
			}
			if (led_fake[2] != 0) led_buffer[2] = led_fake[2];
			if (led_fake[3] != 0) led_buffer[3] = led_fake[3];
			if (isButtonPressed(2) || isButtonLPressed(2)) {
				status = INIT;
				if (led_fake[2] != 0 || led_fake[3] != 0) time4Run[1] = led_fake[2]*10 + led_fake[3];
				for (int i = 0; i < 4; i++) led_fake[i] = 0;
				status = INIT;
				anotherstatus = INIT;
				led_buffer[0] = led_buffer[3] = time4Run[2];
				led_buffer[1] = led_buffer[2] = time4Run[0];
			}
			break;

		default:
			break;
	}
}
