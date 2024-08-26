/* 
 * File:   bios.h
 * Author: Vinit Bhamburdekar
 *
 * Created on 2 June, 2021, 12:01 PM
 */

#ifndef BIOS_H
#define	BIOS_H

#include "../defines.h"

#include "pinmap.h"
#include "timer1.h"
#include "timer2.h"
#include "uart1.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void initializeBIOS();


#ifdef	__cplusplus
}
#endif

#endif	/* BIOS_H */

