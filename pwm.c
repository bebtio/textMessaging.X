#include "pwm.h"
#include "genDefines.h"


/*
 * File:   PWM.c
 * Author: albertoheras, thomasmay,timothyleunsman, xinranfang
 *
 *
 */
#include "p24FJ64GA002.h"

#define FCY 14745600.0
#define TTOT .001
#define PRVAL (((TTOT*FCY)/(1)) - 1.0)
#define SIMPLEPWMMODE 0b0110

#define OCM_1 18

/************************************************************************************/
// Initializes the PWM module

void initPWM(){

    AD1PCFGbits.PCFG12 = 1;
    IO_P24 = input;
    V_P24 = V_HIGH;

    TMR2 = 0;               // Resets Timer 2
    T2CONbits.TCKPS = 0b00; // prescalar of 1 for more acurrate output
    PR2 = PRVAL;            // Sets PRVAL

    // Initialize duty cycle to zero
    OC1R = 0;
    OC1RS = 0;

    // Selects Timer 2
    OC1CONbits.OCTSEL = 0;

    // Sets Simple PWM Mode
    OC1CONbits.OCM = SIMPLEPWMMODE;

    // Right Motor
    RPOR1bits.RP3R = OCM_1;   // map OC1 to pin H-BRIDGE/PIC246 = 15/24

    // Turn on Timer2
    T2CONbits.TON = 1;
    // Set duty Cycles to zero.
    setDutyCycleOCM1(.95);

}


// Sets or changes the current duty cycle to corresponding Output Compare Module
/************************************************************************************/

void setDutyCycleOCM1(float dutyCycle)
{
    OC1RS = PRVAL*dutyCycle;
}

/************************************************************************************/

