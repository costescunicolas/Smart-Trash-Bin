#include "leds.h"

void init_leds() {
    DDRD |= (1 << RED_LED) | (1 << YELLOW_LED) | (1 << GREEN_LED);
    PORTD &= ~((1 << RED_LED) | (1 << YELLOW_LED) | (1 << GREEN_LED));
}

void turn_red_led() {
	PORTD |= (1 << RED_LED);
	PORTD &= ~(1 << YELLOW_LED);
	PORTD &= ~(1 << GREEN_LED);
}

void turn_yellow_led() {
	PORTD |= (1 << YELLOW_LED);
	PORTD &= ~(1 << RED_LED);
	PORTD &= ~(1 << GREEN_LED);
}

void turn_green_led() {
	PORTD |= (1 << GREEN_LED);
	PORTD &= ~(1 << RED_LED);
	PORTD &= ~(1 << YELLOW_LED);
}