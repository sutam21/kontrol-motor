#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial bluetooth(0,1); // pin RX | TX
SoftwareSerial mp3player(10,11); // pin RX | TX
String voice;
#define r1 6 // Pengaman
#define r2 7 // Starter
#define r3 8 // Menghidupkan Kontak


/*
 * 0001 Intro
 * 0002 Nama
 * 0003 Welcome
 * 0004 Mkontak
 * 0005 Hkontak
 * 0006 Mmesin
 * 0007 Hmesin
 * 0008 Nmesin
 * 0009 Mpengaman
 * 0010 Search
 */
 
void bukakontak(){
  mp3_play(5);
  delay(3000);
  digitalWrite(r3, LOW); // menghidupkan kontak pada NO di relay 3
}

void tutupkontak(){
  digitalWrite(r3, HIGH); // mematikan kontak pada NO di relay 3
}

void pengamanon(){
  digitalWrite(r1, HIGH); // mematikan relay 1
}

void pengamanoff(){
  mp3_play(9);
  delay(3000);
  digitalWrite(r1, LOW); // menghidupkan relay 1
}

void stater(){
  delay(3000);
  digitalWrite(r2, LOW);
  delay(2000);
  digitalWrite(r2, HIGH);
  mp3_stop();
}

void lagu_fav(){
mp3_play(10);
delay(4000);
mp3_play(11);
}

void setup(){
  Serial.begin(9600);
  mp3player.begin(9600);
  mp3_set_serial(mp3player);
  delay(1);
  mp3_set_volume(30);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
}

void loop() {
  while (Serial.available()){
    delay(10);
    char c = Serial.read();
    if(c == '#'){break;}
    voice += c;
  }
  if(voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//
/*
 * Indonesian Language
 */
// menghidupkan pengaman | mematikan mesin

/*  if(voice == "buka kontak"){
    bukakontak();
  }
  else if(voice == "tutup kontak"){
    tutupkontak();
  }
*/
  if(voice == "hidupkan pengaman"){
    pengamanon();
  }

  else if(voice == "matikan mesin"){
    pengamanon();
  }

  else if(voice == "Matikan mesin"){
    pengamanon();
  }

  else if(voice == "matikan pengaman"){
    pengamanoff();
  }

//---------------------------------------------//
// menyalakan mesin
  if(voice == "hidupkan mesin"){
    mp3_play(7);
    stater();  
  }
  
  else if(voice == "Nyalakan mesin"){
    mp3_play(8);
    stater();
  }

//---------------------------------------------//
// Memutar lagu favorite
  if(voice == "Putar lagu kesukaan saya"){
    lagu_fav();
  }

  else if(voice == "putar lagu kesukaan saya"){
    lagu_fav();
  }

  else if(voice == "lagu berikutnya"){
    mp3_next();
  }

  else if(voice == "lagu sebelumnya"){
    mp3_prev();
  }
  else if(voice == "jeda musik"){
    mp3_pause();
  }

  else if(voice == "lanjutkan musik"){
    mp3_play();
  }

  else if(voice == "Matikan musik"){
    mp3_stop();
  }
//---------------------------------------------//
voice="";}}
