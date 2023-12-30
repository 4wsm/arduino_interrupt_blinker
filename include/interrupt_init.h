#ifndef INTERRUPT_INIT_H
#define INTERRUPT_INIT_H

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
