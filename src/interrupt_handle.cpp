#include <avr/interrupt.h>
#include <avr/io.h>
#include "interrupt_handle.h"
#include "interrupt_init.h"
#include <Arduino.h>

InterruptType interruptFlagType = NONE;

void InterruptHandle()
{
    switch (interruptFlagType)
    {
    case (TIMER1):
        cli();
        PORTB ^= (1 << PORTB5);
        interruptFlagType = NONE;
        interruptFlag = false;
        sei();
        break;
    case (PORTINPUT):
        cli();
        PORTB ^= (1 << PORTB4);
        interruptFlagType = NONE;
        interruptFlag = false;
        Serial.println("INPUT TRIGGERED");
        sei();
        break;
    default:
        break;
    }
}