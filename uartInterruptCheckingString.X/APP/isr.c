 #include "isr.h"

uint8_t gbIndex = 0;
char gbVar[16];
bool gbFlagStringCheck = false;
bool gbFlagLedBlinkTrigger = false;
static uint16_t count = 0;


void initInterrupts(void)
{
    IEC0bits.U1RXIE = 1;
    IEC0bits.T1IE = 1;     
}



void __attribute__((interrupt(auto_psv))) _U1RXInterrupt(void)
{
    gbVar[gbIndex] = U1RXREG;
    if(gbVar[gbIndex] == '\r')
    {
        gbFlagStringCheck = true;
        gbVar[gbIndex + 1] = '\0';
        gbIndex = 0;
    }
    else
        gbIndex++;

    IFS0bits.U1RXIF = 0;
}


void __attribute__((interrupt(auto_psv))) _T1Interrupt(void)
{
    if((gbFlagLedBlinkTrigger == true))
    {      
        count++;
        if(count == 10) 
        {
            count = 0;
            _LATA0 ^= 1;
        } 
    }    
    else
        count = 0;
    IFS0bits.T1IF = 0;  
}