#include "buzzer.h"
#include <util/delay.h>

void init_buzzer() {
	DDRD |= (1 << BUZZER_PIN);
    PORTD &= ~(1 << BUZZER_PIN);
}

void buzzer_error_beep() {
	for (int i = 0; i < 3; i++) {
		PORTD |= (1 << BUZZER_PIN);
		_delay_ms(300);
		PORTD &= ~(1 << BUZZER_PIN);
		_delay_ms(300);
	}
}