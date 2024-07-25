#include <M5AtomS3.h>

const uint8_t pin1 = 1;  // M5AtomLite S3
const uint8_t pin2 = 2;  // M5AtomLite S3
void setup() {
  AtomS3.begin(false);  // LED無効化でAtomS3を初期化
  Serial.begin(115200);
  delay(100);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
}
void loop() {
  Serial.printf("Blue=%d, Red=%d\n", digitalRead(pin1), digitalRead(pin2));
  delay(100);
}