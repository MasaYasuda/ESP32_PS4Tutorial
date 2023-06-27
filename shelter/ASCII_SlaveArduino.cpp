#include <Arduino.h>

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    
    if (input == 'H') {
      digitalWrite(ledPin, HIGH);
    } else if (input == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}