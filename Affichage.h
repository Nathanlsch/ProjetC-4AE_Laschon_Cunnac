#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "conf.h"
#include "Adafruit_NeoPixel.h"

class Affichage {


private : 
    bool Etat;
    Adafruit_NeoPixel strip;

public : 

Adafruit_NeoPixel setup();

Affichage();
void Allumer();
void Eteindre();

};

#endif;
