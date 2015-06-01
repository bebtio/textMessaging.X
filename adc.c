#include "adc.h"
#include "shared.h"
#include "menuScreen.h"
#include "p24FJ64GA002.h"
#include "shortcuts.h"
#define convert(x)  (x/1023.0)*3.3



/******************************************************************************/

// Initializes the ADC to read an analog voltage from the potentiometer
void initADC()
{
    // These set corresponding pins as analog inputs
    setAnalog(6);
    pinMode(6,input);
    

    // The select lines for ADC conversion, will read the uncommented pins in ascending order.
    AD1CSSLbits.CSSL4 = 1; // PIN3 ON PIC

    AD1CON1bits.FORM = 0;       // Output formatted as an integer
    AD1CON1bits.SSRC = 0b0111;  // Auto internal clock usage
    AD1CON1bits.ASAM = 0;       // Auto start sampling

    AD1CON2bits.VCFG = 0;       // Uses system voltage for reference voltages
    AD1CON2bits.CSCNA = 1;      // Uses CH0SA bits as MUXA input, inputs only work on MUXA
    AD1CON2bits.SMPI = 0b1111;  // Interrupt at 16th sample convert sequence
    AD1CON2bits.ALTS = 0;       // Always uses MUXA input multiplexor settings

    AD1CON3bits.ADRC = 0;       // Uses system clock for conversions
    AD1CON3bits.SAMC = 1;       // 1 = use TAD
    AD1CON3bits.ADCS = 10;      // Clock period select bits = 10 so *FCY
    AD1CHS = 0;                 // Connect pin as positive input: AN0
    AD1CON1bits.ADON = 1;       // Turn on A/D

    IFS0bits.AD1IF = 0;         //Put the flag down
}


/******************************************************************************/

// Takes value from the ADC buffer and returns that value
float getADCBuffVal()
{
    int i = 0;

    // These will hold the voltage reading from each of the buffers in the PIC
    float ADCReading[16];
    int *ADCBuffVal;
    ADCBuffVal = &ADC1BUF0;
    float total = 0;


    IFS0bits.AD1IF = 0;         // Puts A/D flag down
    AD1CON1bits.ASAM = 1;      // Starts Auto Sampling
    while (!IFS0bits.AD1IF){};  // Waits for sampling to finish
    AD1CON1bits.ASAM = 0;     // Stops sampling

    for(i = 0; i < 16; i++)
    {
        ADCReading[i] = *ADCBuffVal++;
        total += ADCReading[i];
    }

    total /= 16.0;
    total = convert(total);
    return(total);
}

/******************************************************************************/

