int V1=2;
int O1=3;
int R1=4;
int V2=5;
int O2=6;
int R2=7;

const int Sor[6] = {2,3,4,5,6,7};

void setup() {

  for(int i=0 ;i<6 ;i++) {
    pinMode(Sor[i], OUTPUT);
  }

}

void loop() {

  digitalWrite(V1,HIGH);
  digitalWrite(R2,HIGH);

  delay(2000);

  digitalWrite(V1,LOW);
  digitalWrite(O1,HIGH);

  delay(500);

  digitalWrite(O1,LOW);
  digitalWrite(R1,HIGH);

  delay(2000);

  digitalWrite(R2,LOW);
  digitalWrite(V2,HIGH);

  delay(2000);

  digitalWrite(V2,LOW);
  digitalWrite(O2,HIGH);

  delay(500);

  digitalWrite(O2,LOW);
  digitalWrite(R2,HIGH);

  delay(2000);

  digitalWrite(R1,LOW);

}
