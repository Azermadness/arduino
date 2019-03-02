int piezo=2;

int millis0=0;

void setup() {

  pinMode(piezo,OUTPUT);

  millis0=millis();

}

void loop() {

  for(int freq=500;freq<=1000;freq++) {
     tone(piezo,freq);
  delay(1);
  }

  for(int freq=1000;freq>=500;freq--) {
    tone(piezo,freq);
    delay(1);
  }

  if(millis()-millis0>10000) {
    noTone(piezo);
    while(1);
  }
}
