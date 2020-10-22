/*
 * requests.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#ifndef MESSAGES_H_
#define MESSAGES_H_

/***************************************************
 * Standards the messages that the HMI MCU and the Control MCU will transfer
 * */

#define CHECK_PASS_EXISTS 1
#define PASS_EXIST 2
#define PASS_NOT_EXIST 3
#define SET_NEW_PASS 4
#define NEW_PASS_SET_COMPLETE 5
#define CHECK_CORRECT_PASS 6
#define CORRECT_PASS 7
#define WRONG_PASS 8
#define OPEN_DOOR 9
#define DOOR_OPENING 10
#define DOOR_OPEN_DONE 11
#define DOOR_CLOSING 12
#define DOOR_CLOSE_DONE 13


#endif /* MESSAGES_H_ */
