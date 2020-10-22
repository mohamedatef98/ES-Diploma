/*
 * view.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "hmi_config.h"
#include "std_types.h"
#include "micro_config.h"

/*
 * Controls The LCD and Keypad to deal with User interaction
 *
 * */
void View_init(void);
void View_enterNewPassword (uint8 * password);
void View_enterPassword (uint8 * password);
void View_confirmPasswordSet (void);
void View_showHomeDisplay (void (*onDoorOpen) (void), void (*onChangePass) (void));
void View_wrongPassword (void);
void View_doorOpening (void);
void View_doorOpened (void);
void View_doorClosing (void);
void View_doorClosed (void);

#endif /* VIEW_H_ */
