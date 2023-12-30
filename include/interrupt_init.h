#ifndef TIMER_INTERRUPT_INIT_H
#define TIMER_INTERRUPT_INIT_H

enum InterruptType
{
    TIMER1,
    PORTINPUT,
    NONE
};

extern volatile bool interruptFlag;
extern InterruptType interruptFlagType;
void initInterrupts();

#endif
