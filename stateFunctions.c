#include "stateFunctions.h"
#include "nokiaLCD.h"
#include "pwm.h"
#include "shared.h"
#include "spiInit.h"
#include "p24FJ64GA002.h"
#include "timers.h"
#include "nokiaLCD.h"
#include "menuScreen.h"
#include "adc.h"
#include "selectorButton.h"
#include "ClockMenu.h"
#include "passwordScreen.h"

/******************************************************************************/

void initState()
{
    initSPI();
    initLCD();
    initADC();
    initSelectorButton1();
    initClock();
    clearLCD();

    buttonPressed   = 0;
    goBackFlag      = 0;
    goBackCount     = 0;
    clockCorrection = 0;
    clockMenuEntered= 0;
    currentState = InitPasswordState;
}

/******************************************************************************/

void waitState()
{
    
}

/******************************************************************************/

void menuScreensState()
{
    initMainMenu();
}

/******************************************************************************/

void initPasswordState()
{
    initPasswordScreen();
}

/******************************************************************************/

void passwordState()
{
    readPasswordInput();
}

/******************************************************************************/