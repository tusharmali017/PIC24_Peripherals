#include "pinmap.h"

//RX1 = RF5 = RP17
//TX1 = RD15 = RP5
//DIR = RC4

void initializePins()
{
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
    LATF = 0;
    LATG = 0;

    TRISA = 0xFFFF;
    TRISB = 0xFFFF;
    TRISC = 0xFFFF;
    TRISD = 0xFFFF;
    TRISE = 0xFFFF;
    TRISF = 0xFFFF;
    TRISG = 0xFFFF;

    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    ANSELG = 0;

    //    Pushbuttons
    _TRISD6 = 1;
    _TRISD7 = 1;
    _TRISD13 = 1;
    
    //LEDs
    _TRISA2 = 0;
    _TRISA3 = 0;
    _TRISA4 = 0;

    __builtin_write_OSCCONL(OSCCON & 0xbf);
    _RP17R = _RPOUT_U1TX;
    _U1RXR = 10;
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
}