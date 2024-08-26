/* 
 * File:   timer2.h
 * Author: Vinit Bhamburdekar
 *
 * Created on 25 August, 2020, 12:51 PM
 * 
 * This timer is used to detect end of packet when serial port 1 receives 
 * data over modbus.
 */

#ifndef TIMER2_H
#define	TIMER2_H

#include "../defines.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void initializeTimer2();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER2_H */

