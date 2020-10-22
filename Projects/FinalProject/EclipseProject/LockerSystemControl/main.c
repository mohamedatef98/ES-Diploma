/*
 * main.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#include "uart.h"
#include "password.h"
#include "messages.h"
#include "control_config.h"
#include "motor.h"
#include "buzzer.h"
#include "timer1.h"

int main (void) {
	UARTConfig uart = { UART_8_BITS, UART_NO_PARITY, UART_1_STOP_BIT, UART_RX_TX };
	TIMER1Config timer1 = { TIMER1_COM1A_NORMAL, TIMER1_COM1B_NORMAL, TIMER1_NORMAL, TIMER1_CPU_1024 };

	UART_init(&uart);
	TIMER1_init(&timer1);
	Password_init();
	Motor_init();
	Buzzer_init();

	/*Password_remove();*/
	/*Password_setPassword("12345");*/

	while (1) {
		uint8 message;
		message = UART_receiveByte();
		uint8 buffer[16];

		if (message == CHECK_PASS_EXISTS) {
			Password_checkExist() ? UART_sendByte(PASS_EXIST) : UART_sendByte(PASS_NOT_EXIST);
		}
		else if (message == SET_NEW_PASS) {
			UART_receiveString(buffer);
			Password_setPassword(buffer);
			UART_sendByte(NEW_PASS_SET_COMPLETE);
		}
		else if (message == CHECK_CORRECT_PASS) {
			UART_receiveString(buffer);
			Password_checkCorrect(buffer) ? UART_sendByte(CORRECT_PASS) : UART_sendByte(WRONG_PASS);
		}
		else if (message == OPEN_DOOR) {
			UART_receiveString(buffer);
			if (Password_checkCorrect(buffer)) {
				UART_sendByte(DOOR_OPENING);
				Buzzer_buzz();
				Motor_runWithSpeed(128);
				TIMER1_count10sec();

				UART_sendByte(DOOR_OPEN_DONE);
				Motor_runWithSpeed(0);
				TIMER1_count10sec();

				UART_sendByte(DOOR_CLOSING);
				Motor_reverse();
				Motor_runWithSpeed(128);
				TIMER1_count10sec();

				Motor_reverse();
				Motor_runWithSpeed(0);
				Buzzer_unBuzz();
				UART_sendByte(DOOR_CLOSE_DONE);
			}
			else UART_sendByte(WRONG_PASS);
		}
	}
}
