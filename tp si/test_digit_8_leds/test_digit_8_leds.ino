const int LED[8] = {2,3,4,5,6,7,8,9};

int vitesse=200;

void setup() {

  for(int i=0 ;i<8 ;i++) {
    pinMode(LED[i], OUTPUT);
  }
  
}

void loop() {

  for(int i=0 ;i<8 ;i++) {

    digitalWrite(LED[i],HIGH);
    delay(vitesse);
    digitalWrite(LED[i],LOW);
  }

}
