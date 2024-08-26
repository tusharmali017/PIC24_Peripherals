#include "timer1.h"




/**
 * This timer initializes such that PR1 match occurs at 1ms.
 * This means the T1IF flag is set every 1ms.
 */
void initTimer1(void)
{
    T1CON = 0;
    TMR1 = 0x00;
//    T1CONbits.TCKPS = 3; //1:256 pre-scale
//    PR1 = 15625;
    PR1 = 4000U;
}


/**
 * This delay function running in a for loop for ms times.
 * If ms value given is 1000, then total 1sec delay generated.
 */
void timer1Delayms(int ms)
{
    unsigned int i;
    T1CONbits.TON = 1;              // turning ON the timer
    for(i=0;i<ms;i++)
    {
       while (!IFS0bits.T1IF);      //monitoring a timer overflow flag
       IFS0bits.T1IF = 0;   
    }
    T1CONbits.TON = 0; 
}

