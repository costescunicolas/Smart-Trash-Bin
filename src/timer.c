#include "timer.h"

volatile uint32_t systicks = 0;

void Timer0_init_ctc() {
	TCCR0A |= (1 << WGM01);
	OCR0A = 250;
	TCCR0B |= (3 << CS00);
	TIMSK0 |= (1 << OCIE0A);
}

ISR(TIMER0_COMPA_vect) {
	systicks++;
}

uint32_t get_milis(void)
{
    uint32_t t;
    uint8_t sreg = SREG;

    cli();
    t = systicks;
    SREG = sreg;

    return t;
}


