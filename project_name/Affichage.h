// Affichage.h
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Adafruit_NeoPixel.h>

class Affichage {
public:
    Affichage();

    void Allumer();
    void Eteindre();
    void AllumerBlanc();
    void AllumerProportionnel(int pourcentage);
    void AllumerRouge();
    void AllumerVert();
    void Gestion(int valeur);

private:
    Adafruit_NeoPixel strip;
    int Etat;
};

#endif  // AFFICHAGE_H