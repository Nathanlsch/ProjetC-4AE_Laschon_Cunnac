#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H


#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "html.h"
#include <string>

class MyWebServer {
public:
    MyWebServer(int port) : server(port) {}

    void setup();
    void begin();
    void handleClient();
    void Init();
    void SetPtr1(std::function<void()> IT_function);
    void SetPtr2(std::function<void()> IT_function);

    void SetCroquette(long entier);
    String getHeureSelect();


private:
    String heureSelectionnee;
    String niveauCroquette;
    const char *SSID;
    const char *PASSWORD;
    ESP8266WebServer server;

    void handleRoot();
    void doseCroquette();
    void handleUpdateHeure();
    void GestionCouvercle();
    std::function<void()> ptr1;
    std::function<void()> ptr2;


};

#endif
