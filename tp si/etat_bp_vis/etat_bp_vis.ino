const int APPUI=0;
const int BP=2;
const int LED=3;

int ETAT_BP=0;


void setup() {

  pinMode(LED,OUTPUT);
  pinMode(BP,INPUT);
  digitalWrite(BP,HIGH);

}

void loop() {

  ETAT_BP=digitalRead(BP);

  if(ETAT_BP==APPUI){
    digitalWrite(LED,1);
  }
  else {
    digitalWrite(LED,0);
  }

}
