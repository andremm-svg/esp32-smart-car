#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

#define ENA_PIN 33
#define IN1_PIN 22
#define IN2_PIN 21
#define IN3_PIN 19
#define IN4_PIN 18
#define ENB_PIN 15

int motorSpeed = 1000;

void stopMotors();
void forward();
void backward();
void left();
void right();

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Car");
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  stopMotors();
  Serial.println("ESP32 Car Ready - Bluetooth: ESP32_Car");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.println(command);
    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopMotors(); break;
      case '0': motorSpeed = 0; break;
      case '1': motorSpeed = 25; break;
      case '2': motorSpeed = 50; break;
      case '3': motorSpeed = 75; break;
      case '4': motorSpeed = 100; break;
      case '5': motorSpeed = 125; break;
      case '6': motorSpeed = 150; break;
      case '7': motorSpeed = 175; break;
      case '8': motorSpeed = 200; break;
      case '9': motorSpeed = 225; break;
      case 'q': motorSpeed = 255; break;
      default: break;
    }
  }
  delay(20);
}

void forward() {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);
  analogWrite(ENA_PIN, motorSpeed);
  analogWrite(ENB_PIN, motorSpeed);
}

void backward() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);
  analogWrite(ENA_PIN, motorSpeed);
  analogWrite(ENB_PIN, motorSpeed);
}

void left() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);
  analogWrite(ENA_PIN, motorSpeed);
  analogWrite(ENB_PIN, motorSpeed);
}

void right() {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);
  analogWrite(ENA_PIN, motorSpeed);
  analogWrite(ENB_PIN, motorSpeed);
}

void stopMotors() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
}
