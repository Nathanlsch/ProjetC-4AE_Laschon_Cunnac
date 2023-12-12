/*********************************************************************
 * @file  Trappe.h
 * @brief Fichier header de la classe Trappe, héritant de la classe Porte
 *********************************************************************/
#ifndef TRAPPE_H
#define TRAPPE_H
#include "Porte.h"
#include <Servo.h>
#include "conf.h"


/**
 * @class Trappe
 * @brief Classe Trappe, héritant de la classe Porte
 */
class Trappe : public Porte{

  private :

    Servo ServoTrap;    // Instance Servo pour la trappe
  
  public :

    /**
     * @fn Trappe::Trappe()
     * @brief Constructeur par défaut de la classe Trappe
     */
    Trappe();

    /**
     * @fn Trappe::~Trappe()
     * @brief Destructeur par défaut de la classe Trappe
     */
    ~Trappe();
    
    /**
     * @fn void Trappe::Open_Door()
     * @brief Fonction pour ouvrir la trappe
     */
    void Open_Door();

    /**
     * @fn void Trappe::Close_Door()
     * @brief Fonction pour fermer la trappe
     */
    void Close_Door();

    /**
     * @fn void Trappe::Distribution()
     * @brief Fonction pour la distribution
     * Ouvre la trappe, attend pendant 200ms, puis la referme.
     * En augmentant le temps d'attente on fait des doses plus grandes 
     * et l'inverse pour un temps d'attente plus court
     */
    void Distribution();

};

#endif