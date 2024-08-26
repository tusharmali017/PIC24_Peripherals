/*
 * File:   main.c
 * Author: Vinit Bhamburdekar
 *
 * Created on 7 June, 2023, 3:55 PM
 */



// PIC24FJ1024GB610 Configuration Bit Settings

// 'C' source line config statements

// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
#pragma config BSLIM = 0x1FFF           // Boot Segment Flash Page Address Limit bits (Enter Hexadecimal value)

// FOSCSEL
#pragma config FNOSC = PRIPLL           // Oscillator Source Selection (Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL))
#pragma config PLLMODE = PLL4X          // PLL Mode Selection (4x PLL selected)
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Mode Select bits (XT Crystal Oscillator Mode)
#pragma config OSCIOFCN = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config SOSCSEL = OFF            // SOSC Power Selection Configuration bits (Digital (SCLKI) mode)
#pragma config PLLSS = PLL_PRI          // PLL Secondary Selection Configuration bit (PLL is fed by the Primary oscillator)
#pragma config IOL1WAY = ON             // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler bits (1:32,768)
#pragma config FWPSA = PR128            // Watchdog Timer Prescaler bit (1:128)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bits (WDT and SWDTEN disabled)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config WDTWIN = WIN25           // Watchdog Timer Window Select bits (WDT Window is 25% of WDT period)
#pragma config WDTCMX = WDTCLK          // WDT MUX Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits)
#pragma config WDTCLK = LPRC            // WDT Clock Source Select bits (WDT uses LPRC)

// FPOR
#pragma config BOREN = ON               // Brown Out Enable bit (Brown Out Enable Bit)
#pragma config LPCFG = OFF              // Low power regulator control (No Retention Sleep)
#pragma config DNVPEN = ENABLE          // Downside Voltage Protection Enable bit (Downside protection enabled using ZPBOR when BOR is inactive)

// FICD
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC2 and PGED2)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Disable (BOOTSWP instruction disabled)

// FDEVOPT1
#pragma config ALTCMPI = DISABLE        // Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC high power mode (default))
#pragma config ALTVREF = ALTREFEN       // Alternate Voltage Reference Location Enable bit (VREF+ and CVREF+ on RA10, VREF- and CVREF- on RA9)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include "defines.h"
#include "BIOS/bios.h"

static bool flagButtonPressedTrigger = false;
static bool flagButtonPressed = false;
static bool flagButtonReleaseTrigger = false;
static bool flagButtonRelease = false;
static bool flagCommandExecute = false;
static uint16_t iCountPressed = 0;
static uint16_t iCountRelease = 0;

static uint8_t iCommands[3] = {0};

typedef enum
{
    STATE_BUTTON_IDLE,
    STATE_BUTTON_PRESSED,
    STATE_BUTTON_RELEASED
} STATE_BUTTON;

STATE_BUTTON buttonState = STATE_BUTTON_IDLE;

//void __attribute__((interrupt(auto_psv))) _IOCInterrupt(void)
//{
//    if (_IOCFD6)
//    {
//        flagButtonPressed = true;
//        _IOCFD6 = 0;
//    }
//
//    _IOCIF = 0;
//}

void __attribute__((interrupt(auto_psv))) _T2Interrupt(void)
{
    if (flagButtonPressedTrigger)
    {
        iCountPressed++;
        if (iCountPressed >= 50)
        {
            flagButtonPressed = true;
        }
    }
    else
    {
        iCountPressed = 0;
    }

    if (flagButtonReleaseTrigger)
    {
        iCountRelease++;
        if (iCountRelease >= 50)
        {
            flagButtonRelease = true;
        }
    }
    else
    {
        iCountRelease = 0;
    }

    _T2IF = 0;
}

void buttonTasks()
{
    switch (buttonState)
    {
    case STATE_BUTTON_IDLE:
        if (DI_BUTTON_S3 == 0)
        {
            iCommands[0] = 1;
            flagButtonPressedTrigger = true;
        }
        else if (DI_BUTTON_S4 == 0)
        {
            iCommands[1] = 1;
            flagButtonPressedTrigger = true;
        }
        else if (DI_BUTTON_S6 == 0)
        {
            iCommands[2] = 1;
            flagButtonPressedTrigger = true;
        }
        else
            flagButtonPressedTrigger = false;

        if (flagButtonPressed)
        {
            flagButtonPressed = false;
            flagButtonPressedTrigger = false;
            buttonState = STATE_BUTTON_PRESSED;
        }
        break;
    case STATE_BUTTON_PRESSED:
        if (DI_BUTTON_S3 == 1 && DI_BUTTON_S4 == 1 && DI_BUTTON_S6 == 1)
        {
            flagButtonReleaseTrigger = true;
        }
        else
            flagButtonReleaseTrigger = false;

        if (flagButtonRelease)
        {
            flagButtonRelease = false;
            flagButtonReleaseTrigger = false;
            buttonState = STATE_BUTTON_RELEASED;
        }
        break;
    case STATE_BUTTON_RELEASED:
        flagCommandExecute = true;
        buttonState = STATE_BUTTON_IDLE;
        break;
    }
}

int main(void)
{
    initializeBIOS();
    _T2IE = 1;
    //    IOCPDbits.IOCPD6 = 1;
    //    _IOCIE = 1;
    //    _IOCON = 1;
    //    _IOCIF = 0;

    while (1)
    {
        buttonTasks();
        
        if(flagCommandExecute)
        {
            flagCommandExecute = false;
            if(iCommands[0] == 1)
            {
                iCommands[0] = 0;
                DO_LED_D5 ^= 1;
            }
            else if(iCommands[1] == 1)
            {
                iCommands[1] = 0;
                DO_LED_D6 ^= 1;                
            }
            else if(iCommands[2] == 1)
            {
                iCommands[2] = 0;
                DO_LED_D7 ^= 1;                
            }
        }
    }

    return 0;
}
