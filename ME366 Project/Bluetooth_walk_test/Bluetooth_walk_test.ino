#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver();

int minPWM = 150;
int maxPWM = 600;

int lf_shoulder = 0;
int lf_arm = 2;
int lf_hand = 3;

int rf_shoulder = 4;
int rf_arm = 6;
int rf_hand = 7;

int lb_shoulder = 8;
int lb_arm = 10;
int lb_hand = 11;

int rb_shoulder = 12;
int rb_arm = 14;
int rb_hand = 15;

int bt_var;

int getPWM(int angle);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  board.begin();
  board.setPWMFreq(60);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(Serial.available()>1)
  {
    bt_var = Serial.read();

    if(bt_var == 'A') //neutral
    {
      board.setPWM(lf_shoulder, 0, getPWM(90));
      board.setPWM(lf_arm, 0, getPWM(90));
      board.setPWM(lf_hand, 0, getPWM(90));
      board.setPWM(rf_shoulder, 0, getPWM(90));
      board.setPWM(rf_arm, 0, getPWM(90));
      board.setPWM(rf_hand, 0, getPWM(90));

      board.setPWM(lb_shoulder, 0, getPWM(90));
      board.setPWM(lb_arm, 0, getPWM(90));
      board.setPWM(lb_hand, 0, getPWM(0));
      board.setPWM(rb_shoulder, 0, getPWM(90));
      board.setPWM(rb_arm, 0, getPWM(90));
      board.setPWM(rb_hand, 0, getPWM(180));
    }

    else if(bt_var == 'B') //left advance
    {
      board.setPWM(lf_arm, 0, getPWM(90-30));
      board.setPWM(lf_shoulder, 0, getPWM(90+45));
      delay(500);
      board.setPWM(lf_arm, 0, getPWM(90));
      delay(500);
      board.setPWM(rb_shoulder, 0, getPWM(90-45));
      board.setPWM(lf_shoulder, 0, getPWM(90));
      delay(500);
    }

    else if(bt_var == 'C') //right advance
    {
      board.setPWM(rf_arm, 0, getPWM(90+30));
      board.setPWM(rf_shoulder, 0, getPWM(90-45));
      delay(500);
      board.setPWM(rf_arm, 0, getPWM(90));
      delay(500);
      board.setPWM(lb_shoulder, 0, getPWM(90+45));
      board.setPWM(rf_shoulder, 0, getPWM(90));
      delay(500);
    }
  }
}

int getPWM(int angle)
{
  int pwm_value;
  pwm_value = map(angle, 0, 180, minPWM, maxPWM);
  return pwm_value;
}
