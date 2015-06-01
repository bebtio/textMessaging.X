/*
 * File:   genDefines.h
 * Author: albertoheras
 *
 * Created on May 17, 2015, 1:42 PM
 */
#include "p24FJ64GA002.h"

#ifndef GENDEFINES_H
#define	GENDEFINES_H
/********************************************************************/
// These SFR control whether a pin is an input or an output.


#define input  1
#define output 0

#define IO_P2  TRISAbits.TRISA0
#define IO_P3  TRISAbits.TRISA1
#define IO_P4  TRISBbits.TRISB0
#define IO_P5  TRISBbits.TRISB1
#define IO_P6  TRISBbits.TRISB2
#define IO_P7  TRISBbits.TRISB3

#define IO_P9  TRISAbits.TRISA2
#define IO_P10 TRISAbits.TRISA3
#define IO_P11 TRISBbits.TRISB4
#define IO_P12 TRISAbits.TRISA4

#define IO_P14 TRISBbits.TRISB5
#define IO_P15 TRISBbits.TRISB6
#define IO_P16 TRISBbits.TRISB7
#define IO_P17 TRISBbits.TRISB8
#define IO_P18 TRISBbits.TRISB9
#define IO_P21 TRISBbits.TRISB10
#define IO_P22 TRISBbits.TRISB11
#define IO_P23 TRISBbits.TRISB12
#define IO_P24 TRISBbits.TRISB13
#define IO_P25 TRISBbits.TRISB14
#define IO_P26 TRISBbits.TRISB15

/********************************************************************/
// These SFR control the the ouput value of each pin

// Defines for Outputting v_h = high voltage
// and v_l = low voltage
#define V_HIGH    1
#define V_LOW    0

#define V_P2  LATAbits.LATA0
#define V_P3  LATAbits.LATA1
#define V_P4  LATBbits.LATB0
#define V_P5  LATBbits.LATB1
#define V_P6  LATBbits.LATB2
#define V_P7  LATBbits.LATB3

#define V_P9  LATAbits.LATA2
#define V_P10 LATAbits.LATA3
#define V_P11 LATBbits.LATB4
#define V_P12 LATAbits.LATA4

#define V_P14 LATBbits.LATB5
#define V_P15 LATBbits.LATB6
#define V_P16 LATBbits.LATB7
#define V_P17 LATBbits.LATB8
#define V_P18 LATBbits.LATB9
#define V_P21 LATBbits.LATB10
#define V_P22 LATBbits.LATB11
#define V_P23 LATBbits.LATB12
#define V_P24 LATBbits.LATB13
#define V_P25 LATBbits.LATB14
#define V_P26 LATBbits.LATB15


/********************************************************************/
// These SFR are used to view the current value on the pin.

#define Read_P2  PORTAbits.RA0
#define Read_P3  PORTAbits.RA1
#define Read_P4  PORTBbits.RB0
#define Read_P5  PORTBbits.RB1
#define Read_P6  PORTBbits.RB2
#define Read_P7  PORTBbits.RB3

#define Read_P9  PORTAbits.RA2
#define Read_P10 PORTAbits.RA3
#define Read_P11 PORTBbits.RB4
#define Read_P12 PORTAbits.RA4

#define Read_P14 PORTBbits.RB5
#define Read_P15 PORTBbits.RB6
#define Read_P16 PORTBbits.RB7
#define Read_P17 PORTBbits.RB8
#define Read_P18 PORTBbits.RB9
#define Read_P21 PORTBbits.RB10
#define Read_P22 PORTBbits.RB11
#define Read_P23 PORTBbits.RB12
#define Read_P24 PORTBbits.RB13
#define Read_P25 PORTBbits.RB14
#define Read_P26 PORTBbits.RB15


/********************************************************************/
// These SFR are used to change the pins to ODCs.

#define ODC_ON 1
#define ODC_OFF 0

#define ODC_P2  ODCAbits.ODA0
#define ODC_P3  ODCAbits.ODA1
#define ODC_P4  ODCBbits.ODB0
#define ODC_P5  ODCBbits.ODB1
#define ODC_P6  ODCBbits.ODB2
#define ODC_P7  ODCBbits.ODB3

