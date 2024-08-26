#include "app.h"

static void initApp(void);

void runApp()
{
    initApp();
    while (1)
    {   
        if(gbFlagModbusPacketCheck == true)
        {
            LATAbits.LATA0 = 1;
        }
    } 
}

static void initApp(void)
{
    initInterrupts();
}