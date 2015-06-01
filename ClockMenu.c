#include "ClockMenu.h"
#include "nokiaLCD.h"
#include "shared.h"
#include "p24FJ64GA002.h"
#include "timers.h"
#include <stdio.h>
#include <stdlib.h>
#include "menuScreen.h"

/********************************************************************************/

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
    
    initTimer3();

}

/********************************************************************************/

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
void displayClockMenu()
{
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

char* getTimeString()
{
    sprintf(time_string, "%02d:%02d:%02d:%d%d", current_time_hours,current_time_minutes,current_time_seconds,current_time_deciseconds,current_time_centiseconds);
    return(time_string);
}


/********************************************************************************/

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


// Tells the robot how long it has been sitting in front of an obstacle, if the
// time is greater than a predefined amount, the robot go to the turnAroundState.
void _ISR _T4Interrupt(void)
{

    IFS1bits.T4IF = 0;

    if(goBackCount >= goBackCountMax)
    {
        goBackFlag = 1;
        T4CONbits.TON = 0;
    }
}

/********************************************************************************/