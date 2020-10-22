/*
 * eeprom.h
 *
 *  Created on: Oct 14, 2020
 *      Author: engmo
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define EEPROM_TWI_START_ERR 0x01
#define EEPROM_NOT_FOUND_ERR 0x02
#define EEPROM_WRITE_ERR 0x03
#define EEPROM_READ_ERR 0x04

void EEPROM_init(void);

uint8 EEPROM_writeByte(uint16 address, uint8 data);

uint8 EEPROM_readByte(uint16 address, uint8 * data);

#endif /* EEPROM_H_ */
