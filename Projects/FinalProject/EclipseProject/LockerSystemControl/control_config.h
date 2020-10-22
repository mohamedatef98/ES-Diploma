/*
 * control_config.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#ifndef CONTROL_CONFIG_H_
#define CONTROL_CONFIG_H_

/*
 * Contains Control MCU configuration constants
 * */

/*
 * We use 1 byte to store a flag that indicates that a password has been set
 * and max 16 bytes to store the actual password
 * */
#define PASS_EXISTS_FLAG 'A'
#define PASS_EXISTS_FLAG_ADDRESS ((uint16) 0)
#define PASS_START_ADDRESS ((uint16) 1)

#define DOOR_OPEN_CLOSE_DELAY 2000


#endif /* CONTROL_CONFIG_H_ */
