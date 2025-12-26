#include"TFT_eSPI.h"            // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                   // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();                  // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.setRotation(3);           // หมุนตำแหน่งการแสดงผลเป็นโหมด 3 
  tft.fillScreen(TFT_RED);      // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
  tft.setTextColor(TFT_BLACK);  // เลือกสีของตัวอักษรเป็นสีดำ
  tft.setTextSize(1);           // เลือกขนาดตัวอักษรเป็น 1
  tft.drawString("Hello world!", 0, 0);   // แสดงข้อความที่พิกัด (0, 0)
  tft.setTextSize(2);                     // เลือกขนาดตัวอักษรเป็น 2
  tft.drawString("Hello world!", 0, 10);  // แสดงข้อความที่พิกัด(0, 10)
}
void loop() 
{}
