#include "menuScreen.h"
#include "nokiaLCD.h"
#include "adc.h"
#include "shared.h"
#include "timers.h"
#include "shortcuts.h"
#include "p24FJ64GA002.h"
#include "ClockMenu.h"
#include "MessagingMenu.h"
#include "MainMenu.h"
#include <string.h>
#include <stdio.h>

//// To save messages in array for sending through radio signal
////strcat(currentInput[cursorPosition[Y_Coordinate]], s);

int exitMenuState = 0;
void initMainMenu()
{
    clearLCD();
    currentMenuState = Main;
    
    while(exitMenuState != 1)
    {
        switch(currentMenuState)
        {
            case Main: displayMainMenu();
                break;
            case Messaging: displayMessageMenu();
                break;
            case PowerOff:
                break;
            case GoBack: 
                break;
            case Time: displayClockMenu();
                break;
        }
    }
}

/******************************************************************************/

void goBackToMainMenu()
{
  
}
// This will notify the rest of the program that the selection button has been pressed.
// The program will then choose whatever character the cursor was hovering over and
// initiate proper action for that character.
void _ISR _CNInterrupt(void)
{
    while(BUTTON == PRESSED);
    boardInterruptFlag(DOWN);
    buttonPressed = 1;

    
}

/******************************************************************************/