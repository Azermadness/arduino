const int LED[8] = {2,3,4,5,6,7,8,9};

int vitesse=50;

void setup() {

  for(int i=0 ;i<8 ;i++) {
    pinMode(LED[i], OUTPUT);
  }

}

void loop() {

  for(int repet=0 ;repet<10 ;repet++ ) {
    allumeLED(B01010101);
    allumeLED(B10101010);
  }
  
  for(int repet=0 ;repet<10 ;repet++ ) {
    allumeLED(B10000001);
    allumeLED(B01000010);
    allumeLED(B00100100);
    allumeLED(B00011000);
    allumeLED(B00011000);
    allumeLED(B00111100);
    allumeLED(B01111110);
    allumeLED(B11111111);
    allumeLED(B01111110);
    allumeLED(B00111100);
    allumeLED(B00011000);
    allumeLED(B00000000);
  }
}

void allumeLED(unsigned int valeur) {
  for(int i=0 ;i<7 ;i++) {
    digitalWrite(LED[i],bitRead(valeur,7-i));
  }
  delay(vitesse);
  
}
