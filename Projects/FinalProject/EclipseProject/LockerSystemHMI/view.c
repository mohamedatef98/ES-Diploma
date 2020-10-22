/*
 * view.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#include "lcd.h"
#include "keypad.h"
#include "view.h"
#include <string.h>

static uint8 View_getPassword(uint8 * message, uint8 * password) {
	uint8 i = 0, t, done = FALSE;
	LCD_clearScreen();
	LCD_displayString(message);
	LCD_goToRowCol(1, 0);
	while(i < 16) {
		t = Keypad_getPressedKey();
		if(t != KEYPAD_ENTER) {
			if (i >= MAX_PASS_LEN) {
				LCD_clearScreen();
				LCD_displayString("More than 12 chars!");
				_delay_ms(LCD_MESSAGE_DELAY);
				break;
			}
			password[i++] = t;
			LCD_sendData('*');
		}
		else {
			if (i < MIN_PASS_LEN) {
				LCD_clearScreen();
				LCD_displayString("Less than 4 chars!");
				_delay_ms(LCD_MESSAGE_DELAY);
				break;
			}
			else {
				password[i++] = '\0';
				done = TRUE;
				break;
			}
		}
	}
	return done;
}

void View_init(void) {
	LCD_init();
}

void View_enterNewPassword (uint8 * password) {
	bool passMatch = FALSE;
	uint8 buffer1[16], buffer2[16];
	do {
		uint8 done1 = FALSE, done2 = FALSE;
		do {
			done1 = View_getPassword("Enter new Password", buffer1);
		} while(!done1);

		do {
			done2 = View_getPassword("Confirm new Password", buffer2);
		} while(!done2);

		if (strcmp(buffer1, buffer2) != 0) {
			LCD_clearScreen();
			LCD_displayString("Passwords not match!");
			_delay_ms(LCD_MESSAGE_DELAY);
		}
		else passMatch = TRUE;

	} while(!passMatch);

	strcpy(password, buffer1);
}

void View_enterPassword (uint8 * password) {
	View_getPassword("Enter password", password);
}


void View_confirmPasswordSet(void) {
	LCD_clearScreen();
	LCD_displayString("New password set!");
	_delay_ms(LCD_MESSAGE_DELAY);
}

void View_showHomeDisplay (void (*onOpenDoor) (void), void (*onChangePass) (void)) {
	uint8 key;
	LCD_clearScreen();
	LCD_displayString("+: Open Door.");
	LCD_goToRowCol(1, 0);
	LCD_displayString("-: Change Pass.");
	key = Keypad_getPressedKey();

	if(key == '+') onOpenDoor();
	else if (key == '-') onChangePass();
	else {
		LCD_clearScreen();
		LCD_displayString("Enter valid option");
		_delay_ms(LCD_MESSAGE_DELAY);
	}
}

void View_wrongPassword (void) {
	LCD_clearScreen();
	LCD_displayString("Wrong Password!");
	_delay_ms(LCD_MESSAGE_DELAY);
}

void View_doorOpening (void) {
	LCD_clearScreen();
	LCD_displayString("Door opening...");
}

void View_doorOpened (void) {
	uint8 i;
	for(i = 0; i < 3; i++) {
		LCD_clearScreen();
		LCD_displayString("Door opened!!");
		_delay_ms(500);
	}
	LCD_clearScreen();
	LCD_displayString("Door opened!!");
}

void View_doorClosing (void) {
	uint8 i;
	for(i = 0; i < 3; i++) {
		LCD_clearScreen();
		LCD_displayString("Door closing!!");
		_delay_ms(500);
	}
	LCD_clearScreen();
	LCD_displayString("Door closing!!");
}

void View_doorClosed (void) {
	LCD_clearScreen();
	LCD_displayString("Door closed.");
	_delay_ms(LCD_MESSAGE_DELAY);
}
