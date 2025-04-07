/*
PROJECT VARANUS
Horizontal Walk code

Angle management for each joint for future references
LF:
---
Shoulder: front-
Arm: up-
Hand: cup=180, foot=...

RF:
---
Shoulder: front+
Arm: up+
Hand: cup=0, foot=...

LB:
---
Shoulder: front-
Arm: up-
Hand: cup=90, foot=...

RB:
---
Shoulder: front+
Arm: up+
Hand: cup=90, foot=...
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver front = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver back = Adafruit_PWMServoDriver(0x40);

int minPWM = 150;
int maxPWM = 600;

int lhand = 15;
int larm = 14;
int lshoulder = 12;

int rshoulder = 3;
int rarm = 2;
int rhand = 0;

int bt_var;
int min_shoulder = 20;
int min_arm = 30;

int getPWM(int angle);
void advance(void);
void recede(void);
void left_turn(void);
void right_turn(void);
void neutral(void);

void setup() {
  // put your setup code here, to run once:
  front.begin();
  front.setPWMFreq(60);
  back.begin();
  back.setPWMFreq(60);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial1.available() > 1) {
    bt_var = Serial1.read();

    if (bt_var == 'A') neutral();
    
    else if (bt_var == 'B') advance();

    else if(bt_var == 'C') recede();

    else if(bt_var == 'D') left_turn();

    else if(bt_var == 'E') right_turn();
  }
}

/*
This function is to map the angles from 0 to 180 degrees
to usable PWM values for the setPWM function, from minPWM=150
to maxPWM=600
Input: integer angle
Output: integer PWM value
*/
int getPWM(int angle) {
  int PWM = map(angle, 0, 180, minPWM, maxPWM);
  return PWM;
}

/*
When called, this function advances VARANUS by one step
Input: None
Output: None
*/
void advance(void)
{
      //lifting, advancing, grounding the left front leg and right back leg
      front.setPWM(larm, 0, getPWM(90 - min_arm));
      back.setPWM(rarm, 0, getPWM(90 + min_arm));
      front.setPWM(lshoulder, 0, getPWM(90 - min_shoulder));
      back.setPWM(rshoulder, 0, getPWM(90 + min_shoulder));
      delay(500);
      front.setPWM(larm, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      delay(500);

      //lifting, advancing, grounding the right front leg and left back leg
      front.setPWM(rarm, 0, getPWM(90 + min_arm));
      back.setPWM(larm, 0, getPWM(90 - min_arm));
      front.setPWM(rshoulder, 0, getPWM(90 + min_shoulder));
      back.setPWM(lshoulder, 0, getPWM(90 - min_shoulder));
      delay(500);
      front.setPWM(rarm, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      delay(500);

      //pushing the body forward by pulling all the legs in
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(rshoulder, 0, getPWM(90));
}

/*
When called, this function recedes VARANUS by one step
Input: None
Output: None
*/
void recede(void)
{
      //lifting, receding, grounding the left front leg and right back leg
      front.setPWM(larm, 0, getPWM(90 - min_arm));
      back.setPWM(rarm, 0, getPWM(90 + min_arm));
      front.setPWM(lshoulder, 0, getPWM(90 + min_shoulder));
      back.setPWM(rshoulder, 0, getPWM(90 - min_shoulder));
      delay(500);
      front.setPWM(larm, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      delay(500);

      //lifting, receding, grounding the right front leg and left back leg
      front.setPWM(rarm, 0, getPWM(90 + min_arm));
      back.setPWM(larm, 0, getPWM(90 - min_arm));
      front.setPWM(rshoulder, 0, getPWM(90 - min_shoulder));
      back.setPWM(lshoulder, 0, getPWM(90 + min_shoulder));
      delay(500);
      front.setPWM(rarm, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      delay(500);

      //pushing the body backward by pulling all the legs in
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(rshoulder, 0, getPWM(90));
}

/*
When called, this function turns VARANUS towards left
Input: None
Output: None
*/
void left_turn(void)
{
    //advance the RF leg, recede the LB leg
    front.setPWM(rarm, 0, getPWM(90 + min_arm));
    back.setPWM(larm, 0, getPWM(90 - min_arm));
    back.setPWM(lshoulder, 0, getPWM(90 + min_shoulder));
    front.setPWM(rshoulder, 0, getPWM(90 + min_shoulder));
    delay(500);
    front.setPWM(rarm, 0, getPWM(90));
    back.setPWM(larm, 0, getPWM(90));
    delay(500);

    //advance the RB leg, recede the LF leg
    back.setPWM(rarm, 0, getPWM(90 + min_arm));
    front.setPWM(larm, 0, getPWM(90 - min_arm));
    front.setPWM(lshoulder, 0, getPWM(90 + min_shoulder));
    back.setPWM(rshoulder, 0, getPWM(90 + min_shoulder));
    delay(500);
    back.setPWM(rarm, 0, getPWM(90));
    front.setPWM(larm, 0, getPWM(90));
    delay(500);

    //push all legs in to turn the bot towards left
    front.setPWM(lshoulder, 0, getPWM(90));
    front.setPWM(rshoulder, 0, getPWM(90));
    back.setPWM(lshoulder, 0, getPWM(90));
    back.setPWM(rshoulder, 0, getPWM(90));
}

/*
When called, this function VARANUS towards right
Input: None
Output: None
*/
void right_turn(void)
{
    //advance the LB leg, recede the RF leg
    front.setPWM(rarm, 0, getPWM(90 + min_arm));
    back.setPWM(larm, 0, getPWM(90 - min_arm));
    back.setPWM(lshoulder, 0, getPWM(90 - min_shoulder));
    front.setPWM(rshoulder, 0, getPWM(90 - min_shoulder));
    delay(500);
    front.setPWM(rarm, 0, getPWM(90));
    back.setPWM(larm, 0, getPWM(90));
    delay(500);

    //advance the LF leg, recede the RB leg
    back.setPWM(rarm, 0, getPWM(90 + min_arm));
    front.setPWM(larm, 0, getPWM(90 - min_arm));
    front.setPWM(lshoulder, 0, getPWM(90 - min_shoulder));
    back.setPWM(rshoulder, 0, getPWM(90 - min_shoulder));
    delay(500);
    back.setPWM(rarm, 0, getPWM(90));
    front.setPWM(larm, 0, getPWM(90));
    delay(500);

    //push all legs in to turn the bot towards right
    front.setPWM(lshoulder, 0, getPWM(90));
    front.setPWM(rshoulder, 0, getPWM(90));
    back.setPWM(lshoulder, 0, getPWM(90));
    back.setPWM(rshoulder, 0, getPWM(90));
}

/*
When called, this function returns VARANUS to the neutral position
Neutral postion is when all the arms are perpendicular to each other
and the cups face the ground. Useful for priming the bot before walking
Input: None
Output: None
*/
void neutral(void)
{
      front.setPWM(lshoulder, 0, getPWM(90));
      front.setPWM(larm, 0, getPWM(90));
      front.setPWM(lhand, 0, getPWM(170)); //TESTING
      back.setPWM(lshoulder, 0, getPWM(90));
      back.setPWM(larm, 0, getPWM(90));
      back.setPWM(lhand, 0, getPWM(90));

      front.setPWM(rshoulder, 0, getPWM(90));
      front.setPWM(rarm, 0, getPWM(90));
      front.setPWM(rhand, 0, getPWM(90)); //TESTING
      back.setPWM(rshoulder, 0, getPWM(90));
      back.setPWM(rarm, 0, getPWM(90));
      back.setPWM(rhand, 0, getPWM(90));
}
