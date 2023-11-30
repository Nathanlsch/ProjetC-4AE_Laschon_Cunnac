#include "Affichage.h"


Affichage::Affichage() {
        Etat = 0;
        strip = setup();
}

Adafruit_NeoPixel Affichage::setup(){
    Adafruit_NeoPixel strip (NbLed, DataIn, NEO_GRB + NEO_KHZ800);
    return strip;
}

void Affichage::Allumer(){

}

