
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <utility/imumaths.h>

  
Adafruit_BNO055 bno = Adafruit_BNO055(55); 

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
float kp = 0.1;
float kd = 0.002;
float ki = 0.001;


void setup(void) 
{
  Serial.begin(9600);
//  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
//    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}
 
void loop(void) 
{
  imu::Vector<3> euler_gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  
imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
//  Serial.print('G');
//  Serial.print(" ");
  Serial.print(euler_gyro.x());
  Serial.print(" ");
  Serial.print(euler_gyro.y());
  Serial.print(" ");
  Serial.print(euler_gyro.z());
  Serial.println(" ");

  imu::Vector<3> euler_lacc = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

//  Serial.print('A');
//Serial.print(" ");
  Serial.print(euler_lacc.x());
  Serial.print(" ");
 Serial.print(euler_lacc.y());
  Serial.print(" ");
  Serial.print(euler_lacc.z());
  Serial.print(" ");
//  Serial.println('\n');
delay(100);
 
}
