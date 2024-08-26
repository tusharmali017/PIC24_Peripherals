#include "timer1.h"




/**
 * This timer initializes such that PR1 match occurs at 1ms.
 * This means the T1IF flag is set every 1ms.
 */
void initTimer1(void)
{
    T1CON= 0; 
    T1CONbits.TCKPS = 3; //1:256 pre-scale
    //T1CONbits.TCKPS1 = 0; //1:1 pre-scale
    //T1CONbits.TCKPS0 = 0; //1:1 pre-scale
    TMR1 = 0x00;
    PR1 = 1562U;
}
