#include "MainMenu.h"
#include "shared.h"
#include "adc.h"
#include "nokiaLCD.h"
#include <stdio.h>
#include <string.h>
#include "timers.h"
// Controls the flow of the program between its main functionalities.

/********************************************************************************/
// List of menu options
char *mainMenuOptions[] =
{
    "---MAINMENU---",
    "MESSAGE",
    "TIME",
    "LOCATION",
    "POWEROFF",
    "BACK"
};

int cursorHighlightMainMenu = -1;

/********************************************************************************/

void displayMainMenu()
{
    getCursorHighlightStateMainMenu();
    initMainMenuText();
    updateMainMenuText();
}

/********************************************************************************/

void initMainMenuText()
{
    int i = 0, j = 0;

    for(i = 0; i <= mainMenuChoices; i++)
    {
        moveCursorLCD(0,i);
        for(j = 0; j < strlen(mainMenuOptions[i]); j++)
        {
            if(cursorHighlightMainMenu == i)
            {
                writeInvertedCharLCD(mainMenuOptions[i][j]);
            }
            else
            {
                writeCharLCD(mainMenuOptions[i][j]);
            }
        }
    }
}

/********************************************************************************/

void updateMainMenuText()
{
    if(buttonPressed)
    {
        buttonPressed = 0;
        delayMs(20);
        clearLCD();
        delayMs(20);
        if(cursorHighlightMainMenu == Messaging)
        {
            currentMenuState = Messaging;
        }
        else if(cursorHighlightMainMenu == Time)
        {
            currentMenuState = Time;
        }
        else if(cursorHighlightMainMenu == PowerOff)
        {
            currentMenuState = PowerOff;
        }
        else if(cursorHighlightMainMenu == GoBack)
        {
            currentMenuState = GoBack;
        }
    }
}

/********************************************************************************/

void getCursorHighlightStateMainMenu()
{
    int i = 0;
    float currentInput = getADCBuffVal();

    for(i = 0; i < mainMenuChoices; i++)
    {
        if( (currentInput > (i*mainMenuOptionRange)) && (currentInput < (mainMenuOptionRange*(i+1))) )
        {
            cursorHighlightMainMenu = i + 1;

        }
    }
}

/********************************************************************************/
