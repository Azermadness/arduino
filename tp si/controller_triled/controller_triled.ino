const int LB=3;
const int LV=5;
const int LR=6;

const boolean R=true;
const boolean V=true;
const boolean B=true;

int vitesse=1000;

void setup() {

  pinMode(LV,OUTPUT);
  pinMode(LR,OUTPUT);
  pinMode(LB,OUTPUT);

}

void loop() {

  ledRVB(R,0,0),ledRVB(0,0,0);
  ledRVB(0,V,0),ledRVB(0,0,0);
  ledRVB(0,0,B),ledRVB(0,0,0);
  ledRVB(R,V,0),ledRVB(0,0,0);
  ledRVB(R,0,B),ledRVB(0,0,0);
  ledRVB(0,V,B),ledRVB(0,0,0);
  ledRVB(R,V,B),ledRVB(0,0,0);
}

void ledRVB(boolean Rouge,boolean Vert,boolean Bleu) {

  if(Rouge==true) digitalWrite(LR,HIGH);
  else digitalWrite(LR,LOW);

  if(Vert==true) digitalWrite(LV,HIGH);
  else digitalWrite(LV,LOW);

  if(Bleu==true) digitalWrite(LB,HIGH);
  else digitalWrite(LB,LOW);

  delay(vitesse);

}
