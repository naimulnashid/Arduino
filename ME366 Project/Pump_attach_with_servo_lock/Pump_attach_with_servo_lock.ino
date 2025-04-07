#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver();

int minPWM = 150;
int maxPWM = 600;

int lf_shoulder = 0;
int lf_hand = 2;
int lf_arm = 3;

int rf_shoulder = 4;
int rf_hand = 6;
int rf_arm = 7;

int lb_shoulder = 8;
int lb_hand = 10;
int lb_arm = 11;

int rb_shoulder = 12;
int rb_hand = 14;
int rb_arm = 15;

int l_f_pump = 6;
int r_f_pump = 7;
int l_b_pump = 8;
int r_b_pump = 9;

int lf_pump_state = 0;
int rf_pump_state = 0;
int lb_pump_state = 0;
int rb_pump_state = 0;

int bt_var;

int getPWM(int angle);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(l_f_pump, OUTPUT);
  pinMode(r_f_pump, OUTPUT);
  pinMode(l_b_pump, OUTPUT);
  pinMode(r_b_pump, OUTPUT);

  digitalWrite(l_f_pump, LOW);
  digitalWrite(r_f_pump, LOW);
  digitalWrite(l_b_pump, LOW);
  digitalWrite(r_b_pump, LOW);

  board.setPWM(lf_shoulder, 0, getPWM(90));
  board.setPWM(lf_hand, 0, getPWM(90));
  board.setPWM(lf_arm, 0, getPWM(90));
  
  board.setPWM(rf_shoulder, 0, getPWM(90));
  board.setPWM(rf_hand, 0, getPWM(90));
  board.setPWM(rf_arm, 0, getPWM(90));

  board.setPWM(lb_shoulder, 0, getPWM(90));
  board.setPWM(lb_hand, 0, getPWM(90));
  board.setPWM(lb_arm, 0, getPWM(90));
  
  board.setPWM(rb_shoulder, 0, getPWM(90));
  board.setPWM(rb_hand, 0, getPWM(90));
  board.setPWM(rb_arm, 0, getPWM(90));
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>1)
  {
    bt_var = Serial.read();
    
    if(bt_var == 'A') //Front left pump on
    {
      if(lf_pump_state == 0)
      {
        digitalWrite(l_f_pump, HIGH);
        lf_pump_state = 1;
      }
      else
      {
        digitalWrite(l_f_pump, LOW);
        lf_pump_state = 0;
      }
    }
    else if(bt_var == 'B') //Front right pump on
    {
      if(rf_pump_state == 0)
      {
        digitalWrite(r_f_pump, HIGH);
        rf_pump_state = 1;
      }
      else
      {
        digitalWrite(r_f_pump, LOW);
        rf_pump_state = 0;
      }
    }
    else if(bt_var == 'C') //Back left pump on
    {
      if(lb_pump_state == 0)
      {
        digitalWrite(l_b_pump, HIGH);
        lb_pump_state = 1;
      }
      else
      {
        digitalWrite(l_b_pump, LOW);
        lb_pump_state = 0;
      }
    }
    else if(bt_var == 'D') //Back right pump on
    {
      if(rb_pump_state == 0)
      {
        digitalWrite(r_b_pump, HIGH);
        rb_pump_state = 1;
      }
      else
      {
        digitalWrite(r_b_pump, LOW);
        rb_pump_state = 0;
      }
    }
    else if(bt_var == 'E') //All pump off
    {
      digitalWrite(l_f_pump, LOW);
      digitalWrite(r_f_pump, LOW);
      digitalWrite(l_b_pump, LOW);
      digitalWrite(r_b_pump, LOW);

      lf_pump_state = 0;
      rf_pump_state = 0;
      lb_pump_state = 0;
      rb_pump_state = 0;
    }
  }
}

int getPWM(int angle)
{
  int PWM = map(angle, 0, 180, minPWM, maxPWM);
  return PWM;
}
