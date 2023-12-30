#include "port_init.h"
#include "interrupt_init.h"
#include "interrupt_handle.h"
#include "system_status.h"
#include <Arduino.h>

int main(void)
{
    SystemStatus machineStatus = INITIALIZATION;

    while (1)
    {
        switch (machineStatus)
        {
        case INITIALIZATION:
            Serial.begin(9600);
            initPorts();
            initInterrupts();
            machineStatus = IDLE;
            break;
        case IDLE:
            if (interruptFlag)
            {
                machineStatus = INTERRUPT_HANDLING;
            }
            break;
        case INTERRUPT_HANDLING:
            InterruptHandle();
            Serial.println("Interrupt handled");
            machineStatus = IDLE;
            break;
        default:
            break;
        }
    }
}