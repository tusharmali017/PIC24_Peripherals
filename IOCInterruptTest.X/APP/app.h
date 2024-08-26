/* 
 * File:   app.h
 * Author: tushar.mali
 *
 * Created on 2 February, 2024, 12:08 PM
 */

#ifndef APP_H
#define	APP_H

#include "../BIOS/bios.h"
#include "isr.h"

#ifdef	__cplusplus
extern "C" {
#endif


    void runApp();
    void delay_ms(unsigned int time);

#ifdef	__cplusplus
}
#endif

#endif	/* APP_H */

