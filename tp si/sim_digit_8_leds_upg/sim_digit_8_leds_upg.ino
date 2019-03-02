const int LED[8] = {2,3,4,5,6,7,8,9};

int vitesse=500;

void setup() {

  for(int i=0 ;i<8 ;i++) {
    pinMode(LED[i],OUTPUT);
  }

}

void loop() {

  allumeLED(B01100000);
  allumeLED(B11011010);
  allumeLED(B11110010);
  allumeLED(B01100110);
  allumeLED(B10110110);
  allumeLED(B10111110);
  allumeLED(B11100000);
  allumeLED(B11111110);
  allumeLED(B11110110);
}

void allumeLED(unsigned int valeur) {

  for(int i=0; i<=7; i++) {
    digitalWrite(LED[i],bitRead(valeur,7-i));
    
  }
  delay(vitesse);
}
