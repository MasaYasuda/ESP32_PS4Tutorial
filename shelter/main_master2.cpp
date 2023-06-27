/*  This program is for ESP32
Protocol
Byte Index | Value
0 | start byte (0xFF)
1 | LED num (1~3)
2 | Brightness (0~255)
3 | checksum (sum of 0,1,2)

*/


#include <Arduino.h>
#include <PS4Controller.h>

byte value[3]={0};

void setup(){
  Serial.begin(115200);
  PS4.begin("xx:xx:xx:xx:xx:xx");//適宜書き換え
}

void loop(){
  if (PS4.isConnected()){
    value[0] = byte(PS4.Square()); //四角ボタン
    value[1] = byte(PS4.L2Value()); //左レバー
    value[2] = byte(PS4.LStickX()+128); //左ジョイスティックx座標
    for(byte i=0;i<3;i++){
      Serial.write(0xFF);
      Serial.write(i+1);
      Serial.write(value[i]);
      byte checksum = (0xFF+(i+1)+value[i]) & 0xFF; //今回は1バイトのchecksumなので元の先頭バイト0xFFは必要ないかもしれない
      Serial.write(checksum);
    }
  }
  delay(20);
}
