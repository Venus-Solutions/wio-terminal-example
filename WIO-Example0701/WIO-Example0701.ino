#include "TFT_eSPI.h"
#include "LIS3DHTR.h"
TFT_eSPI tft;
LIS3DHTR<TwoWire> lis;

void setup(){
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_WHITE);
  tft.setTextSize(2);
  lis.begin(Wire1);
  if(!lis){
    tft.drawString("ERROR", 80, 120);
    while(1);
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ);
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G);
}

void loop(){
  float ax, ay, az;
  ax = lis.getAccelerationX();
  ay = lis.getAccelerationY();
  az = lis.getAccelerationZ();
  tft.drawString("Ax: " + String(ax) + String(" "), 100, 80);
  tft.drawString("Ay: " + String(ay) + String(" "), 100, 100);
  tft.drawString("Az: " + String(az) + String(" "), 100, 120);
  delay(500);
  tft.fillScreen(TFT_BLACK);
}
