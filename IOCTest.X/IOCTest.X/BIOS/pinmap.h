/* 
 * File:   pinmap.h
 * Author: Vinit Bhamburdekar
 *
 * Created on 6 December, 2020, 11:34 AM
 */

#ifndef PINMAP_H
#define	PINMAP_H

#include "../defines.h"

#define DIR_485_Set()   (_LATB15 = 1)
#define DIR_485_Clear()   (_LATB15 = 0)

#define DI_BUTTON_S3    _RD6
#define DI_BUTTON_S4    _RD13
#define DI_BUTTON_S6    _RD7

#define DO_LED_D5       _LATA2
#define DO_LED_D6       _LATA3
#define DO_LED_D7       _LATA4

#ifdef	__cplusplus
extern "C" {
#endif

    void initializePins();


#ifdef	__cplusplus
}
#endif

#endif	/* PINMAP_H */

