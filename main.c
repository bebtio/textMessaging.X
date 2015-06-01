/* 
 * File:   main.c
 * Author: albertoheras
 *
 * Created on May 20, 2015, 8:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "p24FJ64GA002.h"
#include "stateFunctions.h"
#include "spi.h"
#include "spiInit.h"
#include "shared.h"
#include "menuScreen.h"


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

/********************************************************************************/
// An FSM modeled with switch statements.
int main(int argc, char** argv) {
					
    while(1)
    {

        switch(currentState)
        {
            case InitState: initState();
                break;
            case InitPasswordState: initPasswordState();
                break;
            case PasswordState: passwordState();
                break;
            case MenuScreensState:  menuScreensState();
                break;
            case WaitState: waitState();
                break;
        }
    }
    return (EXIT_SUCCESS);
}

/********************************************************************************/

