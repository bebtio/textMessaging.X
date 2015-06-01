#include "keyboard.h"
#include "adc.h"
#include "shared.h"
#include "nokiaLCD.h"
#include <stdlib.h>
#include <string.h>

#define keyBoardArraySize 14.0
#define charsSelectionRange (inputVoltage/keyBoardArraySize)
#define KEYBOARD_INDEX_MAX 2
#define KEYBOARD_INDEX_MIN 0

struct keyboard
{
    char *Characters[(int)keyBoardArraySize];
    unsigned int CursorPosition:4; //only need 4 bits to represent 14 positions
    unsigned int ArrayRow:2;//Only need 2 bits to represent 3 rows.
} 

KeyBoard =
{  
    { // Initialization of KeyboardCharactes
    "<ABCDEF GHIJ>|",
    "<KLMNOP QRST>|",
    "<UVWXYZ .!?'>|"
    }
    // Initialization of columns and rows.
    ,0,0
};
    

void displayKeyboard(int rowToBeDisplayed)
{
    int i = 0, j = 0;
 
    moveCursorLCD(0,rowToBeDisplayed);
    for(j = 0; j < strlen(KeyBoard.Characters[i]); j++)
    {
        if(KeyBoard.CursorPosition == j)
        {
            writeInvertedCharLCD(KeyBoard.Characters[KeyBoard.ArrayRow][j]);
        }
        else
        {
            writeCharLCD(KeyBoard.Characters[KeyBoard.ArrayRow][j]);
        }
    }
    highlightChar();
}

/********************************************************************************/

void highlightChar()
{
    int i = 0;
    float currentInput = getADCBuffVal();

    for(i = 0; i < (int)keyBoardArraySize; i++)
    {
        if( (currentInput > (i*charsSelectionRange)) && (currentInput < (charsSelectionRange*(i+1))) )
        {
                KeyBoard.CursorPosition = i;
        }
    }

}

/********************************************************************************/

char getHighlightedChar()
{
    int isCharReturned = FALSE;

    if(buttonPressed == TRUE)
    {
        buttonPressed = FALSE;
        if(KeyBoard.CursorPosition == 0)
        {
              KeyBoard.ArrayRow -= 1;
              if(KeyBoard.ArrayRow < KEYBOARD_INDEX_MIN)
              {
                  KeyBoard.ArrayRow = KEYBOARD_INDEX_MAX;
              }
        }
        else if(KeyBoard.CursorPosition == 12)
        {
              KeyBoard.ArrayRow += 1;
              if(KeyBoard.ArrayRow > KEYBOARD_INDEX_MAX)
              {
                  KeyBoard.ArrayRow = KEYBOARD_INDEX_MIN;
              }
        }
        else
        {
            displayKeyboard(5);
            buttonPressed = FALSE;
            isCharReturned = TRUE;
        }
    }

    if(isCharReturned == TRUE)
    {
        return(KeyBoard.Characters[KeyBoard.ArrayRow][KeyBoard.CursorPosition]);
    }
    else
    {
        return(NULL);
    }
}