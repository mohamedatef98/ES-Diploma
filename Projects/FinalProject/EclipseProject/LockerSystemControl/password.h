/*
 * password.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_

/*
 * Manages the eeprom to manipulate and access the password stored
 * */

void Password_init(void);
void Password_remove(void);
uint8 Password_checkExist(void);
void Password_setPassword(const uint8 * str);
uint8 Password_checkCorrect(const uint8 * str);

#endif /* PASSWORD_H_ */
