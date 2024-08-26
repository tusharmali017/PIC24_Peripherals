
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
#pragma config FNOSC = FRC              // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config PLLMODE = DISABLED       // PLL Mode Selection (No PLL used; PLLEN bit is not available)
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Mode Select bits (XT Crystal Oscillator Mode)
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
#pragma config ICS = PGD3               // ICD Communication Channel Select bits (Communicate on PGEC3 and PGED3)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Disable (BOOTSWP instruction disabled)

// FDEVOPT1
#pragma config ALTCMPI = DISABLE        // Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC high power mode (default))
#pragma config ALTVREF = ALTREFEN       // Alternate Voltage Reference Location Enable bit (VREF+ and CVREF+ on RA10, VREF- and CVREF- on RA9)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


/*
#include <xc.h>
#define _XTAL_FREQ 8000000

void timer1_delay();  

int main(void)
{
    _TRISA0 = 0;
    _TRISA7 = 1;
    _TRISA1 = 0;
    _LATA0 = 1;
    _LATA1 = 1;
    

    while(1)
    {
        _LATA0 = 1;
        _LATA1 = 1;
        timer1_delay(); 
        _LATA0 = 0;
        _LATA1 = 0;
        timer1_delay();  
        
        
    }
    return 0;
}
void timer1_delay()
{
    // configure Timer1 module
    T1CON = 0x00;	// enabled, prescaler 1:1
    
    // init Timer 1, T1ON, 1:1 prescaler
    TMR1 = 0x00;		// clear the timer
    PR1 = 0xF830;	// set the period register
    
    _TON = 1;           //timer 1 ON
    
    while(IFS0bits.T1IF == 0);// Wait for Timer1 overflow interrupt flag 
    _TON = 0;  			// Turn OFF timer 
    IFS0bits.T1IF = 0;  		// Make Timer1 overflow flag to '0' 
}  
 */

#include <xc.h>

void Timer1_Init(void) {
    T1CONbits.TSIDL = 0; //continues through Idle Mode
    T1CONbits.TGATE = 0; //no TGATE Operations
    T1CONbits.TCS = 0; //internal CLK 
    T1CONbits.TECS = 0x00;

    T1CONbits.TCKPS = 3; //1:256 pre-scale
    /*
      PRESCALE = 256
     * t = 1 sec = 1000 ms = 1,000,000 us
     * Fosc = 8MHz Fosc/2 = 4MHz Tcy = 0.25 us
     * 
     * t = N*PRE*Tcy
     * N = t/(PRE*Tcy) = 1,000,000/(256*0.25) = 15625
     * PR2 = 15625 (0x3D09)    
     */

    TMR1 = 0x00;
    PR1 = 0x3D09;
}

void delay_ms(unsigned int time_ms)
{
    unsigned int i, j;
    for(i=0;i<time_ms;i++)
        for(j=0;j<PR1;j++); 
}
        
int main(void) {
    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = 0;

    Timer1_Init();
    T1CONbits.TON = 1;

    while (1) {
        IFS0bits.T1IF = 0;

        while (!IFS0bits.T1IF);
        IFS0bits.T1IF = 0;
        LATAbits.LATA0 = 1;
        delay_ms(100);
        LATAbits.LATA0 = 1;
        delay_ms(100);       
    }
    return 0;
}