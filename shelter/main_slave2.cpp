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
  if (Serial.available() >= 4) { //4バイト以上溜まっている場合
    byte buf[4]; //バッファを用意
    byte checksum=0; //チェックサム計算用の変数を用意
    buf[0]=Serial.read(); //バッファに受信データを格納
    checksum+=(buf[0] & 0xFF); 

    if(buf[0]==0xFF){
      for(byte i=1;i<3;i++){ 
        buf[i]=Serial.read(); //バッファに受信データを格納
        checksum+=(buf[i] & 0xFF); //サムを順次計算
      }
    }
    buf[3]=Serial.read(); //チェックサムを受信
    if(buf[3]==checksum){ //1バイト目が0xFFでかつ、チェックサムが正しい場合→以下出力
      if (buf[1]==1){
        digitalWrite(PINLED1,buf[2]);
      }else if(buf[1]==2){
        analogWrite(PINLED2,buf[2]);
      }else if(buf[1]==3){
        analogWrite(PINLED3,buf[2]);
      }
    }
  }
  delay(5);
}



