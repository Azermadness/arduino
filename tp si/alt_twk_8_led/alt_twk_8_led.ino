const int LED[8] = {2,3,4,5,6,7,8,9};

int vitesse=50;


void setup() {

  for(int i=0; i<8 ;i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {

 for(int numLED=0 ;numLED<8 ;numLED++) {
    
    for(int i=0; i<8; i++) {

      if(i==numLED) {
        digitalWrite(LED[i],HIGH);
      }
      else {
        digitalWrite(LED[i],LOW);
      }  
      
    }
    delay(vitesse);
    
  }
  
}
