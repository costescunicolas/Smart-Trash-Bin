#ifndef BUZZER_H_
#define BUZZER_H_
#include <avr/io.h>

#define BUZZER_PIN PD5

void init_buzzer();
void buzzer_error_beep();

#endif