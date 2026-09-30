#include "ultrasonic.h"
#include <util/delay.h>

void Ultrasonic0_init(void) {
    ULTRASONIC0_DDR |= (1 << TRIG0_PIN);
    ULTRASONIC0_DDR &= ~(1 << ECHO0_PIN);
    ULTRASONIC0_PORT &= ~(1 << TRIG0_PIN);
}

uint16_t Ultrasonic0_getDistance() {
    uint32_t max_loops = TIMEOUT_US_TO_LOOPS(30000); 
    uint32_t numloops = 0;
    uint32_t echo_time = 0; 
    
    ULTRASONIC0_PORT |= (1 << TRIG0_PIN);
    _delay_us(10);
    ULTRASONIC0_PORT &= ~(1 << TRIG0_PIN);
    
    while (!(ULTRASONIC0_PIN & (1 << ECHO0_PIN))) {
        numloops++;
        if (numloops >= max_loops) return 999; 
    }
    
    while (ULTRASONIC0_PIN & (1 << ECHO0_PIN)) {
        echo_time++;
        if (echo_time >= max_loops) return 999; 
    }
    
    return echo_time / 58;
}

void Ultrasonic1_init(void) {
    ULTRASONIC1_DDR |= (1 << TRIG1_PIN);
    ULTRASONIC1_DDR &= ~(1 << ECHO1_PIN);
    ULTRASONIC1_PORT &= ~(1 << TRIG1_PIN);
}

uint16_t Ultrasonic1_getDistance() {
    uint32_t max_loops = TIMEOUT_US_TO_LOOPS(30000); 
    uint32_t numloops = 0;
    uint32_t echo_time = 0; 
    ULTRASONIC1_PORT |= (1 << TRIG1_PIN);
    _delay_us(10);
    ULTRASONIC1_PORT &= ~(1 << TRIG1_PIN);
    
    while (!(ULTRASONIC1_PIN & (1 << ECHO1_PIN))) {
        numloops++;
        if (numloops >= max_loops) return 999; 
    }
    
    while (ULTRASONIC1_PIN & (1 << ECHO1_PIN)) {
        echo_time++;
        if (echo_time >= max_loops) return 999; 
    }
    
    return echo_time / 58;
}