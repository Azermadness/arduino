const int LR=6;
const int LV=5;
const int LB=3;
const int R=0;
const int V=0;
const int B=0;

int vitesse=10;

void setup() {

  pinMode(LR,OUTPUT);
  pinMode(LV,OUTPUT);
  pinMode(LR,OUTPUT);

}

void loop() {

  for(int i=0;i<=255;i++) ledRVB(i,0,0);
  for(int i=0;i<=255;i++) ledRVB(0,i,0);
  for(int i=0;i<=255;i++) ledRVB(0,0,i);
  for(int i=0;i<=255;i++) ledRVB(i,0,255-i);
  for(int i=0;i<=255;i++) ledRVB(255-i,i,0);
  for(int i=0;i<=255;i++) ledRVB(0,255-i,i);
  for(int i=0;i<=50;i++) {
    ledRVB(random(0,255),random(0,255),random(0,255));
    delay(150);
    ledRVB(0,0,0);
    delay(150);
  }

}

void ledRVB(int rge,int vrt,int blu) {
  
  analogWrite(LR,rge);
  analogWrite(LV,vrt);
  analogWrite(LB,blu);
  
  delay(vitesse);

}
