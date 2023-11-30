#include "Affichage.h"


Affichage::Affichage() {
        Etat = 0;
        strip = setup();
}

Adafruit_NeoPixel Affichage::setup(){
    Adafruit_NeoPixel strip (NbLed, DataIn, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.show();
    return strip;
}

void Affichage::Allumer(){
    for (int i = 0; i <= NbLed; i++) {
      strip.setPixelColor(i, 0, 0, 250);
    }
    strip.show();
    Etat = 1;
}

void Affichage::Eteindre(){
    for (int i = 0; i <= NbLed; i++) {
      strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    Etat = 0;
}



