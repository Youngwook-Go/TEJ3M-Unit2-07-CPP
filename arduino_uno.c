
// Created by: Youngwook Go
// Created on: OCT 2023
// Distance sensor

#include <Servo.h>

Servo servoNumber1;

const int trigPin = 2;
const int echoPin = 3;
float duration;
float distance;

void setup() {
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    Serial.begin(9600);

    servoNumber1.attach(4);
    servoNumber1.write(0);
}

void loop() {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;

    Serial.print("Distance: ");  
    Serial.println(distance);

    if (distance < 50) {
      servoNumber1.write(90);
    } else {
      servoNumber1.write(0);
    }
    delay(100);
}