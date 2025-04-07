#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x41);

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
  board.begin();
  Serial.begin(9600);
  board.setPWMFreq(60);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>1)
  {
    bt_var = Serial.read();

    if(bt_var == 'A') //neutral
    {
      board.setPWM(lshoulder, 0, getPWM(90));
      board.setPWM(larm, 0, getPWM(90));
      board.setPWM(lhand, 0, getPWM(180));
      board.setPWM(rshoulder, 0, getPWM(90));
      board.setPWM(rarm, 0, getPWM(90));
      board.setPWM(rhand, 0, getPWM(0));
    }
    else if(bt_var == 'B') //advance supposedly
    {
      board.setPWM(larm, 0, getPWM(90-30));
      board.setPWM(lshoulder, 0, getPWM(90-20));
      delay(500);
      board.setPWM(larm, 0, getPWM(90));
      delay(500);
      board.setPWM(rarm, 0, getPWM(90+30));
      board.setPWM(rshoulder, 0, getPWM(90+20));
      delay(500);
      board.setPWM(rarm, 0, getPWM(90));
      delay(500);
      board.setPWM(lshoulder, 0, getPWM(90));
      board.setPWM(rshoulder, 0, getPWM(90));
    }
  }
}

int getPWM(int angle)
{
  int PWM = map(angle, 0, 180, minPWM, maxPWM);
  return PWM;
}