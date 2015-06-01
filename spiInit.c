#include "spiInit.h"
#include "p24FJ64GA002.h"

void initSPI()
{
    init_SPI2();
}

/******************************************************************************/

void init_SPI2(void)
{

  IFS2bits.SPI2IF = 0;  // Put Interrupt Flag Down
  IEC2bits.SPI2IE = 1;  // Enable the interrupt
  IPC8bits.SPI2IP = 4;  // Set interrupt priority

  //   SPI1CON1 setting
  SPI2CON1bits.DISSCK   = 0;        // Internal SPI clock enable
  SPI2CON1bits.DISSDO   = 0;        // SDO pin is controlled by the module
  SPI2CON1bits.MODE16   = 0;        // 8 bits wide
  SPI2CON1bits.SMP      = 0;        // input data sampled at the middle of data ouput time
  SPI2CON1bits.CKE      = 0;        // from idle clock to active clock
  SPI2CON1bits.SSEN     = 0;        // SSx pin not used by the module
  SPI2CON1bits.CKP      = 0;        // idle state clock is low level
  SPI2CON1bits.MSTEN    = 1;        // master mode
  SPI2CON1bits.SPRE     = 0b00;     // secondary prescal 8:1
  SPI2CON1bits.PPRE     = 0b00;     // primary prescale 1:1

  // Fsck = (FCY 14745600.0)/(Primary*Secondary Prescalars)

// SPI1CON2 setting
  SPI2CON2bits.FRMEN    = 0;    // framed SPI support disabled
  SPI2CON2bits.SPIFSD   = 0;    // frame sync pulse output Master
  SPI2CON2bits.SPIFPOL  = 0;    // framesync pulse is active low
  SPI2CON2bits.SPIFE    = 0,    // framesync pulse precedes first bit clock
  SPI2CON2bits.SPIBEN   = 0;    // enhanced buffer disable

// SPI1STAT setting
 SPI2STATbits.SPIEN     = 1;    // enable spi
 SPI2STATbits.SPISIDL   = 0;    // continue module operation in idle mode
 SPI2STATbits.SPIROV    = 0;    // no overflow has occured


}

/******************************************************************************/

void write_SPI2(short command)
{
    short temp;
    temp = SPI2BUF;			// dummy read of the SPI1BUF register to clear the SPIRBF flag
    SPI2BUF = command;                  // write the data out to the SPI peripheral
    while (!SPI2STATbits.SPIRBF);	// wait for the data to be sent out
}

/******************************************************************************/

void __attribute__((interrupt,no_auto_psv)) _SPI2Interrupt(void)
{
    
  IFS2bits.SPI2IF = 0;      //Clear Interrupt status of SPI2
  IEC2bits.SPI2IE = 1;

}

/******************************************************************************/