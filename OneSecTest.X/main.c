
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
#pragma config FNOSC = PRI              // Oscillator Source Selection (Primary Oscillator (XT, HS, EC))
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
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC2 and PGED2)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Disable (BOOTSWP instruction disabled)

// FDEVOPT1
#pragma config ALTCMPI = DISABLE        // Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC high power mode (default))
#pragma config ALTVREF = ALTREFEN       // Alternate Voltage Reference Location Enable bit (VREF+ and CVREF+ on RA10, VREF- and CVREF- on RA9)


//#include "APP/app.h"


//int main(void) {
//    //initBIOS();
//    runApp();
//    return 0;
//}

#include "xc.h"

#define CONFIG_SLAVE_ENABLE() CONFIG_RD12_AS_DIG_OUTPUT()
#define SLAVE_ENABLE()        _LATD12 = 0  //low true assertion
#define SLAVE_DISABLE()       _LATD12 = 1
#define EEPROM_RDSR  0x05   //read status register command
#define EEPROM_READ  0x03   //read command
#define EEPROM_WRITE 0x02   //write command
#define EEPROM_WENABLE 0x06   //write command

#define BLKSIZE 64

void configSPI2(void) {
//spi clock = 40MHz/1*4*4 = 40MHz/16 = 2.5 MHz
SPI2CON1 = SEC_PRESCAL_4_1 |     //4:1 secondary prescale
PRI_PRESCAL_4_1 |     //4:1 primary prescale
CLK_POL_ACTIVE_HIGH | //clock active high (CKP = 0)
SPI_CKE_ON          | //out changes active to inactive (CKE=1)
SPI_MODE8_ON        | //8-bit mode
MASTER_ENABLE_ON;     //master mode
SPI2STATbits.SPIEN = 1;  //enable SPI mode
CONFIG_SLAVE_ENABLE();       //chip select for MCP41xxx
SLAVE_DISABLE();             //disable the chip select
}

//Assumes WDT is configured for longer than EEPROM write time
void waitForWriteCompletion() {
uint8 u8_spidata,u8_savedSWDTEN;
u8_savedSWDTEN = _SWDTEN;
_SWDTEN = 1; //enable WDT so that do not get stuck in infinite loop!
do {
SLAVE_ENABLE();
u8_spidata = ioMasterSPI2(EEPROM_RDSR); //send read status command
u8_spidata = ioMasterSPI2(0);   //get status back
SLAVE_DISABLE();
} while (u8_spidata & 0x01);  //LSB of status is write-in-progress flag
 _SWDTEN = u8_savedSWDTEN;  //restore WDT to original state
}

 //Write enable must be done before attempting a write.
 void writeEnable() {
    SLAVE_ENABLE();
    ioMasterSPI2(EEPROM_WENABLE);
    SLAVE_DISABLE();
 }
 
 void memWrite25LC256(uint16 u16_MemAddr, uint8 *pu8_buf) {
   uint8 u8_AddrLo, u8_AddrHi;
   uint8 u8_i;
 
   u8_AddrLo = u16_MemAddr & 0x00FF;
   u8_AddrHi = (u16_MemAddr >> 8);
  
   waitForWriteCompletion();
   writeEnable(); //enable the write
   SLAVE_ENABLE();
   ioMasterSPI2(EEPROM_WRITE);
   ioMasterSPI2(u8_AddrHi);
   ioMasterSPI2(u8_AddrLo);  
   for (u8_i=0; u8_i< BLKSIZE; u8_i++) {   
    ioMasterSPI2(pu8_buf[u8_i]);   
   }
   SLAVE_DISABLE();
 }
 
 void memRead25LC256(uint16 u16_MemAddr, uint8 *pu8_buf) {
   uint8 u8_AddrLo, u8_AddrHi;
   uint8 u8_i;
 
   waitForWriteCompletion();
   u8_AddrLo = u16_MemAddr & 0x00FF;
   u8_AddrHi = (u16_MemAddr >> 8);
   SLAVE_ENABLE();
   ioMasterSPI2(EEPROM_READ);
   ioMasterSPI2(u8_AddrHi);
   ioMasterSPI2(u8_AddrLo);
   for (u8_i=0; u8_i<BLKSIZE ; u8_i++) {
    pu8_buf[u8_i] = ioMasterSPI2(0) ;  //get one byte
   } 
   SLAVE_DISABLE();
 }
 
 
 int main (void) {
   uint8 au8_buf[BLKSIZE];  //holds data for EEPROM I/O
   uint16 u16_MemAddr;
   uint8 u8_Mode;
 
   configBasic(HELLO_MSG);
   configSPI2();             //configure SPI2 Module
   outString("\nEnter 'w' for write mode, anything else reads: ");
   u8_Mode = inCharEcho();
   outString("\n");
   u16_MemAddr = 0;     //start at location 0 in memory
   while (1) {
     uint8 u8_i;
     if (u8_Mode == 'w') {
       outString("Enter 64 chars.\n");
       //first two buffer locations reserved for starting address
       for (u8_i = 0;u8_i< BLKSIZE;u8_i++) {
         au8_buf[u8_i] = inCharEcho();
       }
       outString("\nDoing Write\n");
       // write same string twice to check Write Busy polling
       memWrite25LC256(u16_MemAddr, au8_buf); // do write
       u16_MemAddr = u16_MemAddr + BLKSIZE;
       memWrite25LC256(u16_MemAddr,au8_buf); // do write
       u16_MemAddr = u16_MemAddr + BLKSIZE;
     } else {
       memRead25LC256(u16_MemAddr,au8_buf); // do read
       for (u8_i = 0;u8_i< BLKSIZE;u8_i++) outChar(au8_buf[u8_i]);
       outString("\nAny key continues read...\n");
       inChar();
       u16_MemAddr = u16_MemAddr + BLKSIZE;
     }
   }
 }
