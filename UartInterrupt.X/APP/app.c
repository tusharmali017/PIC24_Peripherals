#include "app.h"



int res1 = 0, res2 = 0, res3 = 0;

static void initApp(void);
//static bool checkPacket();

/**
 * runApp is a function in which we are checking for each string entered on terminal
 * if LED ON typed on terminal, it will on LED
 * if LED OFF typed on terminal, it will off LED
 * if LED BLINK typed on terminal, it will activate trigger flag
 * which will ON led when it is true.
 */


void runApp()
{
    initApp();
    while (1)
    {
        if (gbFlagStringCheck == true)
        {
            gbFlagStringCheck = false;

            if (strcmp(gbVar, "LED ON\r") == 0)
            {
                LATAbits.LATA0 = 1;
                gbFlagLedBlinkTrigger = false;
            }
            else if (strcmp(gbVar, "LED OFF\r") == 0)
            {
                LATAbits.LATA0 = 0;
                gbFlagLedBlinkTrigger = false;
            }
            else if (strcmp(gbVar, "LED BLINK\r") == 0)
                gbFlagLedBlinkTrigger = true;  
            //trigger flag will set when LED BLINK typed
        }
    }
}

/**
 * This function checking each packet continue fashion, checking for \r after each character entered.
 */


//static bool checkPacket()
//{
//    int i;
//    if (gbIndex != 0)
//    {
//        for (i = 0; i < gbIndex; i++)
//        {
//            if ((gbVar[i] == '\r'))
//            {
//                gbIndex = 0;
//                return true;
//            }
//        }
//
//    }
//    return false;
//}

static void initApp(void)
{
    initInterrupts();
    T1CONbits.TON = 1;
}