#include "TFT_eSPI.h"
TFT_eSPI tft;

void setup() {
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
}

void loop() {
  if(digitalRead(WIO_5S_UP) == LOW){
    tft.drawString("UP   ", 0, 10);
    delay(200);
  }
  else if(digitalRead(WIO_5S_DOWN) == LOW){
    tft.drawString("DOWN ", 0, 10);
    delay(200);
  }
  else if(digitalRead(WIO_5S_LEFT) == LOW){
    tft.drawString("LEFT ", 0, 10);
    delay(200);
  }
  else if(digitalRead(WIO_5S_RIGHT) == LOW){
    tft.drawString("RIGHT", 0, 10);
    delay(200);
  }
  else if(digitalRead(WIO_5S_PRESS) == LOW){
    tft.drawString("PRESS", 0, 10);
    delay(200);
  }
}
