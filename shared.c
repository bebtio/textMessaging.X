#include "shared.h"
/******************************************************************************/

volatile stateType currentState;
volatile currentMenu currentMenuState;
volatile int buttonPressed;
volatile int goBackFlag;
volatile int goBackCount;
volatile int clockCorrection;
volatile int clockMenuEntered;

/******************************************************************************/
// Hold values for the constantly updating time
volatile unsigned int current_time_hours;
volatile unsigned int current_time_minutes;
volatile unsigned int current_time_seconds;
volatile unsigned int current_time_deciseconds;
volatile unsigned int current_time_centiseconds;
volatile unsigned int current_time;
char time_string[11];

/******************************************************************************/
