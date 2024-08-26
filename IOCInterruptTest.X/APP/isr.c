#include "isr.h"

bool gbFlagIOCDetected = false;

void initInterrupt(void)
{
    PADCONbits.IOCON = 1;
    IOCNDbits.IOCND13 = 1;
    _IOCFD13 = 0;
    _IOCIF = 0;
    _IOCIE = 1;
}


void __attribute__((interrupt(auto_psv))) _IOCInterrupt(void)
{
    if(_IOCIE & _IOCIF)
    {
        if(_IOCFD13)
        {
            _IOCFD13 = 0;
            gbFlagIOCDetected = true;
        }
    }
    _IOCIF = 0;
}