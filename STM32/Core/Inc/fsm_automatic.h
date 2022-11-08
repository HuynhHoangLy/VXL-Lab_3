/*
 * fsm_automatic.h
 *
 *  Created on: Oct 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "traffic.h"
#include "software_timer.h"
#include "output_display.h"

#define LED_INDEX 0

extern int time4Run[3];

void fsm_automatic_run();

#endif /* INC_FSM_AUTOMATIC_H_ */
