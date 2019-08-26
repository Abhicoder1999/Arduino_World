
// Pin Config
//int pwm_a = 10; //PWM control for motor outputs 1 and 2 is on digital pin 10
int turn_delay = 500;//msec
int l1=2;//A3
int l2=4;//A2

int r1=7;//A1
int r2=8;//A0


int enl=3;//11
int enr=6;//10

//Control Variables
int PWM_l = 0; // Change the intial values for setting the different motor speed
int PWM_r = 0;
int PWM_diff = 0;

void setup() 
{
  Serial.begin(9600);

  
  pinMode(l1,OUTPUT);   // Left motor output
  pinMode(l2,OUTPUT);
  
  pinMode(r1,OUTPUT);  //Right motor output
  pinMode(r2,OUTPUT);

  pinMode(enl,OUTPUT);   //Enable pins of R and L motors
  pinMode(enr,OUTPUT);

  analogWrite(enl, PWM_l);  
  analogWrite(enr, PWM_r);

}

void loop() 
{
  if(Serial.available())
  {
    int ch = Serial.read();
      Serial.println(ch);
      if((char)ch == 'F')
        forward();
      else if(char(ch) == 'S')
        halt();
      else if(char(ch) == 'R')
        forward_right();
      else if(char(ch) == 'r')
        right();//halt()
      else if(char(ch) == 'L')
        forward_left();
      else if(char(ch) == 'l')
        left();//halt()
      else if(char(ch) == 'B')
        backward();
  } 

}


void left()//
{
   PWM_l = 200;
   PWM_r = 200;
   
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  analogWrite(enr, PWM_r);

  Serial.println("inside left");
  delay(turn_delay);
}

void right()//
{
   PWM_l = 200;
   PWM_r = 200;
   
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  analogWrite(enr, PWM_r);

  Serial.println("inside right");
  delay(turn_delay);
}

void forward_left()//
{
   PWM_r = 200 -70;
   PWM_l = 233;
   
  digitalWrite(l2, HIGH);
  digitalWrite(l1, LOW);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r2, HIGH);
  digitalWrite(r1, LOW);
  analogWrite(enr, PWM_r);

  Serial.println("inside forward_left");
}

void forward_right()//
{
   PWM_r = 233;
   PWM_l = 200 - 70;
   
  digitalWrite(l2, HIGH);
  digitalWrite(l1, LOW);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r2, HIGH);
  digitalWrite(r1, LOW);
  analogWrite(enr, PWM_r);

  Serial.println("inside forward_right");
}


void forward()//here pwm_l correlates to right wheel
              // and pwm_r correlates to left wheel
{
   PWM_r = 220;
   PWM_l = 220;
   
  digitalWrite(l2, HIGH);
  digitalWrite(l1, LOW);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r2, HIGH);
  digitalWrite(r1, LOW);
  analogWrite(enr, PWM_r);

  Serial.println("inside forward");
}
void backward()//
{
   PWM_r = 220;
   PWM_l = 200;
   
  digitalWrite(l2, LOW);
  digitalWrite(l1, HIGH);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r2, LOW);
  digitalWrite(r1, HIGH);
  analogWrite(enr, PWM_r);

  Serial.println("inside backward");
}

void halt()
{
   PWM_l = 0;
   PWM_r = 0;
  digitalWrite(l2, LOW);
  digitalWrite(l1, LOW);
  analogWrite(enl, PWM_l);
  
  digitalWrite(r2, LOW);
  digitalWrite(r1, LOW);
  analogWrite(enr, PWM_r);

  Serial.println("inside halt ");
}

