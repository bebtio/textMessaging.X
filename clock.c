#include "clock.h"
#include "p24FJ64GA002.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timers.h"
#include "nokiaLCD.h"





//void initClock()
//{
//    initTimer3();
//}
//
//
//
//char* getTimeString()
//{
//    sprintf(time_string, "%02d:%02d:%02d:%d%d", elapsed_time_hours,elapsed_time_minutes,elapsed_time_seconds,elapsed_time_deciseconds,elapsed_time_centiseconds);
//    return(time_string);
//}
//
//void _ISR _T3Interrupt(void)
//{
//    IFS0bits.T3IF = 0;
//
//
//    elapsed_time+=1;
//
//    if(elapsed_time > 9)// max time 99 min 59 sec 999ms
//    {
//        elapsed_time_centiseconds += 1;
//        elapsed_time = 0;
//
//        if(elapsed_time_centiseconds > 9)
//        {
//            elapsed_time_deciseconds += 1;
//            elapsed_time_centiseconds = 0;
//
//            if(elapsed_time_deciseconds > 9)
//            {
//                elapsed_time_seconds += 1;
//                elapsed_time_deciseconds = 0;
//
//                if(elapsed_time_seconds > 59)
//                {
//                    elapsed_time_minutes += 1;
//                    elapsed_time_seconds = 0;
//
//                    if(elapsed_time_minutes > 60)
//                    {
//                        elapsed_time_minutes = 0;
//                        elapsed_time_hours += 1;
//                    }
//                }
//            }
//        }
//
//    }
//}







