/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application() : server(80)
{
   
}

Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
    // Allume les LED
    affichage.Allumer();

    // Initialisation du serveur et de l'horloge
    server.setup();
    time.setup();

    // Définition de la fonction de distribution pour le serveur
    auto distributionFunction = [this]() {
        this->trappe.Distribution();
    };
    server.SetPtr1(distributionFunction);

    // Définition de la fonction de gestion du couvercle pour le serveur
    auto couvercleFunction = [this]() {
        this->couvercle.gestionCouvercle();
    };
    server.SetPtr2(couvercleFunction);    
}


void Application::run(void)
{
    // Gestion des clients par le serveur
    server.handleClient();

    //Mise à jour de l'heure
    time.MajHeure();

    // Mise à jour du niveau du réservoir
    reservoir.MAJ();

    // Obtient l'heure actuelle
    time.getHeure();

    // Transmission du pourcentage au serveur
    server.SetCroquette(reservoir.Pourcentage());

    // Gère l'affichage en fonction du pourcentage de croquettes restantes
    affichage.Gestion(reservoir.Pourcentage());

    // Si l'heure sélectionnée sur le serveur web correspond à l'heure actuelle, distribue des croquettes
    if(server.getHeureSelect()==time.getHeure()){
      trappe.Distribution();
    }

    // Délai pour éviter une utilisation intensive du processeur
    delay(500);

}
