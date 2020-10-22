/*
 * keypad.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#include "keypad.h"

static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number) {
	switch(button_number) {
		case 1: return '7';
				break;
		case 2: return '8';
				break;
		case 3: return '9';
				break;
		case 4: return '%';
				break;
		case 5: return '4';
				break;
		case 6: return '5';
				break;
		case 7: return '6';
				break;
		case 8: return '*';
				break;
		case 9: return '1';
				break;
		case 10: return '2';
				break;
		case 11: return '3';
				break;
		case 12: return '-';
				break;
		case 13: return KEYPAD_ENTER;
				break;
		case 14: return '0';
				break;
		case 15: return '=';
				break;
		case 16: return '+';
				break;
		default: return button_number;
	}
}

uint8 Keypad_getPressedKey (void) {
	uint8 row = 0, col = 0;
	/* clear all pins except pins not related to keypad */
	KEYPAD_DDR &= ~((1 << (KEYPAD_ROWS + KEYPAD_COLS)) - 1);

	/* enable pull ups for row pins only */
	KEYPAD_PORT |= (1 << (KEYPAD_ROWS)) - 1;

	while (1) {
		for(row = 0; row < KEYPAD_ROWS; row++) {
			for (col = 0; col < KEYPAD_COLS; col++) {
				/* we need to make cols input except for the current col which should be output
				 * without affecting pins not related to the keypad on the same port
				 * and without affecting Row DDR pins
				 */

				/* 1. preserve other pins and clear all others
				 * XXcccrrr -> XX000000
				 */
				KEYPAD_DDR &= ~((1 << (KEYPAD_ROWS + KEYPAD_COLS)) - 1);

				/* 2. set the current col as output */
				KEYPAD_DDR |= (1 << (col+KEYPAD_ROWS));

				/* 3. preserve rows and clear others */
				KEYPAD_DDR |= (KEYPAD_DDR & ~((1 << (KEYPAD_ROWS)) - 1));

				KEYPAD_PORT &= ~(1 << (col+KEYPAD_ROWS));

				if(BIT_IS_CLEAR(KEYPAD_PIN, row)) {
					while (BIT_IS_CLEAR(KEYPAD_PIN, row));
					return KeyPad_4x4_adjustKeyNumber(row * KEYPAD_COLS + col + 1);
				}
			}
		}
	}
}
