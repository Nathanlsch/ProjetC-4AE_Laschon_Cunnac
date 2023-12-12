/*********************************************************************
 * @file  Affichage.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de la classe Affichage
 *********************************************************************/
#include "Affichage.h"

Affichage::Affichage() : strip(24, 4, NEO_GRB + NEO_KHZ800) {
    Etat = 0;
    strip.begin();
    strip.setBrightness(25); // maximum 255
    strip.show();
}

void Affichage::Allumer() {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 250);
    }
    strip.show();
    Etat = 1;
}

void Affichage::Eteindre() {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    Etat = 0;
}

void Affichage::AllumerBlanc() {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 255, 255);
    }
    strip.show();
    Etat = 1;
}

void Affichage::AllumerProportionnel(int pourcentage) {
    int numLedsAllumees = (pourcentage * strip.numPixels()) / 100;

    for (int i = 0; i < numLedsAllumees; i++) {
        strip.setPixelColor(i, 250, 250, 250);
    }

    for (int i = numLedsAllumees; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 0);
    }

    strip.show();
    Etat = 1;
}

void Affichage::AllumerRouge() {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 250, 0, 0);
    }
    strip.show();
    Etat = 1;
}

void Affichage::AllumerVert() {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 250, 0);
    }
    strip.show();
    Etat = 1;
}

void Affichage::Gestion(int valeur) {
    if (valeur < 20) {
        AllumerRouge();
    } else if (valeur > 80) {
        AllumerVert();
    } else {
        AllumerProportionnel(valeur);
    }
}
