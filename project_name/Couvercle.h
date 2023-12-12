/*********************************************************************
 * @file  Couvercle.h
 * @brief Fichier header de la classe Couvercle
 *********************************************************************/
#ifndef COUVERCLE_H
#define COUVERCLE_H
#include "Porte.h"
#include <Servo.h>
#include "conf.h"

/**
 * @class Couvercle
 * @brief Classe héritant de la classe Porte pour représenter un couvercle
 */
class Couvercle : public Porte{

  private:

  int etat;         //Etat du couvercle : 0 = Fermé, 1 = Ouvert
  Servo ServoCouv;  //Instance Servo pour le Couvercle

  public:

  /**
     * @fn Couvercle::Couvercle()
     * @brief Constructeur par défaut de la classe Couvercle
     */
  Couvercle();

  /**
   * @fn void Open_Door()
   * @brief Fonction pour ouvrir le couvercle
   * Utilise la fonction write() de l'objet Servo pour définir l'angle d'ouverture du couvercle.
   */
  void Open_Door();

  /**
   * @fn void Close_Door()
   * @brief Fonction pour fermer le couvercle
   * Utilise la fonction write() de l'objet Servo pour définir l'angle de fermeture du couvercle.
   */
  void Close_Door();

  /**
   * @fn void gestionCouvercle()
   * @brief Fonction pour gérer l'état du couvercle
   * 
   */
  void gestionCouvercle();

};

#endif