
// PIC32MZ2048EFH064 Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_8         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_34_68_MHZ// System PLL Input Range (34-68 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32        // System PLL Output Clock Divider (32x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = POSC             // Oscillator Selection Bits (Primary Osc (HS,EC))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = HS             // Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = ON              // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ3
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define CAN_MESSAGE_ID      0x123     // Example CAN message ID
#define CAN_MESSAGE_DATA    "Hello"   // Example CAN message data

/* This code snippet shows an example of data structure to implement a CAN */
/* message buffer. *//* Define the sub-components of the data structure as specified in Table 34-2 */
/* Create a CMSGSID data type. */

typedef struct 
{
    unsigned SID:11;
    unsigned :21;
}txcmsgsid;

/* Create a CMSGEID data type. */
typedef struct 
{
    unsigned DLC:4;
    unsigned RB0:1;
    unsigned :3;
    unsigned RB1:1;
    unsigned RTR:1;
    unsigned EID:18;
    unsigned IDE:1;
    unsigned SRR:1;
    unsigned :2;
}txcmsgeid;

/* Create a CMSGDATA0 data type. */
typedef struct
{
    unsigned Byte0:8;
    unsigned Byte1:8;
    unsigned Byte2:8;
    unsigned Byte3:8;
}txcmsgdata0;

/* Create a CMSGDATA1 data type. */
typedef struct
{
    unsigned Byte4:8;
    unsigned Byte5:8;
    unsigned Byte6:8;
    unsigned Byte7:8;
}txcmsgdata1;

/* This is the main data structure. */
typedef union uCANTxMessageBuffer 
{
    struct
    {
        txcmsgsid CMSGSID;
        txcmsgeid CMSGEID;
        txcmsgdata0 CMSGDATA0;
        txcmsgdata0 CMSGDATA1;};
        int messageWord[4];
}CANTxMessageBuffer;  

/* Example usage of data structure shown in Example 34-6. This example sets */
/* up a message buffer in FIFO1 */
CANTxMessageBuffer * buffer;
buffer = (CANTxMessageBuffer *)(PA_TO_KVA1(C1FIFOUA1));
/* Clear the message buffer. */
buffer->messageWord[0] = 0;
buffer->messageWord[1] = 0;
buffer->messageWord[2] = 0;
buffer->messageWord[3] = 0;
buffer->CMSGSID.SID = 0x100;
/* Message SID */
buffer->CMSGEID.DLC = 0x2;
/* Data Length is 2 */
buffer->CMSGDATA0.Byte0 = 0xAA;
/* Byte 0 Data */
buffer->CMSGDATA0.Byte1 = 0xbb;
/* Byte 1 Data */
}

void CAN1_Transmit(uint32_t messageId, uint8_t *data, uint8_t dataLength)
{
    if (C1FIFOCON0bits.TXREQ || C1FIFOCON1bits.TXREQ) // Check if transmit buffer is available
    {
        return; // Exit if transmit buffer is not available
    }

    C1FIFOCON0bits.TXREQ = 1;   // Request transmission of message object 0

    /* Clear the message buffer. */
    buffer->messageWord[0] = 0;
    buffer->messageWord[1] = 0;
    buffer->messageWord[2] = 0;
    
    buffer->CMSGSID.SID = messageId;   // Set the message ID
    buffer->CMSGEID.DLC = dataLength;  // Set the data length
    buffer->CMSGDATA.Byte0 = *data;     /* Byte 0 Data */
}

void CAN1_Receive(uint32_t *messageId, uint8_t *data, uint8_t *dataLength)
{
    if (C1FIFOINT0bits.RXFULLIF) // Check if receive buffer has a message
    {
        *messageId = buffer->CMSGSID.SID;  
        *dataLength = buffer->CMSGEID.DLC;
        *data = buffer->CMSGDATA.Byte0;
        C1FIFOINT0bits.RXFULLIF = 0;                // Clear the RXFUL0 flag to indicate that the message has been read
    }
}

void main(void)
{
    uint32_t messageId;
    uint8_t data[8];
    uint8_t dataLength;

    // Initialize the device
    //SYSTEMConfigPerformance(SYS_FREQ);

    // Initialize the CAN module
    CAN1_Initialize();

    while (1)
    {
        // Transmit a CAN message
        CAN1_Transmit(CAN_MESSAGE_ID, (uint8_t *)CAN_MESSAGE_DATA, strlen(CAN_MESSAGE_DATA));

        // Wait for a CAN message to be received
        while (!C1FIFOINT0bits.RXFULLIF)
        {
            // Do other tasks if needed
        }

        // Receive the CAN message
        CAN1_Receive(&messageId, data, &dataLength);

        // Process the received CAN message
        printf("Received message ID: 0x%lx\n", messageId);
        printf("Received data: %.*s\n", dataLength, data);
    }
}
