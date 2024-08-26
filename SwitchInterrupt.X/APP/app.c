#include "app.h"

static void initApp(void);


void runApp() 
{
    initApp();
    while (1) 
    {
        if (gbIntFlag == true) //checking for interrupt flag. if its set, led will toggle
        {
            if (gbSwFlag == true) 
            {
                LATAbits.LATA0 = 1;   
            }
            gbSwFlag = false;
        }
        gbIntFlag = false; //Clearing the interrupt flag
    }
}

static void initApp(void) {
    initInterrupts();
    T1CONbits.TON = 1;
}