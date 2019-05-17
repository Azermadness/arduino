
#include <SoftwareSerial.h>
const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;
const unsigned int BAUD_RATE = 9600;

// Var/Tours
int course = 0;
int passage =0;
int passageold=0;
// setup Afficheur
int delai_latence = 1;
int digit1 = 2;// chiffre des 1000
int digit2 = 3;// chiffre des 100
int digit3 = 4;// chiffre des 10
int digit4 = 5;// chiffre des 1
int segA = 6;// haut
int segB = 7;// haut droit
int segC = 8;// bas droit
int segD = 9;// bas
int segE = 10;// bas gauche
int segF = 11;// haut gauche
int segG = A0;// millieux

//void = fonction, contient le programme
//setup : configuration
void setup()
{     

 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 Serial.begin(BAUD_RATE);
 pinMode(segA, OUTPUT);
 pinMode(segB, OUTPUT);
 pinMode(segC, OUTPUT);
 pinMode(segD, OUTPUT);
 pinMode(segE, OUTPUT);
 pinMode(segF, OUTPUT);
 pinMode(segG, OUTPUT);
 pinMode(digit1, OUTPUT);
 pinMode(digit2, OUTPUT);
 pinMode(digit3, OUTPUT);
 pinMode(digit4, OUTPUT);

digitalWrite(digit1, LOW);
digitalWrite(digit2, LOW);
digitalWrite(digit3, LOW);
digitalWrite(digit4, LOW);
//on commence par tout éteindre
}


void afficheDigit(int num)
// == égalité entre 2 variables , signifie "est égal à"
{
 if (num==0)
   {
   digitalWrite(segA, LOW); //allumer a
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, HIGH); //éteindre g
   }

 if (num==1)
   {
   digitalWrite(segA, HIGH);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, HIGH);
   }

 if (num==2)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, HIGH);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, LOW);
   }

 if (num==3)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, LOW);
   }

 if (num==4)
   {
   digitalWrite(segA, HIGH);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   }

 if (num==5)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, HIGH);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
    }

 if (num==6)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, HIGH);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   }

 if (num==7)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, HIGH);
   }

 if (num==8)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   }

 if (num==9)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   }
}


void affiche4digits(int num)
//Affiche un nb à 4 chiffres
{
int nb;
// arduino calcule des entiers

//affiche le chiffre des 1000
nb=num/1000;
digitalWrite(digit4, LOW);
digitalWrite(digit1, HIGH);
afficheDigit(nb);

delay(delai_latence);

//affiche le chiffre des 100
num=num-nb*1000;
nb=num/100;
digitalWrite(digit1, LOW);
digitalWrite(digit2, HIGH);
afficheDigit(nb);

delay(delai_latence);  

//affiche le chiffre des 10
num=num-nb*100;
nb=num/10;
digitalWrite(digit2, LOW);
digitalWrite(digit3, HIGH);
afficheDigit(nb);

delay(delai_latence);  

//affiche le chiffre des 1
num=num-nb*10;
nb=num;
digitalWrite(digit3, LOW);
digitalWrite(digit4, HIGH);
afficheDigit(nb);

delay(delai_latence);  
}

int distance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 29 / 2;
  if (duration == 0) {
    Serial.print("U r God we can't detect");
  }
  else {
    if (course < 100) {
      return 0;
    }
    else {
      return 1;
    }   
  }
}


void loop()
{
delai_latence=10;
passage = distance;
  if (passage != passageold){ 
    if (passage == 1){
      course=course+1;
      }
    passageold=passage;
    }
  afficheDigit(course);
}
