int BluetoothData;
void setup() {
  
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  
  if(Serial.available()){
    
        BluetoothData = Serial.read();
        Serial.println(BluetoothData);    

      if(BluetoothData == 56){
        //for backwards movement
            digitalWrite(8,LOW);
            digitalWrite(9,HIGH);
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);        
            delay(110);
        }
        
      if(BluetoothData == 50){
        //for forward movement
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            delay(110);        
        }
    
      if(BluetoothData == 52){
        //for left movement
            digitalWrite(8,LOW);
            digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);        
            delay(110);
        }
    
      if(BluetoothData == 54){
        //for right movement
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);        
            delay(110);
        }  

       if(BluetoothData == 53){
        //Stop
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);        
            delay(110);
        }
    }

}
