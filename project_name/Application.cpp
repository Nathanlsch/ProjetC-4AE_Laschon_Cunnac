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
    affichage.Allumer();
    server.setup();
    time.setup(); 

    auto distributionFunction = [this]() {
        this->trappe.Distribution();
    };
    server.SetPtr1(distributionFunction);

    auto couvercleFunction = [this]() {
        this->couvercle.gestionCouvercle();
    };
    server.SetPtr2(couvercleFunction);    
}


void Application::run(void)
{
    server.handleClient();
    time.MajHeure();
    reservoir.MAJ();
    time.getHeure();
    server.SetCroquette(reservoir.Pourcentage());
    affichage.Gestion(reservoir.Pourcentage());

    if(server.getHeureSelect()==time.getHeure()){
      trappe.Distribution();
    }

    delay(500);

}
