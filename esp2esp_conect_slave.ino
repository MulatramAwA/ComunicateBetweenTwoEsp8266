#include <ESP8266WiFi.h>                        
const char* ssid     = "control-master";//Master's AP WiFi          
const char* host = "192.168.4.1";//Master's IP
const uint16_t port = 23;//Master's port      
void setup() {
    Serial.begin(9600);                         
    WiFi.mode(WIFI_STA);                          
    WiFi.begin(ssid);                                
    int i;                                    
    while (WiFi.status() != WL_CONNECTED){                                             
      delay(1000);
      Serial.print("waiting for ");                          
      Serial.print(i++); Serial.println("s...");       
    }                              
    Serial.println("WiFi connected!");
}
void loop() {
    WiFiClient tcpclient;//Define tcp client
    if (!tcpclient.connect(host, port)) {//Try to connect
      Serial.println("connection failed");
      delay(5000);
      return;
    }
    //Add your code beyond this.
}
