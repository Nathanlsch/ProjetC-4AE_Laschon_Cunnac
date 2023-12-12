/*********************************************************************
 * @file  Porte.h
 * @brief Fichier header de la classe Porte 
 classe mère des classes Trappe et Couvercle
 *********************************************************************/
#ifndef PORTE_H
#define PORTE_H
#include <Servo.h>
#include "conf.h"

/**
 * @class Porte
 * @brief Classe représentant tout type de porte commandée par un servo
 */
class Porte{

  private:
  
  public:

  /**
     * @fn Porte()
     * @brief Constructeur de la classe Porte
     */
  Porte();

  /**
     * @fn ~Porte()
     * @brief Destructeur de la classe Porte
     */
  ~Porte();

  /**
     * @fn virtual void Open_Door()
     * @brief Fonction pour ouvrir la porte qui peut être redéfinie pour chaque type de porte
     */
  virtual void Open_Door();

  /**
     * @fn virtual void Close_Door()
     * @brief Fonction pour fermer la porte
     */
  virtual void Close_Door();


};
#endif