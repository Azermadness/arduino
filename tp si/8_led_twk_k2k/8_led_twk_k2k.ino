const int LED[8] = {2,3,4,5,6,7,8,9};
int vitesse=20;

void setup() {
  
  for(int i=0 ;i<8 ;i++) {
    pinMode(LED[i], OUTPUT);
  }  
}

void loop() {

  for(int numLED=0 ;numLED<8 ;numLED++) {

    allumeLED(numLED);
    delay(vitesse);
  }

  for(int numLED=0 ;numLED<8 ;numLED++) {
    allumeLED(7-numLED);

    delay(vitesse);
  }
  
}

void allumeLED (int numLEDIn) {

  for(int i=0 ;i<8 ;i++) {
    if(i==numLEDIn) {
      digitalWrite(LED[i],HIGH);
    }
    else {
      digitalWrite(LED[i],LOW);
    }
  }
  
}
