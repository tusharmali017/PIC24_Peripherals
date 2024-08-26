#include "app.h"

static void initApp(void);


void runApp()
{
    initApp();
    while(1)
    {
        if((gbIntFlag == true))
        {
            LATAbits.LATA0 ^= 1;
            gbIntFlag = false;
        }
    }
}

static void initApp(void)
{
    initInterrupts();
    T1CONbits.TON = 1;    
}