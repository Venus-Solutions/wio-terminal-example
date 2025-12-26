#include <TFT_eSPI.h>
TFT_eSPI tft;
void setup() 
{
  tft.begin();                          // Initial LCD
  tft.drawString("Hello world!", 0, 0); // Show message Hello world! at location [0,0] of LCD screen 
}
void loop()
{}
