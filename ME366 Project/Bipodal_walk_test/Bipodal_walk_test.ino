#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver front = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver back = Adafruit_PWMServoDriver(0x41);

int minPWM = 150;
int maxPWM = 600;

int lhand = 0;
int larm = 2;
int lshoulder = 3;

int rshoulder = 12;
int rarm = 14;
int rhand = 15;

int bt_var;

int getPWM(int angle);

void setup() {
  // put your setup code here, to run once:
  front.begin();
  front.setPWMFreq(60);
  back.begin();
  back.setPWMFreq(60);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>1)
  {
    bt_var = Serial.read();
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(larm, 0, getPWM(90));
      front.setPWM(lhand, 0, getPWM(180));
      front.setPWM(rshoulder, 0, getPWM(90));
      front.setPWM(rarm, 0, getPWM(90));
      front.setPWM(rhand, 0, getPWM(0));

      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      back.setPWM(lhand, 0, getPWM(90));
      back.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      back.setPWM(rhand, 0, getPWM(90));

    if(bt_var == 'A') //neutral
    {
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(larm, 0, getPWM(90));
      front.setPWM(lhand, 0, getPWM(180));
      front.setPWM(rshoulder, 0, getPWM(90));
      front.setPWM(rarm, 0, getPWM(90));
      front.setPWM(rhand, 0, getPWM(0));

      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      back.setPWM(lhand, 0, getPWM(90));
      back.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      back.setPWM(rhand, 0, getPWM(90));
    }
    else if(bt_var == 'B') //advance supposedly
    {
      front.setPWM(larm, 0, getPWM(90-30));
      back.setPWM(rarm, 0, getPWM(90+30));
      front.setPWM(lshoulder, 0, getPWM(90-20));
      back.setPWM(rshoulder, 0, getPWM(90+20));
      delay(500);
      front.setPWM(larm, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      delay(500);
      front.setPWM(rarm, 0, getPWM(90+30));
      back.setPWM(larm, 0, getPWM(90-30));
      front.setPWM(rshoulder, 0, getPWM(90+20));
      front.setPWM(lshoulder, 0, getPWM(90+20));
      delay(500);
      front.setPWM(rarm, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      delay(500);
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(rshoulder, 0, getPWM(90));
    }
  }
}

int getPWM(int angle)
{
  int PWM = map(angle, 0, 180, minPWM, maxPWM);
  return PWM;
}