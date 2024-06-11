#include <Servo.h>

Servo servo1; // Servo on pin 3
Servo servo2; // Servo on pin 4

void setup() {
  servo1.attach(3);
  servo2.attach(4);

  // Изначальное положение серво-приводов
  servo1.write(90); // Среднее положение
  servo2.write(90); // Среднее положение

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    if (command == "Looking Right") {
      servo1.write(25); // 45 градусов влево
    } 
    else if (command == "Looking Left") {
      servo1.write(155); // 45 градусов вправо
    } 
    else if (command == "Looking Up") {
      servo2.write(45); // 45 градусов вверх
    } 
    else if (command == "Looking Down") {
      servo2.write(145); // 45 градусов вниз
    } 
    else if (command == "Forward") {
      servo1.write(90); // Вернуться в среднее положение
      servo2.write(90); // Вернуться в среднее положение
    }
  }
}
