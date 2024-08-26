#include "pinmap.h"

static void setPeripheralMap(void);

void initPinmap(void)
{
    _TRISA0 = 0;

    _TRISB5 = 1; //RB5 as input
    ANSBbits.ANSB5 = 1; //RB5 as a analog pin

    _TRISB4 = 1; //RB4 as input
    ANSBbits.ANSB4 = 1; //RB4 as a analog pin
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
