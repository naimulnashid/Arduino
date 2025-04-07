#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Scanning I2C bus...");
  Wire.begin();
}

void loop() {
  byte address = 1;  // Start scan from address 1

  for (; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0 && address != 112) {
      Serial.print("I2C device found at address: 0x");
      Serial.println(address, HEX);
    }
  }

  delay(1000);
}