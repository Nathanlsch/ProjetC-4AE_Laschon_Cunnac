#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "html.h"

class MyWebServer {
public:
    MyWebServer(int port) : server(port) {}

    void setup();
    void begin();
    void handleClient();
    void Init();

private:
    String heureSelectionnee;
    String niveauCroquette;
    const char *SSID;
    const char *PASSWORD;
    ESP8266WebServer server;

    void handleRoot();
    void doseCroquette();
    void handleUpdateHeure();

};
