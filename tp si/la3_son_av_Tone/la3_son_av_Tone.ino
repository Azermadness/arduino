const int piezo=2;

int la3=440;

void setup() {

  pinMode(piezo,OUTPUT);
  
}

void loop() {

  tone(piezo,la3);
  delay(500);
  noTone(piezo);
  delay(500);
}
