#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern "C" {
    #include "usart.h"
    #include "timer.h"
    #include "ultrasonic.h"
    #include "servo.h"
    #include "leds.h"
    #include "buzzer.h"
}

#define BIN_TOTAL_DISTANCE 40

LiquidCrystal_I2C lcd(0x27, 16, 2);

typedef enum {
    CLOSED_STATE,
    OPEN_STATE,
    COOLDOWN_STATE
} bin_state;

uint32_t last_read_ultrasonic0_time = 0;
char buffer[32];
bin_state state = CLOSED_STATE;
uint32_t bin_top_time = 0;
uint16_t procent = 0;
uint8_t procent_shown = 0;

void setup() {
    
    USART_init(MYUBBR);
    Timer0_init_ctc();
    Ultrasonic0_init();
    Ultrasonic1_init();
    Servo_init();
    init_leds();
    init_buzzer();

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Smart Bin");
    delay(2000);

    sei();
}

void loop() {
    uint32_t current_time = get_milis(); 

    if (current_time - last_read_ultrasonic0_time >= 500) {
        uint16_t dist_to_object = Ultrasonic0_getDistance();

        if (dist_to_object == 999) {
            USART_print("Eroare la senzor 0\r\n");
        } else {
            sprintf(buffer, "Distanta: %d cm\r\n", dist_to_object);
            USART_print(buffer);
        }

        last_read_ultrasonic0_time = current_time;

        if (state == CLOSED_STATE) {
            
            uint16_t distance_to_bin = Ultrasonic1_getDistance();
            
            sprintf(buffer, "Distanta interior: %d cm\r\n", distance_to_bin);
            USART_print(buffer);
            
            if (distance_to_bin <= BIN_TOTAL_DISTANCE) {
               if (procent_shown == 0) {
                    uint16_t bin_height = BIN_TOTAL_DISTANCE - distance_to_bin;
                    procent = (bin_height * 100) / (BIN_TOTAL_DISTANCE - 5);
                    procent_shown = 1;
                    
                    sprintf(buffer, "Procent recalculat: %d\r\n", procent);
                    USART_print(buffer);
                    
                    lcd.setCursor(0, 0);   
                    lcd.print("Procent: ");
                    lcd.print(procent);
                    lcd.print("%   "); 
                    
                    if (procent < 50) {
                        turn_green_led();           
                    } else if (procent < 85) {
                        turn_yellow_led();
                    } else {
                        turn_red_led();
                    }
                }
            } else {
                procent_shown = 0;
            }

            if (dist_to_object <= 20) {
                if (procent >= 85) {
                    buzzer_error_beep();
                } else {
                    USART_print("Ar trebui sa deschid capacul\r\n");
                    Servo_setAngle(180);
                    state = OPEN_STATE;
                    bin_top_time = get_milis();
                }
            }
            
        } else if (state == OPEN_STATE) {
            if (dist_to_object <= 20) {
                bin_top_time = get_milis();
            } else {
                if (get_milis() - bin_top_time >= 4500) {
                    Servo_setAngle(0);
                    state = COOLDOWN_STATE;
                    bin_top_time = get_milis();
                }
            }
        } else if (state == COOLDOWN_STATE) {
            if (get_milis() - bin_top_time >= 1500) {
                state = CLOSED_STATE;
                procent_shown = 0;
            }
        }    
    }
}