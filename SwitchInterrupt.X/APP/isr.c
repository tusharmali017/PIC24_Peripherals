#include "isr.h"

bool gbIntFlag = false;
bool gbSwFlag = false;
static uint16_t count = 0;
static uint8_t var;


void initInterrupts(void)
{
    IEC0bits.T1IE = 1;   
    IEC0bits.U1RXIE = 1; 
    IEC1bits.IOCIE = 1;         //IOC enable bit
    PADCONbits.IOCON = 1;
    IOCSTATbits.IOCPDF = 1;
    //IOCNDbits.IOCND13 = 1;
    IOCPDbits.IOCPD13 = 1;
}

/*ISR
 when switch is pressed LED will ON after 1 sec period
 and LED will OFF after 1 sec period 
 one trigger is declared when switch is pressed
 */

void __attribute__((interrupt(auto_psv))) _T1Interrupt(void)
{     
        count++;
        gbIntFlag = true;
//        if(count == 10) 
//        {
//            gbIntFlag = true;
//            count = 0;
//        }    
    IFS0bits.T1IF = 0;   
}

/**
 * ISR----- when any character sends through terminal to uc then it will 
 * resend it to terminal.
 */ 

void __attribute__((interrupt(auto_psv))) _U1RXInterrupt(void)
 {
    while (U1STAbits.UTXBF);     // Wait until the transmit buffer is empty
    U1TXREG = U1RXREG;               // Write the data to the UART1 transmit register  
    IFS0bits.U1RXIF = 0;
 }


void __attribute__((interrupt(auto_psv))) _IOCInterrupt(void)
{
    gbSwFlag = true;
    IOCFDbits.IOCFD13 = 0;
}