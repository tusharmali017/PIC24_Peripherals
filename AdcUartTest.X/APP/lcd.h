/* 
 * File:   lcd.h
 * Author: tushar.mali
 *
 * Created on 30 November, 2023, 9:42 PM
 */

#ifndef LCD_H
#define	LCD_H

#include "../BIOS/bios.h"

#define LCD_RS LATBbits.LATB15
#define LCD_EN LATDbits.LATD4
#define LCD_RW LATDbits.LATD5
#define LCD_DATALINE LATE

#ifdef	__cplusplus
extern "C" {
#endif

    void initLCD(void);
    void LCDData(char data);
    void LCDCmd(uint16_t cmd);
    void LCDPutString(char *tx_str, int size);
    void LCDClearScreen(void);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

