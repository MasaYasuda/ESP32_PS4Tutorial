// This program is for ESP32

#include <Arduino.h>
#include <PS4Controller.h>

const int PINLED1=4;
const int PINLED2=5;//analogWrite（PWM出力）ができるピンを選ぶ
const int PINLED3=6;//analogWrite（PWM出力）ができるピンを選ぶ

int led2value=0;
int led3value=0;

void setup(){
  Serial.begin(115200);
  PS4.begin("xx:xx:xx:xx:xx:xx");//適宜書き換え
}

void setup(){
  if (PS4.isConnected()){
    //PS4.Square():0 or 1
    digitalWrite(PINLED1,PS4.Square());
    //PS4.L2Value():0~255
    led2value=int(PS4.L2Value()); //analogWriteの値はint型なのでint型にキャスト（変換）した
    analogWrite(PINLED2,led2value);
    //PS4.LStickX():-128~127
    led3value=int(PS4.LStickX()+128);
    analogWrite(PINLED3,led3value);
  }
  delay(5);
}