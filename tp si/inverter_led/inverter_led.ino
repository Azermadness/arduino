const int APPUI=0;
const int LED=3;
const int BP=2;

int etatLED=0;

void setup() {

  pinMode(LED,OUTPUT);
  pinMode(BP,INPUT);
  digitalWrite(BP,HIGH);

}

void loop() {

  if(digitalRead(BP)==APPUI) {
    if(etatLED==0) etatLED=1;else etatLED=0;
    delay(250);
    
  }

  if(etatLED==1) {
    digitalWrite(LED,HIGH);
  }
  else digitalWrite(LED,LOW);

}
