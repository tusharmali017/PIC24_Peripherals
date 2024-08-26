#include "isr.h"

bool gbIntFlag = false;
static uint16_t count = 0;


void initInterrupts(void)
{
    IEC0bits.T1IE = 1;    
}



void __attribute__((interrupt(auto_psv))) _T1Interrupt(void)
{
    count++;
    if(count == 10) 
    {
        gbIntFlag = true;
        count = 0;
    }
    IFS0bits.T1IF = 0;
}