#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt_init.h"

// set timer and prescaler for a 2Hz interrupt
#define TIMER_PRESCALER (1 << CS12) // 256
#define TIMER_COMPARE_VALUE 31249   // 16MHz / (2Hz*256) - 1
volatile bool interruptFlag = false;

void initInterrupts()
{
    cli();

    // timer interrupt setup
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    // set compare value
    OCR1A = TIMER_COMPARE_VALUE;

    // enable CTC
    TCCR1B |= (1 << WGM12);

    // prescaler
    TCCR1B |= TIMER_PRESCALER;

    // enable interrupt
    TIMSK1 |= (1 << OCIE1A);

    // external interrupt setup
    PIND |= (1 << PORTD2); // set PULLUP on PD2
    // EIMSK |= 0x01; // enable INT0
    // EICRA |= 0x01; // falling edge
    PCICR |= (1 << PCIE2);    // Enable pin change interrupt on PD2
    PCMSK2 |= (1 << PCINT18); // MASK REGISTER PD2
    sei();
}

ISR(TIMER1_COMPA_vect)
{
    interruptFlag = true;
    interruptFlagType = TIMER1;
}

ISR(PCINT2_vect)
{
    interruptFlag = true;
    interruptFlagType = PORTINPUT;
}