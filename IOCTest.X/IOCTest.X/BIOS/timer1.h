/* 
 * File:   timer1.h
 * Author: Vinit Bhamburdekar
 *
 * Created on 24 August, 2020, 11:50 AM
 * 
 * This timer is used to generate delays.
 */

#ifndef TIMER1_H
#define	TIMER1_H

#include "../defines.h"


#ifdef	__cplusplus
extern "C" {
#endif

    void initializeTimer1();
    void delayus(unsigned long us);
    void delayms(int ms);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER1_H */

