#include"TFT_eSPI.h"            // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                   // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();                  // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.fillScreen(TFT_BLACK);    // กำหนดให้แสดงสีดำเต็มหน้าจอแสดงผล
  tft.setTextColor(TFT_WHITE);  // เลือกสีของตัวอักษรเป็นสีขาว
  tft.setTextSize(4);           // เลือกขนาดตัวอักษรเป็น 4
}
void loop() 
{
  tft.fillScreen(TFT_BLACK);          // กำหนดให้แสดงสีดำเต็มหน้าจอแสดงผล
  tft.setRotation(0);                 // หมุนตำแหน่งการแสดงผลเป็นโหมด 0
  tft.drawString("WIO-INEX", 0, 0);   // แสดงข้อความที่พิกัด (0, 0)
  delay (1000);
  tft.fillScreen(TFT_BLACK);          // กำหนดให้แสดงสีดำเต็มหน้าจอแสดงผล
  tft.setRotation(1);                 // หมุนตำแหน่งการแสดงผลเป็นโหมด 1
  tft.drawString("WIO-INEX", 0, 0);   // แสดงข้อความที่พิกัด (0, 0)
  delay (1000);
  tft.fillScreen(TFT_BLACK);          // กำหนดให้แสดงสีดำเต็มหน้าจอแสดงผล
  tft.setRotation(2);                 // หมุนตำแหน่งการแสดงผลเป็นโหมด 2
  tft.drawString("WIO-INEX", 0, 0);   // แสดงข้อความที่พิกัด (0, 0)
  delay (1000);
  tft.fillScreen(TFT_BLACK);          // กำหนดให้แสดงสีดำเต็มหน้าจอแสดงผล
  tft.setRotation(3);                 // หมุนตำแหน่งการแสดงผลเป็นโหมด 3
  tft.drawString("WIO-INEX", 0, 0);   // แสดงข้อความที่พิกัด (0, 0)
  delay (1000);
}
