#include "app.h"

void runApp() {
    while (1) {
        if (PORTDbits.RD13 == 0) {
            timer1Delayms(2000);
            if (PORTDbits.RD13 == 1)
                LATAbits.LATA4 = 1;
        }
    }
    
    
}
 
