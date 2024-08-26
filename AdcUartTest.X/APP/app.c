#include "app.h"

char buf[32] = {0};

void runApp()
{
    initLCD();
    uint16_t ivalue = 0;
    float temp;
    double voltage;
    while(1)
    {
        ivalue = readADC(5);                //channel 4 - Temp Sensor, channel 5 - Potentiometer
        //voltage = (VREF * ivalue)/1023;
        //temp = (voltage - 0.5) * 10 ;      // Converting to degrees
        
        /* sprintf is used to print the potentiometer values*/
        sprintf(buf, "%d\r\n", ivalue);
        
//        /* sprintf is used to print the voltages*/
//        sprintf(buf, "ivalue = %d voltage = %.2lf\r\n", ivalue, voltage); 
//        uart1PutString(buf, sizeof(buf));
//        sprintf(buf, "temp = %.2lf\r\n", temp); 
        
//        
//        /* sprintf is used to print the temp*/
//        sprintf(buf, "%.2lf\r\n", temp);
        
        uart1PutString(buf, sizeof(buf));
        timer1Delayms(100);
    }
}
