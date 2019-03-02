const int LED[8] = {2,3,4,5,6,7,8,9};

int vitesse=1000;

void setup() {

  for(int i=0;i<8;i++) {
    pinMode(LED[i],OUTPUT);
  }

}

void loop() {

  for(int chiffre=0;chiffre<10;chiffre++) {
    digit(chiffre,chiffre % 2);

    delay(vitesse);
  }

  digit(-1, false);
  delay(vitesse);

}

void allumeLED(unsigned int valeur) {

  for(int i=0;i<7;i++) {
    digitalWrite(LED[i],bitRead(valeur,7-i));
  }
  
}

void digit(int chiffrein, boolean pointin) {

  if(chiffrein==1) allumeLED(B01100000);
  if(chiffrein==2) allumeLED(B11011010);
  if(chiffrein==3) allumeLED(B11110010);
  if(chiffrein==4) allumeLED(B01100110);
  if(chiffrein==5) allumeLED(B10110110);
  if(chiffrein==6) allumeLED(B10111110);
  if(chiffrein==7) allumeLED(B11100000);
  if(chiffrein==8) allumeLED(B11111110);
  if(chiffrein==9) allumeLED(B11110110);
  if(chiffrein<0) allumeLED(B00000000);
  if(pointin==true) digitalWrite(LED[7],HIGH);
  else digitalWrite(LED[7],LOW);
}
