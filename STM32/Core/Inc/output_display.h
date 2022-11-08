/*
 * output_display.h
 *
 *  Created on: Oct 23, 2022
 *      Author: LENOVO
 */

#include "main.h"
#include "software_timer.h"
#include "global.h"
#include "fsm_automatic.h"

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

extern int led_buffer[4];
extern int led_fake[4];
extern int index_led;
extern int mem;
extern int remember[4];

void display7SEG(int num);
void adisplay7SEG(int num);
void update7SEG(int index);
void updateVal7SEG();
void scan7SEG();
void blinkyLed(int led);

#endif /* INC_OUTPUT_DISPLAY_H_ */
