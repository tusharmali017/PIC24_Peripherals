#include "app.h"

void runApp()
{
    initInterrupt();

    while (1)
    {
        if (gbFlagIOCDetected)
        {
            gbFlagIOCDetected = false;
            LATAbits.LATA0 ^= 1;
            delay_ms(1000);
        }
    }
}

void delay_ms(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 255; j++);
}
