#include "bios.h"

void initializeBIOS()
{
    initializePins();
    initializeUART1();
    initializeTimer1();
    initializeTimer2();
}
