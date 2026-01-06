#include "TFT_eSPI.h"
#include "LIS3DHTR.h"
TFT_eSPI tft;
LIS3DHTR<TwoWire> lis;
#define THRESHOLD 60
int cnt = 0;

void count(){
  cnt++;
  tft.drawString("Tap: " + String(cnt), 120, 120);
}

void setup(){
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  lis.begin(Wire1);
  if(!lis){
    tft.drawString("ERROR", 80, 120);
    while(1);
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ);
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G);
  lis.click(1, THRESHOLD);
  attachInterrupt(digitalPinToInterrupt(GYROSCOPE_INT1), count, RISING);
  tft.drawString("Tap: " + String(cnt), 120, 120);
}

void loop(){
  
}
