#include "TFT_eSPI.h"
TFT_eSPI tft;

void setup(){
  pinMode(WIO_MIC, INPUT);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
}

void loop(){
  int adc = analogRead(WIO_MIC);
  tft.drawString("Tap: " + String(adc) + String(" "), 120, 120);
  delay(200);
}
