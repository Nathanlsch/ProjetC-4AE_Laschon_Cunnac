/*********************************************************************
 * @file  MyWebServer.cpp
 * @brief Fichier source de la classe MyWebServer
 *********************************************************************/
#include "MyWebServer.h"

void MyWebServer::setup() {
  
  // Initialisation des paramètres et connexion WiFi
  this->Init();
  Serial.begin(115200);

        // Connexion au réseau WiFi
        WiFi.begin(SSID, PASSWORD);
        while (WiFi.status() != WL_CONNECTED) {
          delay(1000);
          Serial.println("Connecting to WiFi...");
         }
        Serial.println("Connected to WiFi");

        // Initialisation du serveur web
        this->begin();
}

void MyWebServer::begin() {
  // Définition des gestionnaires de route pour le serveur web
  server.on("/", HTTP_GET, std::bind(&MyWebServer::handleRoot, this));
  server.on("/index.html", HTTP_GET, std::bind(&MyWebServer::handleRoot, this));
  server.on("/doseCroquette", HTTP_GET, std::bind(&MyWebServer::doseCroquette, this));
  server.on("/updateHeure", HTTP_GET, std::bind(&MyWebServer::handleUpdateHeure, this));
  server.on("/actionCouvercle", HTTP_GET, std::bind(&MyWebServer::GestionCouvercle, this));
  
  // Démarrage du serveur web
  server.begin();
}

void MyWebServer::handleClient() {
  // Gestion des clients web
  server.handleClient();
}

void MyWebServer::GestionCouvercle(){
  // Gestion du couvercle en appelant la fonction associée
  Serial.println("test 2 !");
  ptr2();
  server.send(200, "text/plain", "OK");
}

void MyWebServer::handleRoot() {
  // Affichage de la page principale du serveur web
      if (server.uri() == "/") {
          String temp(reinterpret_cast<const __FlashStringHelper*>(index_html));
          // Include the value of the selected time in the HTML page
          temp.replace("%HEURE_SELECTIONNEE%", heureSelectionnee);
          temp.replace("%NIVEAU_CROQUETTE%", niveauCroquette);
          server.send(200, "text/html", temp);
      }
    }

void MyWebServer::doseCroquette() {
      Serial.println("test !");
      ptr1();
      Serial.print("Nouveau niveau de croquette : ");
      Serial.println(niveauCroquette);
      server.send(200, "text/plain", niveauCroquette);
}

void MyWebServer::handleUpdateHeure() {
  // Mise à jour de l'heure en fonction de la requête
        if (server.hasArg("heure")) {
          heureSelectionnee = server.arg("heure");
          Serial.print("Nouvelle heure : ");
          Serial.println(heureSelectionnee);
          server.send(200, "text/plain", "OK");
        } else {
          server.send(400, "text/plain", "Erreur de requête");
        }
    }

void MyWebServer::Init(){
  // Initialisation des variables et des pointeurs de fonction
  heureSelectionnee = "";
  niveauCroquette = "50%";
  SSID = "iPhone de Nathan";
  PASSWORD = "123456789";
  ptr1 = NULL;
  ptr2 = NULL;
}

void MyWebServer::SetPtr1(std::function<void()> IT_function) {
   // Définition du pointeur de fonction 1
    this->ptr1 = IT_function;
}

void MyWebServer::SetPtr2(std::function<void()> IT_function) {
  // Définition du pointeur de fonction 2
    this->ptr2 = IT_function;
}

void MyWebServer::SetCroquette(long entier){
  // Mise à jour du niveau de croquettes
  niveauCroquette = String(entier);
}

String MyWebServer::getHeureSelect() {
  // Récupération de l'heure sélectionnée en string
  return heureSelectionnee+":0";
}

