#include <SPI.h>..



char buff;
volatile byte indx;
volatile boolean process;

void setup(void) {
      Serial.begin (115200);
      
      pinMode(MISO, OUTPUT);
      pinMode(5,OUTPUT);
      SPCR |= _BV(SPE); //Turn ON SPI in slave mode
      process = false; 
      SPI.attachInterrupt(); //Turn on interupt
}

ISR(SPI_STC_vect)
 {    Serial.println("called");
      byte c = SPDR; //read the byte sent from the SPI data register
          buff = c;
          process = true;  
  }

void loop(void) {
      if(process)
      {     Serial.println("Recived Something");
            if(buff == 'a')
            {
               Serial.println("Successful");
               digitalWrite(5,HIGH);
               delay(2000);
               digitalWrite(5,LOW);
            }
            process = 0;
      }
}
