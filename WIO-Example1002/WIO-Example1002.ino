#include "rpcWiFi.h"

const char* ssid = "TEEEDU";
const char* password = "Venus@2018";

void setup() {
  Serial.begin(115200);
  while(!Serial);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to WiFi..");
    WiFi.begin(ssid, password);
  }
  Serial.println("Connected to the WiFi network");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
