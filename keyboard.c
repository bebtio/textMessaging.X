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
#define MOVE_LEFT 0
#define MOVE_RIGHT 12
#define DISPLAY_ROW 5
// This is the keyboard. This displays the keyboard and returns a char only.
// Lets me use it across multiple files.

/*****************************************************************************/

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

/*****************************************************************************/
// Displays the currently selectable keys on a single row. Row can be set to values
// 1 - 5.
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
// Depending on the positino of the potentiometer, one char from the keyboard will
// be highlighted, this calcuates which char that is.
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
// Returns the char that is currently highlighted if the pushBotton is pressed.
char getHighlightedChar()
{
    int isCharReturned = FALSE;

    if(buttonPressed == TRUE)
    {
        buttonPressed = FALSE;
        if(KeyBoard.CursorPosition == MOVE_LEFT)
        {
              KeyBoard.ArrayRow -= 1;
              if(KeyBoard.ArrayRow < KEYBOARD_INDEX_MIN)
              {
                  KeyBoard.ArrayRow = KEYBOARD_INDEX_MAX;
              }
        }
        else if(KeyBoard.CursorPosition == MOVE_RIGHT)
        {
              KeyBoard.ArrayRow += 1;
              if(KeyBoard.ArrayRow > KEYBOARD_INDEX_MAX)
              {
                  KeyBoard.ArrayRow = KEYBOARD_INDEX_MIN;
              }
        }
        else
        {
            displayKeyboard(DISPLAY_ROW);
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

/*****************************************************************************/