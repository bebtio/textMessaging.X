#include "passwordScreen.h"
#include "keyboard.h"
#include "shared.h"
#include <stdlib.h>
#include <string.h>
#include "nokiaLCD.h"
#include "timers.h"

// The maximum size allowed for a password
#define MAX_PASSWORD_SIZE 10


const char password[5] = "ABCDE";   // The actual password
char userInput[15];                 // Will hold the users input for the password
int userInputIndex = 0;             // The current number of chars the user has input so far
const int charWidth = 6;            // How many pixels a single char takes on the lcd screen

/************************************************************************************************/

void initPasswordScreen()
{

    userInputIndex = 0;                         // Begin at index zero
    while(userInput[userInputIndex] != '\0')    // Initializes values of input array just in case.
    {
        userInput[userInputIndex] = '\0';
        userInputIndex++;
    }

    userInputIndex = 0;                         // Reset the index
    moveCursorLCD(0,0);                         // Put the cursor in the starting position
    writeStringLCD("Password:");
    currentState = PasswordState;               // Go to the password state
}

/************************************************************************************************/
// Reads character input from potentiometer
void readPasswordInput()
{
    displayKeyboard(5);                             // Display valid inputs on Row 5 of LCD
    char input = getHighlightedChar();                 // If there was a selections, a char will be pushed into input
    if(input != NULL && userInputIndex < MAX_PASSWORD_SIZE)
    {
        moveCursorLCD((userInputIndex*charWidth),3);// Move the Cursor to 3rd row
        userInput[userInputIndex] = input;
        writeCharLCD(input);
        userInputIndex += 1;
    }

    passwordStateTransition();                      // Check Whether password is right or wrong
}

/************************************************************************************************/
// Checks if a transition should occur based on input
void passwordStateTransition()
{
    int toMenuScreenState = FALSE;
    int toInitPasswordState = FALSE;

    toMenuScreenState = compareInputAndPassword(); // If the password and user input match, go to the menuScreen
    toInitPasswordState = exceedsPasswordSize();       // If the size of the user input exceeds the max password size, give retry

    if(toMenuScreenState == TRUE)
    {
        currentState = MenuScreensState;
    }

    if(toInitPasswordState == TRUE)
    {
        currentState = InitPasswordState;
    }
}

/************************************************************************************************/
// Checks if user input exceeds allowable password size.
// Gives error message.
int exceedsPasswordSize()
{
    int doesExceed = FALSE;
    if(strlen(userInput) >= MAX_PASSWORD_SIZE)
    {
        clearLCD();
        moveCursorLCD(0,1);
        writeCenteredStringLCD("Wrong!!");
        moveCursorLCD(0,4);
        writeCenteredStringLCD("Try Again!!");
        delaySeconds(2);
        clearLCD();

        doesExceed = TRUE;
    }

    return(doesExceed);
}

/************************************************************************************************/

int compareInputAndPassword()
{
    int isCorrect = FALSE;
    if(strcmp(password,userInput) == 0)
    {
        isCorrect = TRUE;
    }
    return(isCorrect);
}