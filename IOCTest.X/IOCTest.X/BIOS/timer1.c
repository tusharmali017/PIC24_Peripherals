#include "timer1.h"

void initializeTimer1()
{
    T1CON = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 0;
}

void delayus(unsigned long us)
{
    unsigned long i;

    T1CONbits.TON = 0;
    PR1 = 16;
    TMR1 = 0;
    _T1IF = 0;
    T1CONbits.TON = 1;

    for (i = 0; i < us; i++)
    {
        while (_T1IF == 0);
        _T1IF = 0;
        TMR1 = 0;
    }
}

void delayms(int ms)
{
    int i;
    T1CONbits.TON = 0;
    PR1 = 16000;
    TMR1 = 0;
    _T1IF = 0;
    T1CONbits.TON = 1;

    for (i = 0; i < ms; i++)
    {
        while (_T1IF == 0);
        _T1IF = 0;
        TMR1 = 0;
    }

    T1CONbits.TON = 0;
}
