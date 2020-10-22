/*
 * eeprom.c
 *
 *  Created on: Oct 14, 2020
 *      Author: engmo
 */

#include "twi.h"
#include "eeprom.h"

#define DELAY() (_delay_ms(10))

void EEPROM_init(void) {
	TWI_init(0);
}

uint8 EEPROM_writeByte(uint16 address, uint8 data) {
	/*
	 * 1. Send Start
	 * 2. Send 1010 + A10,9,8 + R/W = 0
	 * 3. Send A7...0
	 * 4. Send Byte
	 * 5. Send Stop
	 * */
	uint8 addr = (uint8)(0xA0 | ((address & 0x0700) >> 7));
	TWI_start();
	if(TWI_getStatus() != TW_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr);
	if(TWI_getStatus() != TW_MT_SLA_W_ACK) return EEPROM_NOT_FOUND_ERR;

	TWI_write((uint8) address);
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	TWI_write(data);
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	TWI_stop();
	DELAY();

	return 0;

}

uint8 EEPROM_readByte(uint16 address, uint8 * data) {
	/*
	 * 1. Send Start
	 * 2. Send 1010 + A10,9,8 + R/W = 0
	 * 3. Send A7...0
	 * 4. Send Start
	 * 5. Send 1010 + A10,9,8 + R/W = 1
	 * 6. Receive Byte
	 * 7. Send stop
	 * */
	uint8 addr = (uint8)(0xA0 | ((address & 0x0700) >> 7));
	TWI_start();
	if(TWI_getStatus() != TW_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr);
	if(TWI_getStatus() != TW_MT_SLA_W_ACK) return EEPROM_NOT_FOUND_ERR;

	TWI_write((uint8) address);
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	TWI_start();
	if(TWI_getStatus() != TW_REP_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr | 1);
	if(TWI_getStatus() != TW_MT_SLA_R_ACK) return EEPROM_NOT_FOUND_ERR;

	*data = TWI_readWithNACK();
	if(TWI_getStatus() != TW_MR_DATA_NACK) return EEPROM_WRITE_ERR;

	TWI_stop();
	DELAY();

	return 0;
}

uint8 EEPROM_writeString (uint16 address, const uint8 * str) {
	/*
	 * 1. Send Start
	 * 2. Send 1010 + A10,9,8 + R/W = 0
	 * 3. Send A7...0
	 * 4. Send each Byte
	 * 5. send null char
	 * 6. Send Stop
	 * */
	uint8 addr = (uint8) (0xA0 | ((address & 0x0700) >> 7));
	TWI_start();
	if(TWI_getStatus() != TW_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr);
	if(TWI_getStatus() != TW_MT_SLA_W_ACK) return EEPROM_NOT_FOUND_ERR;

	TWI_write((uint8) address);
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	while(*str) {
		TWI_write(*str++);
		if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;
	}
	TWI_write('\0');
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	TWI_stop();
	DELAY();

	return 0;
}

uint8 EEPROM_readString(uint16 address, uint8 * data) {
	/*
	 * 1. Send Start
	 * 2. Send 1010 + A10,9,8 + R/W = 0
	 * 3. Send A7...0
	 * 4. Send Start
	 * 5. Send 1010 + A10,9,8 + R/W = 1
	 * 6. Receive each Byte
	 * 7. Send stop
	 * */
	uint8 addr = (uint8) (0xA0 | ((address & 0x0700) >> 7));

	TWI_start();
	if(TWI_getStatus() != TW_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr);
	if(TWI_getStatus() != TW_MT_SLA_W_ACK) return EEPROM_NOT_FOUND_ERR;

	TWI_write((uint8) address);
	if(TWI_getStatus() != TW_MT_DATA_ACK) return EEPROM_WRITE_ERR;

	TWI_start();
	if(TWI_getStatus() != TW_REP_START) return EEPROM_TWI_START_ERR;

	TWI_write(addr | 1);
	if(TWI_getStatus() != TW_MT_SLA_R_ACK) return EEPROM_NOT_FOUND_ERR;

	while(1) {
		*data = TWI_readWithACK();
		LCD_displayHex(TWI_getStatus());
		if(TWI_getStatus() != TW_MR_DATA_ACK) return EEPROM_WRITE_ERR;

		if(*data++ == '\0') break;
	}

	TWI_stop();
	DELAY();

	return 0;
}
