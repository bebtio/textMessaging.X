/* 
 * File:   passwordScreen.h
 * Author: albertoheras
 *
 * Created on May 31, 2015, 8:39 PM
 */

#ifndef PASSWORDSCREEN_H
#define	PASSWORDSCREEN_H

void initPasswordScreen();
void readPasswordInput();
int exceedsPasswordSize();
void passwordStateTransition();
int compareInputAndPassword();

#endif	/* PASSWORDSCREEN_H */

