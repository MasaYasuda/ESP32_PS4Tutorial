/*  This program is for ESP32

Protocol
Byte Index | Value
0 | LED num (1~3)
1 | Brightness (0~255)

*/


#include <Arduino.h>
#include <PS4Controller.h>

byte led1value=0;
byte led2value=0;
byte led3value=0;

void setup(){
  Serial.begin(115200);
  PS4.begin("xx:xx:xx:xx:xx:xx");//適宜書き換え
}

void loop(){
  if (PS4.isConnected()){
    led1value = byte(PS4.Square()); //四角ボタン
    led2value = byte(PS4.L2Value()); //左レバー
    led3value = byte(PS4.LStickX()+128); //左ジョイスティックx座標

    Serial.write(1);
    Serial.write(led1value);
    Serial.write(2);
    Serial.write(led2value);
    Serial.write(3);
    Serial.write(led3value);
  }
  delay(20);
}