/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application() : server(80)
{
  
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
    server.setup();
    time.setup();    ;
}


void Application::run(void)
{
    server.handleClient();
    time.MajHeure();
    reservoir.MAJ();
    reservoir.Affichage()
    ;
}
