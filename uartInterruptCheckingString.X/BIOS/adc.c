#include "adc.h"



void initADC(void)
{
    AD1CON1 = 0;
    AD1CON2 = 0;
    AD1CON3 = 0;
    
    AD1CON1bits.ASAM = 1;       //Sampling begins immediately after last conversion
    AD1CON1bits.SSRC = 0b0111;  //Auto-Convert mode
    //AD1CON1bits.MODE12 = 1;       //use this for 12 bit adc mode
    
    AD1CON3bits.ADCS = 1;       //TAD= 2*TCY
    AD1CON3bits.SAMC = 31;      //sampling time is 31*TAD   
}

uint16_t readADC(uint16_t iChannel)
{
    AD1CHSbits.CH0SA = iChannel;
    AD1CON1bits.ADON = 1;       //ADC On
    while (!AD1CON1bits.DONE);
    AD1CON1bits.ADON = 0;       //ADC OFF
    
    return ADC1BUF0;
    
}

