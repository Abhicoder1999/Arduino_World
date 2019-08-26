void setup() {
  pinMode(14,OUTPUT);
  pinMode(2,OUTPUT);

}

void loop() {
  digitalWrite(2,HIGH);
  delay(400);
  digitalWrite(2,LOW);
  delay(400);
  digitalWrite(14,HIGH);
  digitalWrite(2,HIGH);
  delay(400);
  digitalWrite(2,LOW);
  delay(400); 
  digitalWrite(14,LOW);
}
