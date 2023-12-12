/*********************************************************************
 * @file  Affichage.h
 * @brief Définition de la classe Affichage
 *********************************************************************/
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "conf.h"
#include <Adafruit_NeoPixel.h>

class Affichage {
public:
    /**
     * @brief Constructeur de la classe Affichage
     */
    Affichage();

    /**
     * @brief Allume l'affichage en mettant en couleur toutes les LED
     */
    void Allumer();

    /**
     * @brief Éteint l'affichage en éteignant toutes les LED
     */
    void Eteindre();

    /**
     * @brief Allume les LED en blanc
     */
    void AllumerBlanc();

    /**
     * @brief Allume les LED proportionnelement au pourcentage de croquettes restantes
     * @param pourcentage Le pourcentage à afficher
     */
    void AllumerProportionnel(int pourcentage);

    /**
     * @brief Allume les LED en rouge
     */
    void AllumerRouge();

    /**
     * @brief Allume toutes les LED en vert
     */
    void AllumerVert();

    /**
     * @brief Gestion de l'affichage des LEDs en fonction du pourcentage des croquettes
     * niveau faible = toutes les LEDs rouge ,  niveau haut = toutes les LEDs vertes et entre c'est proportionnel au niveau
     * @param valeur  
     */
    void Gestion(int valeur);

private:
    Adafruit_NeoPixel strip;  // Instance de Adafruit_NeoPixel pour la gestion des LED
    int Etat;                 // État de l'affichage (allumé ou éteint)
};

#endif