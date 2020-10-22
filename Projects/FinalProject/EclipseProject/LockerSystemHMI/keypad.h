/*
 * keypad.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_ENTER 13

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

#define KEYPAD_PORT PORTA
#define KEYPAD_DDR DDRA
#define KEYPAD_PIN PINA

uint8 Keypad_getPressedKey (void);

#endif /* KEYPAD_H_ */
