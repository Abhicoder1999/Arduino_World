#include <SPI.h>


void setup() {
  Serial.begin(115200);
  digitalWrite(SS,HIGH); //Master Code
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
  char c;
  
  if(Serial.available())
   {
    digitalWrite(SS,LOW);
    char c = Serial.read();
    SPI.transfer(c);
    Serial.print(c);//
    }

  digitalWrite(SS,HIGH); 
  delay(2000);
  
}
