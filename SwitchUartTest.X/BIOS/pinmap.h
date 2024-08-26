/* 
 * File:   pinmap.h
 * Author: tushar.mali
 *
 * Created on 8 February, 2023, 4:01 PM
 */

#ifndef PINMAP_H
#define	PINMAP_H

#include "../BIOS/bios.h"

#define SWITCH3 PORTDbits.RD6
#define SWITCH4 PORTDbits.RD13
#define SWITCH6 PORTDbits.RD7
#define SWITCH5 PORTAbits.RA7


#ifdef	__cplusplus
extern "C" {
#endif

    void initPinmap(void);


#ifdef	__cplusplus
}
#endif

#endif	/* PINMAP_H */

