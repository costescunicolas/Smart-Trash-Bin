# Smart Trash Bin 🗑️🤖

An automated, touchless smart waste container built with an embedded microcontroller architecture using PlatformIO. The system uses ultrasonic sensing for object and distance detection, a servo motor for automatic lid operation, acoustic and visual feedback indicators, and USART serial communication for debugging and status telemetry.

---

## 📌 Features

* **Touchless Lid Control:** Automatically opens and closes the bin lid via a servo motor upon proximity detection.
* **Ultrasonic Distance Sensing:** Measures proximity to trigger lid actuation and monitor capacity/distance.
* **Audio & Visual Indicators:** Integrated buzzer and LEDs provide real-time status alerts (e.g., opening, closing, full bin).
* **Hardware Timer Management:** Dedicated timer modules handle precise delays, event scheduling, and PWM signals.
* **USART Telemetry:** Serial interface for logging distance measurements, sensor events, and operational states.
* **Modular C/C++ Architecture:** Clear separation of hardware abstraction layers (HAL) across standalone driver modules.

---

## 🛠️ Hardware & Peripherals

The project codebase implements drivers for the following peripheral modules:

* **Microcontroller Unit (MCU):** Managed via PlatformIO configuration (`platformio.ini`).
* **Ultrasonic Sensor (e.g., HC-SR04):** Driver handled by `ultrasonic.c` / `ultrasonic.h` for echo timing and distance calculations.
* **Servo Motor (e.g., SG90):** Controlled via `servo.c` / `servo.h` for physical lid movement.
* **Piezo Buzzer:** Managed via `buzzer.c` / `buzzer.h` for acoustic signaling.
* **LED Status Indicators:** Controlled via `leds.c` / `leds.h` for visual state feedback.
* **Timer Peripheral:** Implemented in `timer.c` / `timer.h` for accurate hardware timing.
* **USART Interface:** Implemented in `usart.c` / `usart.h` for serial logging and diagnostics.

---

## 📁 Repository Structure

```text
Smart-Trash-Bin/
├── include/              # Header files (declarations and register definitions)
│   ├── buzzer.h          # Buzzer interface definitions
│   ├── leds.h            # LED indicators interface
│   ├── servo.h           # Servo actuation prototypes
│   ├── timer.h           # Hardware timer configuration
│   ├── ultrasonic.h      # Ultrasonic distance sensor interface
│   └── usart.h           # Serial communication prototypes
├── src/                  # Source files (driver implementations and main routine)
│   ├── buzzer.c          # Buzzer control logic
│   ├── leds.c            # LED state handling
│   ├── main.cpp          # System entry point and state machine loop
│   ├── servo.c           # Servo pulse generation / movement logic
│   ├── timer.c           # Timer interrupt routines and delay helpers
│   ├── ultrasonic.c      # Trigger pulse and echo measurement routines
│   └── usart.c           # Baud rate setup, transmit, and receive routines
├── lib/                  # Custom third-party or isolated libraries
├── test/                 # Unit and functional tests
├── .gitignore            # Git exclusion rules for build artifacts
└── platformio.ini        # PlatformIO environment, board, and framework setup
