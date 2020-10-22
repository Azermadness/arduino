//boucle interrupteur
//if (digitalRead(2)==1) {
//  if (altern==0) {
//    altern=1;
//    digitalWrite(pin_relais,HIGH);
//    delay(500);
//  }
//  else {
//    altern=0;
//    digitalWrite(pin_relais,LOW);
//    delay(500);
//  }
//}

//boucle aquerir heures ou minutes
//
//SeeedOled.setTextXY(0,0);
//SeeedOled.putString("heure:");
//SeeedOled.setTextXY(4,3);
//while(digitalRead(butt_pin)==0) {
//  SeeedOled.putString(val_hrs);
//  }
//int hrs_val==digitalRead(butt_pin)
//
//
//




#include <Wire.h>
#include <SeeedOLED.h>

const int pin_relais=4;
const int butt_pin=2;
int altern=0;




void setup() {
  Serial.begin(115200);
  Wire.begin();
  SeeedOled.init();  //initialise le SEEED OLED display
  SeeedOled.clearDisplay();          //nettoie l'écran et pose la position d'écriture en haut a gauche
  SeeedOled.setNormalDisplay();      //met l affichage en mode normal (non mode inverse)
  SeeedOled.setPageMode();           //mode d envoie des données mis par defaut(par paquets)
  SeeedOled.setTextXY(0,0);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(35,INPUT);
  pinMode(A5,INPUT);
}

void loop() {
  
  digitalWrite(2,HIGH);
  int val_pot=analogRead(A5);
  int val_min=map(val_pot,0,1023,0,59);
  int val_hrs=map(val_pot,0,1023,0,23);
  Serial.println(val_pot);
  Serial.println(val_min);
  Serial.println(val_hrs);
  if (digitalRead(35)==HIGH) {
    Serial.println("bouton actif");
  }
  Serial.println(altern);
  delay(10);




//boucle switch pour activer une pin en high ou low

  if (digitalRead(35)==HIGH) {
    digitalWrite(pin_relais,HIGH);
    delay(50);
  }
  else {
    digitalWrite(pin_relais,LOW);
  }


}
