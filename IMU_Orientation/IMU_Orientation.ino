
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <utility/imumaths.h>

  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
 
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
  imu::Vector<3> euler_gyro = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  
//  Serial.print('G');
//  Serial.print(" ");
  Serial.print(euler_gyro.x());
  Serial.print(" ");
  Serial.print(euler_gyro.y());
  Serial.print(" ");
  Serial.print(euler_gyro.z());
  Serial.println("\n");

  imu::Vector<3> euler_lacc = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

////  Serial.print('A');
////Serial.print(" ");
//  Serial.print(euler_lacc.x());
//  Serial.print(" ");
// Serial.print(euler_lacc.y());
//  Serial.print(" ");
//  Serial.print(euler_lacc.z());
//  Serial.print(" ");
////  Serial.println('\n');
delay(100);
 
}
