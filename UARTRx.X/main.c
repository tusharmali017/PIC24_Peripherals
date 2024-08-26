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
#pragma config FNOSC = FRCPLL           // Oscillator Source Selection (Fast RC Oscillator with divide-by-N with PLL module (FRCPLL) )
#pragma config PLLMODE = PLL4X          // PLL Mode Selection (4x PLL selected)
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFCN = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config SOSCSEL = ON             // SOSC Power Selection Configuration bits (SOSC is used in crystal (SOSCI/SOSCO) mode)
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
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Disable (BOOTSWP instruction disabled)

// FDEVOPT1
#pragma config ALTCMPI = DISABLE        // Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC high power mode (default))
#pragma config ALTVREF = ALTREFEN       // Alternate Voltage Reference Location Enable bit (VREF+ and CVREF+ on RA10, VREF- and CVREF- on RA9)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

int data;

void setpinmap()
{
    __builtin_write_OSCCONL(OSCCON & 0xbf);
    //    // Configure Input Functions 
    //    RPINR18bits.U1RXR = 10; // Assign U1RXR to RP10
    //    
    //    // Configure Output Functions
    //    RPOR8bits.RP17R = 3; //Assign U1TX To Pin RP17

    // UART2 for BMS
    _U2RXR = 19;
    _RP27R = _RPOUT_U2TX;
    __builtin_write_OSCCONL(OSCCON | 0x40);
}

void uart_init()
{
    U2MODEbits.BRGH = 1;
    U2BRG = 415; // 9600 baud at 8Mhz Fosc

    //U2BRG = 25;                 //9600 baud rate set into baud rate register
    /*
     * Desired Baud Rate = Fcy/16(UxBRG+1)
     * UxBRG= ((Fcy/Baud rate)/16)-1
     * U1BRG = ((4MHz/9600)/16)-1
     * U1BRG = 25           //BRGH = 0,  allows for greater accuracy in baud rate generation
     *                      for low baud rates, recommended to use BRGH = 0
     */

    U2MODE = 0x8000; //UART enabled
    U2STA = 0; //UART1 status and control register

    U2STAbits.UTXEN = 1; //Enable Transmission
    U2STAbits.URXEN = 1; //Enable Receiver

    // Configure UART1 RX Interrupt
    _U2RXIF = 0; // Clear UART1 RX Interrupt Flag
    _U2RXIE = 0; // Enable UART1 RX Interrupt
}

void UART_Write(int data)
{
    while (U2STAbits.UTXBF); // Wait until the transmit buffer is empty
    U1TXREG = data; // Write the data to the UART1 transmit register
}

char UART_Read()
{
    while (!U2STAbits.URXDA); // Wait until data is received
    return U1RXREG; // Read the data from the UART1 receive register
}

int main(void)
{

    setpinmap();
    uart_init(9600); // Initialize UART module with 9600 baud rate

    while (1)
    {       
        data = UART_Read(); // Read data from UART
        UART_Write('A'); // Write the received data back to UART
    }
    return 0;
}
