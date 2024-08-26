#include "pinmap.h"


void initPinmap(void)
{
    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = 0;
    TRISDbits.TRISD13 = 1;
    LATDbits.LATD13 = 1;
}
