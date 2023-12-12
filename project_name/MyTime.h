/*********************************************************************
 * @file  MyTime.h
 * @brief Fichier header de la classe MyTime
 *********************************************************************/
#ifndef MYTIME_H
#define MYTIME_H

#include <WiFiUdp.h>
#include "NTPClient.h"

/**
 * @class MyTime
 * @brief Classe MyTime pour la gestion du temps via NTP
 */
class MyTime {

  private :

    int Heure[3];                         /**< Tableau pour stocker l'heure */
    const long gmtOffset_sec = 3600;      // GMT+1 (par exemple, Paris)
    const int daylightOffset_sec = 3600;  // Décalage d'été (1 heure en secondes)
    WiFiUDP ntpUDP;                       /**< Objet UDP pour la connexion au serveur NTP */
    NTPClient timeClient;                 /**< Client NTP pour la gestion du temps */

  public :
    /**
     * @brief Constructeur de la classe MyTime
     * Initialise les membres de la classe.
     */
    MyTime();

    /**
     * @brief Destructeur de la classe MyTime
     * (S'il y a des ressources à libérer, les libérer ici.)
     */
    ~MyTime();

    /**
     * @fn void setup()
     * @brief Fonction d'initialisation de la classe MyTime
     * Configure le client NTP et initialise la connexion au serveur NTP.
     */
    void setup();

    /**
     * @fn void MajHeure()
     * @brief Fonction pour mettre à jour l'heure
     * Met à jour les informations d'heure en interrogeant le serveur NTP.
     */
    void MajHeure();

    /**
     * @fn String getHeure()
     * @brief Fonction pour obtenir l'heure actuelle au format String
     * @return Une chaîne de caractères représentant l'heure actuelle.
     */
    String getHeure();
};
#endif