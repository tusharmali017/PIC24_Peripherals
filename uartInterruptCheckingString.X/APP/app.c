#include "app.h"


static void initApp(void);
static bool arrStringCheck();
 int i, found = 0;
bool gbFlagString1 = false;
bool gbFlagString2 = false;
bool gbFlagString3 = false;

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
            arrStringCheck();
            if(gbFlagString1 == 1)
            {
                LATAbits.LATA0 = 1;
                gbFlagLedBlinkTrigger = false;
            }
            else if ((gbFlagString2 == true))
            {
                LATAbits.LATA0 = 0;
                gbFlagLedBlinkTrigger = false;
            }
            else if ((gbFlagString3 == true))
                gbFlagLedBlinkTrigger = true;                       //trigger flag will set when LED BLINK typed
        }
    }
}

static bool arrStringCheck()
{
   char arr[3][16] = {"LED ON\r", "LED OFF\r", "LED BLINK\r"}; 
   if(strcmp(gbVar, arr[0]) == 0)
   {
       gbFlagString1 = true;
       gbFlagString2 = false;
       gbFlagString3 = false;
   }
   else if(strcmp(gbVar, arr[1]) == 0)
   {
       gbFlagString2 = true;
       gbFlagString1 = false;
       gbFlagString3 = false;
   }
   else if(strcmp(gbVar, arr[2]) == 0)
   {
       gbFlagString3 = true;
       gbFlagString2 = false;
       gbFlagString1 = false;
   }
   return 0;
}


static void initApp(void)
{
    initInterrupts();
    T1CONbits.TON = 1;
}