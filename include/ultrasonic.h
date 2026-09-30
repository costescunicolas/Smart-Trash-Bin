#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <stdint.h>
#include <avr/io.h>

// --- SENZOR 0 (Exterior - Deschide capacul) ---
#define TRIG0_PIN PC0   
#define ECHO0_PIN PC1   
#define ULTRASONIC0_PORT PORTC
#define ULTRASONIC0_DDR DDRC
#define ULTRASONIC0_PIN PINC


#define TRIG1_PIN PC2   
#define ECHO1_PIN PC3   
#define ULTRASONIC1_PORT PORTC
#define ULTRASONIC1_DDR DDRC
#define ULTRASONIC1_PIN PINC

#define CYCLES_PER_MICROSECOND (F_CPU / 1000000UL)
#define CYCLES_PER_LOOP 16
#define TIMEOUT_US_TO_LOOPS(us) (((us) * CYCLES_PER_MICROSECOND) / CYCLES_PER_LOOP)

void Ultrasonic0_init(void);
uint16_t Ultrasonic0_getDistance(void);

void Ultrasonic1_init(void);
uint16_t Ultrasonic1_getDistance(void);

#endif