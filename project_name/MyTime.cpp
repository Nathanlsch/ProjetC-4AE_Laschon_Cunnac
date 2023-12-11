#include "MyTime.h"

MyTime::MyTime() : timeClient(ntpUDP, "pool.ntp.org", gmtOffset_sec){
  Heure[0]=0;
  Heure[1]=0;
}

MyTime::~MyTime(){

}

void MyTime::MajHeure() {
  timeClient.update();
  Heure[0]= timeClient.getHours();
  Heure[1] = timeClient.getMinutes();
  Heure[2] = timeClient.getSeconds();
}

void MyTime::setup(){
  timeClient.begin();
}

String MyTime::getHeure(){
  
  String chaineDeCaracteres1 = String(this->Heure[0]);
  String chaineDeCaracteres2 = String(this->Heure[1]);
  String chaineDeCaracteres3 = String(this->Heure[2]);
  String chaineDeCaracteres =  chaineDeCaracteres1 +":"+chaineDeCaracteres2+":"+chaineDeCaracteres3;
  Serial.println( chaineDeCaracteres);
  return  chaineDeCaracteres;
}

