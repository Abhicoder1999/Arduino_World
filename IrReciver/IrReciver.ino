#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>
long x;

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  
  if (irrecv.decode(&results)){
        x = results.value;
        Serial.println(x, HEX);
        if(results.value == 0x1FE50AF)
       Serial.println("successful");
        
        irrecv.resume();
  }
}

