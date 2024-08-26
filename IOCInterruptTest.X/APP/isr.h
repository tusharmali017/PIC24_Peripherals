/* 
 * File:   isr.h
 * Author: tushar.mali
 *
 * Created on 2 February, 2024, 12:08 PM
 */

#ifndef ISR_H
#define	ISR_H

#include "../BIOS/bios.h"

#ifdef	__cplusplus
extern "C" {
#endif

    extern bool gbFlagIOCDetected;
    void initInterrupt(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ISR_H */

