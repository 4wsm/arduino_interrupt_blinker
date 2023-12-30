#include <avr/io.h>
#include "port_init.h"

void initPorts()
{
    // set outputs
    DDRB |= (1 << PORTB5);
    PORTB &= ~(1 << PORTB5);
    DDRB |= (1 << PORTB4);
    PORTB &= ~(1 << PORTB4);
}