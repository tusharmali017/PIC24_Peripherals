#include "timer2.h"

/**
 * Initialize Timer2 with interrupt generated every 1ms.
 * PR2 = 250, as for 1ms at 32Mhz Fosc, every tick equals 4us.
 */
void initializeTimer2()
{
    T2CON = 0;
    T2CONbits.TCS = 0; // Internal Clock Fosc/2
    T2CONbits.TCKPS = 0b10; // 64 prescalar
    TMR2 = 0;
    PR2 = 250;
 
    T2CONbits.TON = 0;
}
