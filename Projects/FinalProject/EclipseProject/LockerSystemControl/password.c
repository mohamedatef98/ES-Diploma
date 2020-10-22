/*
 * password.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#include "eeprom.h"
#include "password.h"
#include "control_config.h"
#include <string.h>

void Password_remove(void) {
	EEPROM_writeByte(PASS_EXISTS_FLAG_ADDRESS, 0);
}

static void Password_getPassword(uint8 * str) {
	EEPROM_readString(PASS_START_ADDRESS, str);
}

void Password_init(void) {
	EEPROM_init();
}

uint8 Password_checkExist(void) {
	uint8 flag;
	EEPROM_readByte(PASS_EXISTS_FLAG_ADDRESS, &flag);

	return (flag == PASS_EXISTS_FLAG) ? TRUE : FALSE;
}

void Password_setPassword(const uint8 * str) {
	/*
	 * 1. Save the new password.
	 * 2. Set the PASSWORD_EXISTS_FLAG to its proper set value.
	 * */

	EEPROM_writeString(PASS_START_ADDRESS, str);

	EEPROM_writeByte(PASS_EXISTS_FLAG_ADDRESS, PASS_EXISTS_FLAG);
}

uint8 Password_checkCorrect(const uint8 * givenPassword) {
	uint8 fetchedPassword[16];
	uint8 passwordExists = Password_checkExist();

	if(!passwordExists) return FALSE;

	Password_getPassword(fetchedPassword);

	return (strcmp(givenPassword, fetchedPassword) == 0) ? TRUE : FALSE;
}
