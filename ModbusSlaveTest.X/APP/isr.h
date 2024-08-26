/* 
 * File:   isr.h
 * Author: tushar.mali
 *
 * Created on 10 February, 2023, 5:08 PM
 */

#ifndef ISR_H
#define	ISR_H

#include "../BIOS/bios.h"

#ifdef	__cplusplus
extern "C" {
#endif

    extern uint8_t gbIndex;
    extern bool gbFlagModbusPacketCheck;
    void initInterrupts(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ISR_H */


