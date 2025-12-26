#include"TFT_eSPI.h"            // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                   // สร้างออปเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();                  // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.fillScreen(TFT_RED);      // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
  tft.drawPixel(4,7,TFT_BLACK); // วาดจุดสีดำที่พิกัด (4,7) 
}
void loop() 
{}
