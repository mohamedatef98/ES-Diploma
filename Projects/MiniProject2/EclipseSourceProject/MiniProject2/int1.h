/*
 * int1.h
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#ifndef INT1_H_
#define INT1_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum {
	INT1_LOW, INT1_ANY, INT1_FALL, INT1_RISE
} INT1SenseControlConfig;

void INT1_init(const INT1SenseControlConfig sc);

void INT1_setCallback(void (*func)(void));

#endif /* INT1_H_ */
