/* 
 * File:   shared.h
 * Author: albertoheras
 *
 * Created on May 21, 2015, 9:06 PM
 */

#ifndef SHARED_H
#define	SHARED_H

#define mainMenuChoices 4.0
#define messagingMenuChoices 13.0
#define inputVoltage 3.3
#define mainMenuOptionRange inputVoltage/(mainMenuChoices)
#define messagingMenuOptionRange inputVoltage/(messagingMenuChoices)
#define clockMenuOptionRange inputVoltage/(mainMenuChoices)
#define goBackCountMax 1500

// Keyboard Defines
#define TRUE 1
#define FALSE 0
// Define btton presses
#define PRESSED 0
#define RELEASED 1
#define BUTTON PORTBbits.RB12

// Define ON and OFF
#define ON   1
#define OFF  0

// State variables


typedef enum
{
    InitState,
    InitPasswordState,
    PasswordState,
    WaitState,
    MenuScreensState,
            

} stateType;

typedef enum
{
    Main,
    Messaging = 1,
    Time = 2,
    PowerOff  = 3,
    GoBack  = 5,

} currentMenu;



extern volatile unsigned int current_time_hours;
extern volatile unsigned int current_time_minutes;
extern volatile unsigned int current_time_seconds;
extern volatile unsigned int current_time_deciseconds;
extern volatile unsigned int current_time_centiseconds;
extern volatile unsigned int current_time;
extern char   time_string[11];

extern volatile stateType currentState;
extern volatile currentMenu currentMenuState;
extern volatile int buttonPressed;
extern volatile int goBackFlag;
extern volatile int goBackCount;
extern volatile int clockCorrection;
extern volatile int clockMenuEntered;





#endif	/* SHARED_H */

