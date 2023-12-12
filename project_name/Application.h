/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "MyWebServer.h"
#include "MyTime.h"
#include "Reservoir.h"
#include <Arduino.h>
#include "Trappe.h"
#include "Couvercle.h"
#include "Affichage.h"

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();  
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);

  private :
    MyWebServer server;     // Instance de MyWebServer pour gérer le serveur web
    Reservoir reservoir;    // Instance de Reservoir pour gérer le réservoir
    MyTime time;            // Instance de MyTime pour gérer le temps
    Couvercle couvercle;    // Instance de Couvercle pour gérer le couvercle
    Trappe trappe;          // Instance de Trappe pour gérer la trappe
    Affichage affichage;    // Instance de Affichage pour gérer le cercle de LED
};
#endif