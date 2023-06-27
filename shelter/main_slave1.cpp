#include <Arduino.h>

const int PINLED1=4;
const int PINLED2=5;//analogWrite（PWM出力）ができるピンを選ぶ
const int PINLED3=6;//analogWrite（PWM出力）ができるピンを選ぶ

byte num=0;
byte value=0;

void setup(){
  Serial.begin(115200);
}

void loop(){
  if (Serial.available() >= 2) {
    num=Serial.read();
    value=Serial.read();
    if (num==1){
      digitalWrite(PINLED1,value);
    }else if(num==2){
      analogWrite(PINLED2,value);
    }else if(num==3){
      analogWrite(PINLED3,value);
    }
  }
  delay(5);
}



