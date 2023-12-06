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
}

void MyTime::setup(){
  timeClient.begin();
}

