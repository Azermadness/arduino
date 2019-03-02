const int piezo=2;

const int nbnotes=11;

int DO=262;
int RE=294;
int MI=330;
int note[nbnotes]={DO,DO,DO,RE,MI,RE,DO,MI,RE,RE,DO};
int duree[nbnotes]={1,1,1,1,1,2,1,1,1,1,1};

void setup() {

  pinMode(piezo,OUTPUT);
}

void loop() {

  for(int i=0;i<nbnotes;i++) {

    tone(piezo,note[i]);
    delay(500*duree[i]);

    noTone(piezo);
    delay(100);
  }

  noTone(piezo);
  delay(1000);
}
