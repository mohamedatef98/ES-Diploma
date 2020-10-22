/*
 * main.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */


#include "view.h"
#include "uart.h"
#include "messages.h"

void onDoorOpen (void);

void onChangePass (void);

int main (void) {
	UARTConfig uart = { UART_8_BITS, UART_NO_PARITY, UART_1_STOP_BIT, UART_RX_TX };
	View_init();
	UART_init(&uart);

	/*
	 * At the start of the HMI MCU code.
	 * First, check if the a password has already been set.
	 * By sending a CHECK_PASS_EXISTS request to control MCU.
	 * */
	UART_sendByte(CHECK_PASS_EXISTS);

	/*
	 * If no password exists.
	 * Let the user create one.
	 * And then save it by sending a SET_NEW_PASS request.
	 * */
	if(UART_receiveByte() == PASS_NOT_EXIST) {
		uint8 password[12];
		View_enterNewPassword(password);
		UART_sendByte(SET_NEW_PASS);
		UART_sendString(password);
		if (UART_receiveByte() == NEW_PASS_SET_COMPLETE) View_confirmPasswordSet();
	}

	while(1) {
		/**
		 * Show the home page that asks user either to open door or change password.
		 * and give it pointers to functions to execute when user wants to open door or change password.
		 * */
		View_showHomeDisplay (onDoorOpen, onChangePass);
	}

}


/*
 * When user wants to open door,
 * this function will ask him for the password.
 * if his password is wrong it will show a "Wrong Password" message.
 * If password is correct, the control MCU will open the door.
 * and it will show messages for each phase of door opening.
 * */
void onDoorOpen (void) {
	uint8 buffer[16], response;
	View_enterPassword(buffer);
	UART_sendByte(OPEN_DOOR);
	UART_sendString(buffer);

	response = UART_receiveByte();

	if (response == WRONG_PASS) View_wrongPassword();
	else if (response == DOOR_OPENING) {
		View_doorOpening();
		if (UART_receiveByte() == DOOR_OPEN_DONE) {
			View_doorOpened();
			if (UART_receiveByte() == DOOR_CLOSING) {
				View_doorClosing();
				if (UART_receiveByte() == DOOR_CLOSE_DONE) {
					View_doorClosed();
				}
			}
		}
	}
}

/*
 * When user wants to change password,
 * this function will ask him for the password.
 * if his password is wrong it will show a "Wrong Password" message.
 * If password is correct, it will ask him for new password.
 * and then send the new password to the control MCU.
 * */
void onChangePass (void) {
	uint8 old[16], new[16], response;
	View_enterPassword(old);
	UART_sendByte(CHECK_CORRECT_PASS);
	UART_sendString(old);

	_delay_ms(10);
	response = UART_receiveByte();
	PORTC = response;
	if (response == WRONG_PASS) View_wrongPassword();
	else {
		View_enterNewPassword(new);
		UART_sendByte(SET_NEW_PASS);
		UART_sendString(new);

		if(UART_receiveByte() == NEW_PASS_SET_COMPLETE) View_confirmPasswordSet();
	}
}

