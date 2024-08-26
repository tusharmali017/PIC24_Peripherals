#include "app.h"

/* An I2C scanner is a program or tool used to scan the I2C bus and detect 
 * all connected devices. It helps verify the presence and address of I2C devices, 
 * which is useful for debugging communication issues.

=> Purpose of an I2C Scanner
Verify Connections: Ensure that devices are correctly connected to the I2C bus.
Determine Addresses: Identify the I2C addresses of connected devices, which can 
be used in your program to communicate with them.
Troubleshoot Issues: Detect issues with the I2C bus, such as incorrect wiring, 
faulty devices, or address conflicts.
*/

#define I2C_ACK 0
#define I2C_NACK 1

static void I2C_Scanner(void);

// Example main function to run the I2C scanner
void runApp()
{
    // Initialize I2C and UART
    I2C1_open();

    // Run the I2C scanner
    I2C_Scanner();

    // Close I2C and UART (optional, depending on your system)
    I2C1_close();

    // Endless loop
    while (1);

    return 0;
}

static void I2C_Scanner(void)
{
    char buf[32];
    uint8_t address;

    UART1WriteString("Scanning I2C bus...\r\n");

    for (address = 1; address < 127; address++)
    {
        I2C1_generateStart();
        I2C1_Write((address << 1) | 0); // Write mode
        if (I2C1_checkACKSlave() == I2C_ACK)
        {
            sprintf(buf, "Found device at 0x%02X\r\n", address);
            UART1WriteString(buf);
        }
        I2C1_generateStop();
    }

    UART1WriteString("Scan complete.\r\n");
}

