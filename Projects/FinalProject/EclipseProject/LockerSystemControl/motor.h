/*
 * motor.h
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define MOTOR_POS PB0
#define MOTOR_NEG PB1
#define MOTOR_DDR DDRB
#define MOTOR_PORT PORTB

void Motor_init(void);

void Motor_runWithSpeed(const uint8 speed);

void Motor_reverse(void);

#endif /* MOTOR_H_ */
