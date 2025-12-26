#include"TFT_eSPI.h"        // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;               // สร้างออปเจ็กต์ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();              // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.fillScreen(TFT_RED);  // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
}
void loop()
{}
