#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>


#define RedPin 3
#define GreenPin 5
#define BluePin 9

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value;

//The following are the IRremote 1-6 button recived Hex values
//0x1FE50AF
//0x1FED827
//0x1FEF807
//0x1FE30CF
//0x1FEB04F
//0x1FE708F


void setColor(int RedValue,int GreenValue, int BlueValue )
  {  
     analogWrite(RedPin,RedValue);
     analogWrite(GreenPin,GreenValue);
     analogWrite(BluePin,BlueValue);
             
  }
  
void setup() {
  
      pinMode(RedPin, OUTPUT);
      pinMode(BluePin, OUTPUT);
      pinMode(GreenPin, OUTPUT);   
      irrecv.enableIRIn();
      irrecv.blink13(true); //this will make the 13th LED blink when
      
}


void loop() {

   if (irrecv.decode(&results)){
        Serial.println("Inside the loop");//
        if(results.value == 0xFFFFFFFF)
        {results.value = key_value; Serial.println("repeated");}//
        else
        {key_value = results.value;Serial.println("Not same");}//
        
        Serial.println(results.value, HEX);
         
        switch (results.value){
        case 0x1FE50AF: setColor(255,0,0);Serial.println("red"); break;
        case 0x1FED827: setColor(0,255,0);Serial.println("blue"); break;
        case 0x1FEF807: setColor(0,0,255);Serial.println("green"); break;
        case 0x1FE30CF: setColor(255,255,255);Serial.println("white"); break;
        }
               
        irrecv.resume();
  }

}
