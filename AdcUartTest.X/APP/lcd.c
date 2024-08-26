#include "lcd.h"

void initLCD(void)
{
    LCDCmd(0x38); //2 lines, 5x7 matrix
    LCDCmd(0x0E); //Display On, Cursor Blinking
    LCDCmd(0x01); //Clear Display
    LCDCmd(0x80); //move the cursor to begining of first line

}

void LCDData(char data)
{
    LCD_DATALINE = data;
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_EN = 1;
    timer1Delayms(5);
    LCD_EN = 0;
}

void LCDCmd(uint16_t cmd)
{
    LCD_DATALINE = cmd;
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 1;
    timer1Delayms(5);
    LCD_EN = 0;
}

void LCDPutString(char *tx_str, int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        LCDData(*tx_str);
        tx_str++;
    }
}

void LCDClearScreen(void)
{
    LCDCmd(0x01);
}