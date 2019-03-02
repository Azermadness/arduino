const int LED[4] = {2,3,4,5};

int vitesse=1000;

void setup() {
  
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT); 
}

void loop() {
  
  digitalWrite(LED[0],HIGH);
  digitalWrite(LED[1],HIGH);
  digitalWrite(LED[2],HIGH);
  digitalWrite(LED[3],HIGH);

  delay(vitesse);

  digitalWrite(LED[1],LOW);
  digitalWrite(LED[2],LOW);
  digitalWrite(LED[3],LOW);
  digitalWrite(LED[0],LOW);

  delay(vitesse);
}
