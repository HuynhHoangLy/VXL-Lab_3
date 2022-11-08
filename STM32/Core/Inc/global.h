/*
 * global.h
 *
 *  Created on: Oct 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"

#define LED_RED 0
#define LED_GREEN 1
#define LED_YELLOW 2

#define INIT 0
#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14

#define TIMER_BUTTON 0
#define TIMER_SOFTWARE 1

extern int status;
extern int anotherstatus;

#endif /* INC_GLOBAL_H_ */
