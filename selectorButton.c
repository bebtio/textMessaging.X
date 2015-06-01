#include "shared.h"
#include "p24FJ64GA002.h"
#include "shortcuts.h"

/*****************************************************************************/
// This enables hte bits for making a push button to make selections.
void initSelectorButton1()
{
    IPC4bits.CNIP = 1;
    pinMode(23, input);
    setDigital(23);
    enablePullUp(23,ON);
    enableBoardCN(ON);
    enablePinCN(23,ON);
    boardInterruptFlag(DOWN);
    
}

/******************************************************************************/