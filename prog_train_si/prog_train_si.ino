//Start

#include <Servo.h>

Servo servo;
const int timerPiet=10000;     //delai pour appui pieton
unsigned int Begin;
const int feuV=2;
const int feuO=3;
const int feuR=4;
const int barr=5;
const int trArr=9;
const int trPass=10;
const int clignoR=11;
const int alarme=12;
const int pictoV=6;
const int pictoR=7;
const int BPpieton=8;
int trIci=0;                //devient =1 lorsque le train est present

const int pin[11] = {2,3,4,5,6,7,8,9,10,11,12};


void setup() {

  Serial.begin(115200);

  for(int i=0;i<11;i++) {
    pinMode(pin[i],OUTPUT);
  }
  pinMode(BPpieton,INPUT);
  pinMode(trArr,INPUT);
  pinMode(trPass,INPUT);
  servo.attach(5);
  servo.write(90);
  digitalWrite(feuV,HIGH);
  digitalWrite(pictoR,HIGH);
  digitalWrite(feuR,LOW);

}

void pieRfeuV() {
  digitalWrite(pictoV,LOW);
  digitalWrite(pictoR,HIGH);
  delay(3000);
  digitalWrite(feuV,HIGH);
  digitalWrite(feuR,LOW);
}

void pieVfeuR() {

  delay(1000);
  digitalWrite(feuV,LOW);
  digitalWrite(feuO,HIGH);
  delay(1000);
  digitalWrite(feuO,LOW);
  digitalWrite(feuR,HIGH);
  delay(1000);
  digitalWrite(pictoR,LOW);
  digitalWrite(pictoV,HIGH);
  
}

void barrHigh() {     //tempo enter servo.write(0)
  delay(100);
  servo.write(90);        //temporaireapres: for(int i=0;i<=90;i++) { enter servo.write(i); enter delay(30); enter }
}

void barrLow() {
  servo.write(90);
  delay(100);
  for(int i=90;i>=0;i--) {
    servo.write(i);
    delay(30);
  }
}

void Signal() {
  digitalWrite(clignoR,HIGH);
  digitalWrite(alarme,HIGH);
  delay(200);
  digitalWrite(clignoR,LOW);
  digitalWrite(alarme,LOW);
  delay(200);
}

void keepFeuR() {
  digitalWrite(feuR,HIGH);
  digitalWrite(feuO,LOW);
  digitalWrite(feuV,LOW);
  digitalWrite(pictoV,HIGH);
  digitalWrite(pictoR,LOW);
}


void loop() {

  
  Serial.println("BP train arrive");
  if(digitalRead(trArr)==HIGH) {  
    Serial.println("train est la");
    trIci=1;
    delay(500);
    digitalWrite(clignoR,HIGH);
    digitalWrite(alarme,HIGH);
    delay(500);
    digitalWrite(feuV,LOW);
    digitalWrite(feuO,HIGH);
    digitalWrite(clignoR,LOW);
    digitalWrite(alarme,LOW);
    delay(500);
    digitalWrite(clignoR,HIGH);
    digitalWrite(alarme,HIGH);
    digitalWrite(feuO,LOW);
    digitalWrite(feuR,HIGH);
    delay(500);
    digitalWrite(clignoR,LOW);
    digitalWrite(alarme,LOW);
    delay(500);
    digitalWrite(clignoR,HIGH);
    digitalWrite(alarme,HIGH);
    delay(500);
    digitalWrite(pictoR,LOW);
    digitalWrite(pictoV,HIGH);
    digitalWrite(clignoR,LOW);
    digitalWrite(alarme,LOW);
    barrLow; 
    servo.write(90);
    delay(100);
    for(int i=90;i>=0;i--) {
      servo.write(i);
      delay(30); 
    }
    while(digitalRead(trPass)==LOW) {                            
      digitalWrite(clignoR,HIGH);
      digitalWrite(alarme,HIGH);
      delay(500);
      digitalWrite(clignoR,LOW);
      digitalWrite(alarme,LOW);
      delay(500);
      }                                  
    trIci=0;
    servo.write(0);
    delay(100);
    for(int i=0;i<=90;i++) {
      servo.write(i);
      delay(30);
      }
    delay(1000);
    while((millis()-Begin)<=timerPiet) {
      
    }
    digitalWrite(pictoV,LOW);
    digitalWrite(pictoR,HIGH);
    delay(3000);
    digitalWrite(feuV,HIGH);
    digitalWrite(feuR,LOW);
  }

  else {
    
    delay(50);
    Serial.println("BP pieton");
    
    if(digitalRead(BPpieton)==HIGH) {
      Serial.println("debut delay");
      delay(2000);
      Begin = millis();
      Serial.println("millis set");
      delay(1000);
      digitalWrite(feuV,LOW);
      digitalWrite(feuO,HIGH);
      delay(1000);
      digitalWrite(feuO,LOW);
      digitalWrite(feuR,HIGH);
      delay(1000);
      digitalWrite(pictoR,LOW);
      digitalWrite(pictoV,HIGH);

        while((millis()-Begin)<=timerPiet) {
          Serial.println("timer en cours");
          delay(50);
    }
      if(trIci==1) {
      Serial.println("attente trPass");
      while(digitalRead(trPass)==LOW) {
         digitalWrite(feuR,HIGH);
         digitalWrite(feuO,LOW);
         digitalWrite(feuV,LOW);
         digitalWrite(pictoV,HIGH);
         digitalWrite(pictoR,LOW);
      }
      digitalWrite(pictoV,LOW);
      digitalWrite(pictoR,HIGH);
      delay(3000);
      digitalWrite(feuV,HIGH);
      digitalWrite(feuR,LOW); 
    }
    else {
      digitalWrite(pictoV,LOW);
      digitalWrite(pictoR,HIGH);
      delay(3000);
      digitalWrite(feuV,HIGH);
      digitalWrite(feuR,LOW);
    } 
   }
  }
  delay(50);

}




//END
