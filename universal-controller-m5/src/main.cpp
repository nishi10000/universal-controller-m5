#include <M5AtomS3.h>
#include <Wire.h>

#define JOY_ADDR 0x52 //define Joystick I2C address

void setup() {
  AtomS3.begin(false);  // LED無効化でAtomS3を初期化
  Serial.begin(115200);
  Serial.println("Joystick Test");
  
  Wire.begin(2, 1);  // ATOM S3のI2CピンはGPIO 2（SDA）とGPIO 1（SCL）
}

void loop() {
  uint8_t x_data, y_data, button_data;
  Wire.requestFrom(JOY_ADDR, 3);  //Request 3 bytes from the slave device.  
  if (Wire.available() >= 3) { //If data is received.
    x_data = Wire.read();
    y_data = Wire.read();
    button_data = Wire.read();
    Serial.printf("x:%d y:%d button:%d\n", x_data, y_data, button_data);
  } else {
    Serial.println("Failed to read from joystick");
  }
  delay(200);
}