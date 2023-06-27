// This program is for ESP32
#include <Arduino.h>

void setup(void) {
  Serial.begin(115200);
  uint8_t bt_mac[6];
  esp_read_mac(bt_mac, ESP_MAC_BT);
  Serial.printf("Bluetooth Mac Address => %02X:%02X:%02X:%02X:%02X:%02X\r\n", bt_mac[0], bt_mac[1], bt_mac[2], bt_mac[3], bt_mac[4], bt_mac[5]);
}

void loop() {
}