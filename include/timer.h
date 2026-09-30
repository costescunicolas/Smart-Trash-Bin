#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint32_t systicks;

void Timer0_init_ctc();
uint32_t get_milis();

#endif // TIMER_H_