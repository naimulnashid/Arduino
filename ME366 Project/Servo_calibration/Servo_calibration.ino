#include <Servo.h>

Servo test;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  test.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  test.write(90);
}
