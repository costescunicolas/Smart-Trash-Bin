#include "servo.h"
#include <avr/io.h>

void Servo_init() {
    DDRB |= (1 << PB1); 

    TCCR1A = 0;
    TCCR1B = 0;

    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11);

    ICR1 = 40000;
    OCR1A = 2000;
}

void Servo_setAngle(uint8_t angle) {
	if (angle > 180) {
		angle = 180;
	}

	OCR1A = 2000 + ((uint32_t)angle * 2000) / 180;
}