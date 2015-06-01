/*
 * File:   genDefines.h
 * Author: albertoheras
 *
 * Created on May 17, 2015, 1:42 PM
 */
#ifndef SHORTCUTS_H
#define	SHORTCUTS_H



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
#define HIGH    1
#define LOW    0

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

#define ON 1
#define OFF 0

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

#define ON 1
#define OFF 0


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


/********************************************************************/
// These SFR are used to map an internal device as the output of these pins.

#define RPOR_P4 RPOR0bits.RP0R
#define RPOR_P5 RPOR0bits.RP1R
#define RPOR_P6 RPOR1bits.RP2R
#define RPOR_P7 RPOR1bits.RP3R
#define RPOR_P11 RPOR2bits.RP4R
#define RPOR_P14 RPOR2bits.RP5R
#define RPOR_P15 RPOR3bits.RP6R
#define RPOR_P16 RPOR3bits.RP7R
#define RPOR_P17 RPOR4bits.RP8R
#define RPOR_P18 RPOR4bits.RP9R
#define RPOR_P21 RPOR5bits.RP10R
#define RPOR_P22 RPOR5bits.RP11R
#define RPOR_P23 RPOR6bits.RP12R
#define RPOR_P24 RPOR6bits.RP13R
#define RPOR_P25 RPOR7bits.RP14R
#define RPOR_P26 RPOR7bits.RP15R

// Output functions that can be mapped to pins above.
//  Function    Set above pins to this number
//  NULL(2)     0 NULL
//  C1OUT       1 Comparator 1 Output
//  C2OUT       2 Comparator 2 Output
//  U1TX        3 UART1 Transmit
//  U1RTS(3)    4 UART1 Request To Send
//  U2TX        5 UART2 Transmit
//  U2RTS(3)    6 UART2 Request To Send
//  SDO1        7 SPI1 Data Output
//  SCK1OUT     8 SPI1 Clock Output
//  SS1OUT      9 SPI1 Slave Select Output
//  SDO2        10 SPI2 Data Output
//  SCK2OUT     11 SPI2 Clock Output
//  SS2OUT      12 SPI2 Slave Select Output
//  OC1         18 Output Compare 1
//  OC2         19 Output Compare 2
//  OC3         20 Output Compare 3
//  OC4         21 Output Compare 4
//  OC5         22 Output Compare 5

#define NULL 0
#define CLOCK1OUT 1
#define CLOCK2OUT 2
#define U1TX 3
#define U1RTS 4
#define U2TX 5
#define U2RTS 6
#define SDO1 7
#define SCK1OUT 8
#define SS1OUT 9
#define SDO2 10
#define SCK2OUT 11
#define SS2OUT 12
#define OutputCompare1 18
#define OutputCompare2 19
#define OutputCompare3 20
#define OutputCompare4 21
#define OutputCompare5 22

/********************************************************************/
#define UP 1
#define DOWN 0
#define pinMode(pin, mode) IO_P##pin = mode
#define pinVoltage(pin,volt) V_P##pin = volt
#define readValue(pin) read_P##pin
#define setODC(pin, mode) ODC_P##pin = mode
#define setAnalog(pin) AD_P##pin = 0
#define setDigital(pin) AD_P##pin = 1
#define enablePinCN(pin,mode) CN_P##pin = mode
#define enablePullUp(pin, mode) PU_P##pin = mode
#define remmapOutput(pin,function) RPOR_P##pin = function
#define enableBoardCN(mode)  IEC1bits.CNIE = mode
#define boardInterruptFlag(mode) IFS1bits.CNIF = mode

#endif	/* SHORTCUTS_H */