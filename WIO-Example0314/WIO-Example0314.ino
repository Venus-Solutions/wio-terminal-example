#include"TFT_eSPI.h"          // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                 // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();                // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.setRotation(3);         // หมุนตำแหน่งการแสดงผลเป็นโหมด 3
  tft.fillScreen(TFT_BLACK);  // กำหนดให้จอแสดงผลเป็นสีดำ
  tft.setTextSize(2);         // กำหนดขนาดตัวอักษรเป็น 2
  tft.drawChar(140,120,'A',TFT_BLACK, TFT_RED,2); // แสดงอักษร A ที่พิกัด (140,120)
  tft.drawChar(155,120,'B',TFT_BLACK, TFT_RED,2); // แสดงอักษร B ที่พิกัด (155,120)
  tft.drawChar(170,120,'C',TFT_BLACK, TFT_RED,2); // แสดงอักษร C ที่พิกัด (170,120)
}
void loop() 
{}
