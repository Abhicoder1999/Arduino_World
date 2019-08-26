#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <utility/imumaths.h>

//IMU communication
Adafruit_BNO055 bno = Adafruit_BNO055(55);
float w = 0.1; //in rad per sec
float t = 6.28/w; // in sec
float v = 2; // m/s


// Pin Config
//int pwm_a = 10; //PWM control for motor outputs 1 and 2 is on digital pin 10

int l1=2;//A3
int l2=4;//A2

int r1=7;//A1
int r2=8;//A0


int enl=3;//11
int enr=6;//10

//Control Variables
int PWM_l = 0; // Change the intial values to velocity mapping
int PWM_r = 0;
int PWM_diff = 20;
int tune_PWM = 50; 
float kp = 0.2;
float kd = 0.002;
float ki = 0.001;
unsigned long time_lapsed;
float theta = 0;
float last_error = 0;

void setup() 
{
  Serial.begin(9600);
//  Serial.println("inside setup");/
   if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no/ BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);

  
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
//  Serial.println("inside loop"); /
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  if(Serial.available())
  {
    
    int ch = Serial.read();
      Serial.println(ch);
      if((char)ch == 'F')
      { 
        unsigned long time_start = millis();
        while((char)ch != 'S')
         { 
        
           euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
           forward(euler.x(),euler.y(),euler.z(),time_start);
           ch = Serial.read();  
           
         }
      }
      if((char)ch == 'S')
       {
        halt();
        theta = 0;
       }
  } 

}

void forward(float a1, float a2, float a3, unsigned long time_start)
{
   long error;
   theta = ( (millis() - time_start)*360.0)/(t*1000.0);
   error = theta - a1;
   PWM_diff = kp*error ;//+ kd*(error - last_error);
//   Serial.print(" "); 
   last_error = error;
   
   Serial.print(a1);
   Serial.print(" ");
   Serial.print(theta);
   Serial.print(" "); 
   Serial.print(PWM_diff);
   Serial.print("\n");
   PWM_r = 70 + PWM_diff; // this base will depend on the velocity
   PWM_l = 55;
   
   digitalWrite(l2, HIGH);
   digitalWrite(l1, LOW);
   analogWrite(enl, PWM_l);
  
   digitalWrite(r2, HIGH);
   digitalWrite(r1, LOW);
   analogWrite(enr, PWM_r);
//  / Serial.println("inside forward");
   
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


