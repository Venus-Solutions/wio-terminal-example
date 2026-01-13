/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button

  Required libraries:
   - Seeed Arduino rpcUnified
   - Seeed Arduino rpcWiFi
   - Seeed Arduino SFUD
   - Seeed Arduino FS
   - Seeed Arduino mbedtls
   - Seeed Arduino FreeRTOS
   - ArduinoOTA
   - ArduinoHttpClient

  NOTE: Please also update the WiFi module firmware:
   https://wiki.seeedstudio.com/Wio-Terminal-Network-Overview
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
#define BLYNK_TEMPLATE_ID "TMPL6YmPDhkRs"
#define BLYNK_TEMPLATE_NAME "Light"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#include <TFT_eSPI.h>
TFT_eSPI tft;
BlynkTimer timer;

void sendLight(){
  int light = analogRead(WIO_LIGHT);
  String str = "Light: " + String(light);
  tft.drawString(str + String(" "), 80, 120);
  Blynk.virtualWrite(V0, light);
}

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(WIO_LIGHT, INPUT);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("Wait...", 80, 120);
  BlynkEdgent.begin();
  timer.setInterval(1000L, sendLight);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
