#include <Arduino.h>
void setup() {
  // シリアル通信の開始
  Serial.begin(115200);
}

void loop() {
  // 1秒ごとに「H」と「L」を送信
  delay(1000);
  Serial.write(72); // ASCIIコードの「H」の値(1バイト送信)
  delay(1000);
  Serial.write(76); // ASCIIコードの「L」の値(1バイト送信)
}