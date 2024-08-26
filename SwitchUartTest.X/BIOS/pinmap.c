#include "pinmap.h"
static void setPeripheralMap(void);

void initPinmap(void)
{
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0000;
    LATG = 0x0000;

    TRISA = 0xFFFF;
    TRISB = 0xFFFF;
    TRISC = 0xFFFF;
    TRISD = 0xFFFF;
    TRISE = 0xFFFF;
    TRISF = 0xFFFF;
    TRISG = 0xFFFF;

    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    ANSELD = 0x0000;
    ANSELE = 0x0000;
    ANSELF = 0x0000;
    ANSELG = 0x0000;
    
    TRISAbits.TRISA0 = 0;
       
    setPeripheralMap();
}



/**
 * Tx and Rx pins are configured here as RP17 and RP10 pins.
 */
static void setPeripheralMap(void)
{
    __builtin_write_OSCCONL(OSCCON & 0xbf);
    // Configure Input Functions 
    RPINR18bits.U1RXR = 10; // Assign U1RXR to RP10
    
    // Configure Output Functions
    RPOR8bits.RP17R = 3; //Assign U1TX To Pin RP17
    __builtin_write_OSCCONL(OSCCON | 0x40);
}
