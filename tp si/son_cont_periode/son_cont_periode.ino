const int piezo=2;

int periode=1000;

void setup() {
  pinMode(piezo,OUTPUT);

}

void loop() {

  digitalWrite(piezo,HIGH);
  delayMicroseconds(periode);
  digitalWrite(piezo,LOW);
  delayMicroseconds(periode);

}
