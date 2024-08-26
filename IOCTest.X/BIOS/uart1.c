#include "uart1.h"

void initializeUART1()
{
    U1MODE = 0;
    U1MODEbits.BRGH = 1;
    U1BRG = 416; // 9600 baud at 16Mhz Fcy

    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}

void UART1_sendByte(uint8_t data)
{
    while(U1STAbits.UTXBF);
    U1TXREG = data;
}

void UART1_sendString(const char* data)
{
    while (*data != '\0')
    {
        UART1_sendByte(*data);
        data++;
    }
}

void UART1_sendData(const uint8_t* data, uint16_t length)
{
    while(length--)
    {
        UART1_sendByte(*data);
        data++;
    }
}