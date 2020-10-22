/*
 * TWI.h
 *
 *  Created on: Oct 14, 2020
 *      Author: engmo
 */

#ifndef TWI_H_
#define TWI_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define TW_BR 0x01
#define TW_PS 0x00

#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

void TWI_init(const uint8 deviceAddress);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(const uint8 data);
uint8 TWI_readWithACK(void);
uint8 TWI_readWithNACK(void);
uint8 TWI_getStatus(void);


#endif /* TWI_H_ */
