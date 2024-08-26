#include "app.h"

void runApp()
{
    while (1)
    {
        if ((SWITCH3 == 0) | (SWITCH4 == 0) | (SWITCH6 == 0))
        {
            timer1Delayms(100);
            if ((SWITCH3 == 1) | (SWITCH4 == 1) | (SWITCH6 == 1))
            {
                LATAbits.LATA0 = 1;
                UART1WriteString("WELCOME TO PRECISION\r\n");
            }
        }
        timer1Delayms(2000);
        LATAbits.LATA0 = 0;
    }
}

