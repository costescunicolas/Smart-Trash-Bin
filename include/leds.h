#ifndef LEDS_H_
#define LEDS_H_
#include <avr/io.h>

#define RED_LED PD2
#define YELLOW_LED PD3
#define GREEN_LED PD4

void init_leds();
void turn_red_led();
void turn_yellow_led();
void turn_green_led();


#endif