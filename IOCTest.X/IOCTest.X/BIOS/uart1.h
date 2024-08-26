/* 
 * File:   uart1.h
 * Author: Vinit Bhamburdekar
 *
 * Created on 10 August, 2020, 12:47 PM
 */

#ifndef UART1_H
#define	UART1_H

#include "../defines.h"


#ifdef	__cplusplus
extern "C" {
#endif

    void initializeUART1();
    void UART1_sendByte(uint8_t data);
    void UART1_sendString(const char* data);
    void UART1_sendData(const uint8_t* data, uint16_t length);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

