#include <Arduino.h>

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // シリアル通信からの入力を待機
  if (Serial.available() >= sizeof(int)) {
    int duration;
    Serial.readBytes((byte*)&duration, sizeof(duration));
    /* 他にもいろんな書き方ができる（例）

    int duration = 0; 
    buf[2]={0}
    for(int i=0;i<2;i++){
        buf[i]=Serial.read();
    }
    memcpy(&duration, buf, sizeof(value)); //指定したメモリ領域をコピーする

    */

    // LEDを指定された点灯時間だけHIGHにする
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
  }
  delay(5);
}