int l_f_pump = 6;
int r_f_pump = 7;
int l_b_pump = 8;
int r_b_pump = 9;

int lf_pump_state = 0;
int rf_pump_state = 0;
int lb_pump_state = 0;
int rb_pump_state = 0;

int bt_var;

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
