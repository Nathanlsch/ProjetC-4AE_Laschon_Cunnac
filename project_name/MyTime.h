#ifndef MYTIME_H
#define MYTIME_H

#include <WiFiUdp.h>
#include "NTPClient.h"

class MyTime {

  private :
    int Heure[3];
    const long gmtOffset_sec = 3600; // GMT+1 (par exemple, Paris)
    const int daylightOffset_sec = 3600; // Décalage d'été (1 heure en secondes)
    WiFiUDP ntpUDP;
    NTPClient timeClient;

  public :
    MyTime();
    ~MyTime();

    void setup();

    void MajHeure();

    String getHeure();


};

#endif