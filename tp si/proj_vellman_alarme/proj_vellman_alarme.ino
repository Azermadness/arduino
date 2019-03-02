void setup() {

  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(3,INPUT);
  digitalWrite(3,LOW);

}

void loop() {

  digitalWrite(2,HIGH);

  if(digitalRead(3)==0) {
    digitalWrite(7,HIGH);
  }
  else digitalWrite(7,LOW);
}
