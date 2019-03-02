const int LED=3;
const int BP=2;
const int APPUI=0;
int etatLED=0;


void setup() {

  pinMode(LED,OUTPUT);
  pinMode(BP,INPUT);
  digitalWrite(BP,HIGH);

}

void loop() {

  if(digitalRead(BP)==APPUI) {
    digitalWrite(LED,HIGH);
    delay(5000);
    digitalWrite(LED,LOW);
  }

}
