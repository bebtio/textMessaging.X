#include "ClockMenu.h"
#include "nokiaLCD.h"
#include "shared.h"
#include "p24FJ64GA002.h"
#include "timers.h"
#include <stdio.h>
#include <stdlib.h>
#include "menuScreen.h"

// This is a cheap version of a clock, it becomes off by 3 minutes every eight hours
// when I do it.  Your results may vary.
// I tried to use the RTCC module internal to the microcontroller but couldn't get it
// to work properly.  I'll leave it like this until I can figure it out.

/********************************************************************************/
// This will be the "parts" to build the clock menu scree.
char *clockMenuOptions[] =
{
    "|----TIME----|",
    "|            |",
    "|------------|"
};

/********************************************************************************/

void initClock()
{
    // Enter Current Time Here
    current_time_hours   = 2;
    current_time_minutes = 8;
    current_time_seconds = 50;

    // The timer that will update time from entered start.
    initTimer3();

}

/********************************************************************************/
// Sets up the display for the clock.
void initClockMenu()
{
    moveCursorLCD(0,0);
    writeStringLCD(clockMenuOptions[0]);
    moveCursorLCD(0,1);
    writeStringLCD(clockMenuOptions[1]);
    moveCursorLCD(0,2);
    writeStringLCD(clockMenuOptions[1]);
    moveCursorLCD(0,3);
    writeStringLCD(clockMenuOptions[1]);
    moveCursorLCD(0,4);
    writeStringLCD(clockMenuOptions[1]);
    moveCursorLCD(0,5);
    writeStringLCD(clockMenuOptions[2]);
    clockMenuEntered = 1;
}

/********************************************************************************/
// Displays the time and date, updating the changes.
void displayClockMenu()
{
    // Helps in updating only text that is acutually changing.
    if(clockMenuEntered == 0)
    {
        initClockMenu();
    }

    moveCursorLCD(9,2);
    writeStringLCD(getTimeString());
    moveCursorLCD(6,3);
    writeStringLCD("!!The Date!!");
}

/********************************************************************************/
// Returns the time as a string.
char* getTimeString()
{
    sprintf(time_string, "%02d:%02d:%02d:%d%d", current_time_hours,current_time_minutes,current_time_seconds,current_time_deciseconds,current_time_centiseconds);
    return(time_string);
}


/********************************************************************************/
// Using timer3 keeps track of how much time has passed since start.
void _ISR _T3Interrupt(void)
{
    IFS0bits.T3IF = 0;

    current_time+=1;


    if(current_time > 9)// max time 99 min 59 sec 999ms
    {
        current_time_centiseconds += 1;
        current_time = 0;

        if(current_time_centiseconds > 9)
        {
            current_time_deciseconds += 1;
            current_time_centiseconds = 0;

            if(current_time_deciseconds > 9)
            {
                current_time_seconds += 1;
                current_time_deciseconds = 0;

                if(current_time_seconds > 59)
                {
                    current_time_minutes += 1;
                    current_time_seconds = 0;

                    if(current_time_minutes > 60)
                    {
                        current_time_minutes = 0;
                        current_time_hours += 1;
                    }
                    if(current_time_hours > 23)
                    {
                        current_time_hours = 0;
                    }
                }
            }
        }
    }

}

/********************************************************************************/