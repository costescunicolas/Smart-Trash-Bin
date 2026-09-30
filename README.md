# Smart Trash Bin 🗑️🤖

An automated, touchless smart waste container built with an embedded microcontroller architecture using PlatformIO. The system uses ultrasonic sensing for object and distance detection, a servo motor for automatic lid operation, acoustic and visual feedback indicators, and USART serial communication for debugging and status telemetry.

---

## 📌 Features

* **Touchless Lid Control:** Automatically opens and closes the bin lid via a servo motor upon proximity detection.
* **Ultrasonic Distance Sensing:** Measures proximity to trigger lid actuation and monitor capacity/distance.
* **Audio & Visual Indicators:** Integrated buzzer and LEDs provide real-time status alerts (e.g., opening, closing, full bin).
* **Hardware Timer Management:** Dedicated timer modules handle precise delays, event scheduling, and PWM signals.
* **USART Telemetry:** Serial interface for logging distance measurements, sensor events, and operational states.
* **Modular C/C++ Architecture:** Clear separation of hardware abstraction layers (HAL) across standalone driver modules[cite: 1].

---

## 🛠️ Hardware & Peripherals

The project codebase implements drivers for the following peripheral modules[cite: 1]:

* **Microcontroller Unit (MCU):** Managed via PlatformIO configuration (`platformio.ini`)[cite: 1].
* **Ultrasonic Sensor (e.g., HC-SR04):** Driver handled by `ultrasonic.c` / `ultrasonic.h` for echo timing and distance calculations[cite: 1].
* **Servo Motor (e.g., SG90):** Controlled via `servo.c` / `servo.h` for physical lid movement[cite: 1].
* **Piezo Buzzer:** Managed via `buzzer.c` / `buzzer.h` for acoustic signaling[cite: 1].
* **LED Status Indicators:** Controlled via `leds.c` / `leds.h` for visual state feedback[cite: 1].
* **Timer Peripheral:** Implemented in `timer.c` / `timer.h` for accurate hardware timing[cite: 1].
* **USART Interface:** Implemented in `usart.c` / `usart.h` for serial logging and diagnostics[cite: 1].

---

## 📁 Repository Structure

```text
Smart-Trash-Bin/
├── include/              # Header files (declarations and register definitions)[cite: 1]
│   ├── buzzer.h          # Buzzer interface definitions[cite: 1]
│   ├── leds.h            # LED indicators interface[cite: 1]
│   ├── servo.h           # Servo actuation prototypes[cite: 1]
│   ├── timer.h           # Hardware timer configuration[cite: 1]
│   ├── ultrasonic.h      # Ultrasonic distance sensor interface[cite: 1]
│   └── usart.h           # Serial communication prototypes[cite: 1]
├── src/                  # Source files (driver implementations and main routine)[cite: 1]
│   ├── buzzer.c          # Buzzer control logic[cite: 1]
│   ├── leds.c            # LED state handling[cite: 1]
│   ├── main.cpp          # System entry point and state machine loop[cite: 1]
│   ├── servo.c           # Servo pulse generation / movement logic[cite: 1]
│   ├── timer.c           # Timer interrupt routines and delay helpers[cite: 1]
│   ├── ultrasonic.c      # Trigger pulse and echo measurement routines[cite: 1]
│   └── usart.c           # Baud rate setup, transmit, and receive routines[cite: 1]
├── lib/                  # Custom third-party or isolated libraries[cite: 1]
├── test/                 # Unit and functional tests[cite: 1]
├── .gitignore            # Git exclusion rules for build artifacts[cite: 1]
└── platformio.ini        # PlatformIO environment, board, and framework setup[cite: 1]
