#include <TFT_eSPI.h>
TFT_eSPI tft;
void setup() 
{
  pinMode(WIO_LIGHT, INPUT);
  analogReadResolution(12);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN,TFT_BLACK);          
  tft.setTextSize(3);
}
void loop() 
{
   int light = analogRead(WIO_LIGHT);
   tft.drawString("Light: "+String(light)+String("   "), 80, 120);
   delay(200);
 }
