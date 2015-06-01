#include "MessagingMenu.h"
#include "nokiaLCD.h"
#include "shared.h"
#include "p24FJ64GA002.h"
#include "timers.h"
#include <stdio.h>
#include <string.h>
#include "adc.h"
#include "menuScreen.h"

/********************************************************************************/

// Defines the upper and lower bounds of the messageMenuOptions array.
#define MESSAGE_MENU_INDEX_MAX 3
#define MESSAGE_MENU_INDEX_MIN 1
// To save messages in array for sending through radio signal
//strcat(currentInput[cursorPosition[Y_Coordinate]], s);

/********************************************************************************/

int cursorHighlightMessagingMenu = -1;
int cursorMessagePosition[2] ={0,2};
int messageMenuIndex = 1;
char *messagingMenuOptions[] =
{
    "---MESSAGE---",
    "<ABCDEF GHIJ>",
    "<KLMNOP QRST>",
    "<UVWXYZ .!?'>"
};

/********************************************************************************/

void displayMessageMenu()
{
    //goBackToMainMenu();
    getCursorHighlightStateforMessaging();
    initMessageMenuText();
    UpdateMessageMenuText();
}

/********************************************************************************/

void initMessageMenuText()
{
    int i = 0, j = 0;

    for(i = 0; i < 2; i++)
    {
        moveCursorLCD(0,i);
        for(j = 0; j < strlen(messagingMenuOptions[i]); j++)
        {
            if(cursorHighlightMessagingMenu == j && i != 0)
            {
                writeInvertedCharLCD(messagingMenuOptions[messageMenuIndex][j]);
            }
            else if(i == 0)
            {
                writeCharLCD(messagingMenuOptions[i][j]);
            }
            else
            {
                writeCharLCD(messagingMenuOptions[messageMenuIndex][j]);
            }
        }
    }
}

/********************************************************************************/

void UpdateMessageMenuText()
{
     if(buttonPressed)
    {
        buttonPressed = 0;
        delayMs(20);
        if(cursorHighlightMessagingMenu == 0 || cursorHighlightMessagingMenu == 12)
        {
            if(cursorHighlightMessagingMenu == 0)
            {
                messageMenuIndex++;
            }
            else
            {
                messageMenuIndex--;
            }

            if(messageMenuIndex > MESSAGE_MENU_INDEX_MAX)
            {
                messageMenuIndex = MESSAGE_MENU_INDEX_MIN;
            }
            else if(messageMenuIndex < MESSAGE_MENU_INDEX_MIN)
            {
                messageMenuIndex = MESSAGE_MENU_INDEX_MAX;
            }
        }
        else
        {
            moveCursorLCD(cursorMessagePosition[0],cursorMessagePosition[1]);
            writeCharLCD(messagingMenuOptions[messageMenuIndex][cursorHighlightMessagingMenu]);
            cursorMessagePosition[0] += 6;
            if(cursorMessagePosition[0] >= 84)
            {
                cursorMessagePosition[1] += 1;
                cursorMessagePosition[0] = 0;
            }
        }

     }
}

/********************************************************************************/

void getCursorHighlightStateforMessaging()
{
    int i = 0;
    float currentInput = getADCBuffVal();

    for(i = 0; i < messagingMenuChoices; i++)
    {
        if( (currentInput > (i*messagingMenuOptionRange)) && (currentInput < (messagingMenuOptionRange*(i+1))) )
        {
                cursorHighlightMessagingMenu = i;

        }
    }

}

/********************************************************************************/