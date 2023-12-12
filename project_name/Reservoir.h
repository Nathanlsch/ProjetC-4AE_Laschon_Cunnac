/*********************************************************************
 * @file  Reservoir.h
 * @brief Fichier d'en-tête de la classe Reservoir
 *********************************************************************/
#ifndef RESERVOIR_H
#define RESERVOIR_H
#include "Ultrasonic.h"
#include "conf.h"

/**
 * @class Reservoir
 * @brief Classe Reservoir représentant le réservoir de croquettes
 */
class Reservoir{
    
    private:
    
    bool Vide;
    long Dist_Fond;                 // Variable representant la distance mesurée par le capteur ultrason 
    Ultrasonic CapteurUltrason;     // Instance de capteur ultrason
    
    public:

    /**
     * @fn Reservoir()
     * @brief Constructeur par défaut de la classe Reservoir
     */
    Reservoir();

    /**
     * @fn ~Reservoir()
     * @brief Destructeur de la classe Reservoir
     */
    ~Reservoir();

    /**
     * @fn bool getVide()
     * @brief Retourne l'état du réservoir (vide ou non)
     * @return true si le réservoir est vide, false sinon
     */
    bool getVide();

    /**
     * @fn bool EtatReservoir()
     * @brief Vérifie l'état du réservoir en fonction de la distance mesurée par le capteur
     * @return true si la distance mesurée est supérieure à la distance maximale établie, indiquant que le réservoir est vide
     */         
    bool EtatReservoir();

    /**
     * @fn void MAJ()
     * @brief Met à jour les informations du réservoir
     */
    void MAJ();

    /**
     * @fn long Pourcentage()
     * @brief Calcule le pourcentage de remplissage du réservoir
     * @return Pourcentage de remplissage du réservoir
     */
    long Pourcentage();
    
    /**
     * @fn void Affichage()
     * @brief Affiche la distance mesurée par le capteur fonction de test
     */
    void Affichage();
};

#endif
