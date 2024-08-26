/* 
 * File:   adc.h
 * Author: tushar.mali
 *
 * Created on 3 February, 2023, 3:52 PM
 */

#ifndef ADC_H
#define	ADC_H

#include "../projectdefines.h"

#ifdef	__cplusplus
extern "C" {
#endif

void initADC(void);
uint16_t readADC(uint16_t iChannel);



#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

