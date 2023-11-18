#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WiFiServer.h>
static const char *ssid = "control-master";    // SSID
WiFiClient _Client;//Connected TCP client.
WiFiServer server(23); //Define TCP server on port 23
void setup() {
    Serial.begin(9600);
    bool ok=WiFi.softAP(ssid);//Try to open AP WiFi.
    if (!ok){
        Serial.println("Create AP WiFi failed.");
        ok=WiFi.softAP(ssid);//Try to open AP WiFi again.
        if (!ok){
            Serial.println("Create AP WiFi failed.");
            ok=WiFi.softAP(ssid);//Try to open AP WiFi third.
            if(!ok){
              Serial.println("Create AP WiFi failed.");
              Serial.println("Restarting...");
              ESP.reset();
            }
        } 
    }
    Serial.println("IP:192.168.4.1");
    server.begin();
    server.setNoDelay(true);
}
void loop() {
    if(server.hasClient()){
        _Client=server.available(); //Get the client
        Serial.println("[Client connected]");
    }
    //Add your code beyond this.    
}
