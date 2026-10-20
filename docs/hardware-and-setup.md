# Hardware and setup

## Components
- ESP32 development board
- L298N dual H-bridge driver
- Four DC motors
- Chassis and separate motor power supply

## ESP32 to L298N wiring
| ESP32 GPIO | L298N input |
| --- | --- |
| 33 | ENA |
| 22 | IN1 |
| 21 | IN2 |
| 19 | IN3 |
| 18 | IN4 |
| 15 | ENB |

Connect grounds together and use a suitable supply for the motors. Check the driver board jumper configuration before applying PWM to ENA and ENB.

## Run
1. Install Arduino IDE and ESP32 board support.
2. Open `src/esp32_smart_car.ino`.
3. Select the correct ESP32 board and serial port.
4. Upload the sketch.
5. Pair a compatible Bluetooth serial controller with `ESP32_Car`.
6. Send F, B, L, R or S to control direction, or 0-9 and q for speed.

## Known limitations
The original project code initializes `motorSpeed` to 1000, outside the standard 8-bit PWM duty cycle range (0-255). Set a suitable value in that range before hardware testing. This repository preserves the original sketch from the project report rather than claiming that the uploaded version has been independently tested.

ESP32 BluetoothSerial requires a board with compatible Bluetooth Classic support. Not all ESP32 variants support it.
