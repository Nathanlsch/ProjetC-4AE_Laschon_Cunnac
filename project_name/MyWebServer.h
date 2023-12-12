/*********************************************************************
 * @file  MyWebServer.h
 * @brief Fichier header de la classe MyWebServer
 *********************************************************************/
#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H


#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "html.h"
#include <string>

/**
 * @class MyWebServer
 * @brief Classe pour la gestion du serveur web sur ESP8266
 */
class MyWebServer {

  public:
    /**
     * @brief Constructeur de la classe MyWebServer
     * @param port Numéro de port pour le serveur web
     */
    MyWebServer(int port) : server(port) {}
    
    /**
     * @brief Fonction d'initialisation du serveur web
     * Configure le serveur web et initialise les paramètres.
     */
    void setup();

    /**
     * @brief Fonction pour démarrer le serveur web
     * Met en marche le serveur web.
     */
    void begin();

    /**
     * @brief Fonction pour gérer les clients web
     * Permet de gérer les requêtes des clients
     */
    void handleClient();

    /**
     * @brief Fonction pour l'initialisation
     * Initialise les variables et fonctions nécessaires.
     */
    void Init();

    /**
     * @brief Fonction pour définir le pointeur de fonction 1
     * @param IT_function Pointeur vers la première fonction à exécuter.
     */
    void SetPtr1(std::function<void()> IT_function);

    /**
     * @brief Fonction pour définir le pointeur de fonction 2
     * @param IT_function Pointeur vers la deuxième fonction à exécuter.
     */
    void SetPtr2(std::function<void()> IT_function);

    /**
     * @brief Fonction pour définir le niveau de croquettes
     * @param entier Niveau de croquettes en pourcentage.
     */
    void SetCroquette(long entier);
    
    /**
      * @fn String getHeureSelect()
      * @brief Fonction pour obtenir l'heure sélectionnée
      * @return Une chaîne de caractères représentant l'heure sélectionnée
      */
    String getHeureSelect();

  private:

    String heureSelectionnee;     // Variable pour stocker l'heure sélectionnée 
    String niveauCroquette;       // Variable pour stocker le niveau de croquettes 
    const char *SSID;             // SSID du réseau WiFi 
    const char *PASSWORD;         // Mot de passe du réseau WiFi 
    ESP8266WebServer server;      // Objet ESP8266WebServer pour la gestion du serveur web 

    /**
     * @brief Fonction pour gérer la page d'accueil
     * Affiche la page principale du serveur web.
     */
    void handleRoot();

    /**
     * @brief Fonction pour distribuer des croquettes
     * Exécute la distribution de croquettes en appelant la fonction associée.
     */
    void doseCroquette();

    /**
     * @brief Fonction pour mettre à jour l'heure
     * Exécute la mise à jour de l'heure en appelant la fonction associée.
     */
    void handleUpdateHeure();

    /**
     * @brief Fonction pour la gestion du couvercle
     * Exécute la gestion du couvercle en appelant la fonction associée.
     */
    void GestionCouvercle();

    std::function<void()> ptr1;     // Pointeur vers la première fonction */
    std::function<void()> ptr2;     // Pointeur vers la deuxième fonction */


};

#endif
