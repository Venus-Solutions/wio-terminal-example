#include"TFT_eSPI.h"        // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;               // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();              // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.setRotation(3);
  tft.fillScreen(TFT_RED);  // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
  tft.drawLine(0,0,160,120,TFT_BLACK);  // วาดเส้นตรงจากจุดเริ่มต้น (0,0) ไปยังจุดปลายทาง (160,120)
}
void loop() 
{}
