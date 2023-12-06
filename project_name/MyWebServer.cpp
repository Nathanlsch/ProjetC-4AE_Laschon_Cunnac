#include "MyWebServer.h"

void MyWebServer::setup() {
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
  server.on("/", HTTP_GET, std::bind(&MyWebServer::handleRoot, this));
  server.on("/index.html", HTTP_GET, std::bind(&MyWebServer::handleRoot, this));
  server.on("/doseCroquette", HTTP_GET, std::bind(&MyWebServer::doseCroquette, this));
  server.on("/updateHeure", HTTP_GET, std::bind(&MyWebServer::handleUpdateHeure, this));
  server.begin();
}

void MyWebServer::handleClient() {
  server.handleClient();
}

void MyWebServer::handleRoot() {
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
      niveauCroquette = "40%";
      Serial.print("Nouveau niveau de croquette : ");
      Serial.println(niveauCroquette);
      server.send(200, "text/plain", niveauCroquette);
}

void MyWebServer::handleUpdateHeure() {
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
  heureSelectionnee = "";
  niveauCroquette = "50%";
  SSID = "iPhone de Nathan";
  PASSWORD = "123456789";
}


