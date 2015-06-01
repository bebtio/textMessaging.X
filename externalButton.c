#include "externalButton.h"
#include "p24FJ64GA002.h"
#include "shared.h"

/*****************************************************************************/

void initExternalButton1()
{
    TRISAbits.TRISA0 = 1;       // Set Pin2 as input
    AD1PCFGbits.PCFG0 = 1;      // Analog input enable
    CNPU1bits.CN2PUE = 1;       // Pull Up resistor
    IEC1bits.CNIE = 1;          // interrupt enable for board
    CNEN1bits.CN2IE = 1;        // interrupt enable for the pin
    IFS1bits.CNIF = 0;          // interrupt flag down
}

/*****************************************************************************/

unsigned int inputbuttonisPressed()
{
    if(inputButton == PRESSED)
    {
        return(PRESSED);
    }
    else
    {
        return(RELEASED);
    }
}

/*****************************************************************************/
