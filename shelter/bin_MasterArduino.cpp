#include <Arduino.h>
int durations[] = {0, 100, 500, 1000};

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // 点灯時間を送信
    Serial.write((byte*)&durations[i], sizeof(durations[i]));
    delay(2000);  // 2秒待機
  }
}