#define ODC_P9  ODCAbits.ODA2
#define ODC_P10 ODCAbits.ODA3
#define ODC_P11 ODCBbits.ODB4
#define ODC_P12 ODCAbits.ODA4

#define ODC_P14 ODCBbits.ODB5
#define ODC_P15 ODCBbits.ODB6
#define ODC_P16 ODCBbits.ODB7
#define ODC_P17 ODCBbits.ODB8
#define ODC_P18 ODCBbits.ODB9
#define ODC_P21 ODCBbits.ODB10
#define ODC_P22 ODCBbits.ODB11
#define ODC_P23 ODCBbits.ODB12
#define ODC_P24 ODCBbits.ODB13
#define ODC_P25 ODCBbits.ODB14
#define ODC_P26 ODCBbits.ODB15

/********************************************************************/
// These SFR are used to change the pins to analog pins.

#define AD_ON 1
#define AD_OFF 0

#define AD_P2  AD1PCFGbits.PCFG0
#define AD_P3  AD1PCFGbits.PCFG1
#define AD_P4  AD1PCFGbits.PCFG2
#define AD_P5  AD1PCFGbits.PCFG3
#define AD_P6  AD1PCFGbits.PCFG4
#define AD_P7  AD1PCFGbits.PCFG5
#define AD_P23 AD1PCFGbits.PCFG12
#define AD_P24 AD1PCFGbits.PCFG11
#define AD_P25 AD1PCFGbits.PCFG10
#define AD_P26 AD1PCFGbits.PCFG9


/********************************************************************/
// These SFR control the change notification enable of each pin.

#define CN_ON 1
#define CN_OFF 0

#define CN_P2  CNEN1bits.CN2IE
#define CN_P3  CNEN1bits.CN3IE
#define CN_P4  CNEN1bits.CN4IE
#define CN_P5  CNEN1bits.CN5IE
#define CN_P6  CNEN1bits.CN6IE
#define CN_P7  CNEN1bits.CN7IE

#define CN_P9  CNEN2bits.CN30IE
#define CN_P10 CNEN2bits.CN29IE
#define CN_P11 CNEN1bits.CN1IE
#define CN_P12 CNEN1bits.CN0IE

#define CN_P14 CNEN2bits.CN27IE
#define CN_P15 CNEN2bits.CN24IE
#define CN_P16 CNEN2bits.CN23IE
#define CN_P17 CNEN2bits.CN22IE
#define CN_P18 CNEN2bits.CN21IE
#define CN_P21 CNEN2bits.CN16IE
#define CN_P22 CNEN1bits.CN15IE
#define CN_P23 CNEN1bits.CN14IE
#define CN_P24 CNEN1bits.CN13IE
#define CN_P25 CNEN1bits.CN12IE
#define CN_P26 CNEN1bits.CN11IE

/********************************************************************/
// These SFR are used to enable pull up resistors for the pins.

#define PU_ON 1
#define PU_OFF 0

#define PU_P2  CNPU1bits.CN2PUE
#define PU_P3  CNPU1bits.CN3PUE
#define PU_P4  CNPU1bits.CN4PUE
#define PU_P5  CNPU1bits.CN5PUE
#define PU_P6  CNPU1bits.CN6PUE
#define PU_P7  CNPU1bits.CN7PUE


#define PU_P9  CNPU2bits.CN30PUE
#define PU_P10 CNPU2bits.CN29PUE
#define PU_P11 CNPU1bits.CN1PUE
#define PU_P12 CNPU1bits.CN0PUE

#define PU_P14 CNPU2bits.CN27PUE
#define PU_P15 CNPU2bits.CN24PUE
#define PU_P16 CNPU2bits.CN23PUE
#define PU_P17 CNPU2bits.CN22PUE
#define PU_P18 CNPU2bits.CN21PUE
#define PU_P21 CNPU2bits.CN16PUE
#define PU_P22 CNPU1bits.CN15PUE
#define PU_P23 CNPU1bits.CN14PUE
#define PU_P24 CNPU1bits.CN13PUE
#define PU_P25 CNPU1bits.CN12PUE
#define PU_P26 CNPU1bits.CN11PUE


#endif	/* GENDEFINES_H */

