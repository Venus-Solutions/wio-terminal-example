#include"TFT_eSPI.h"            // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                   // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();                  // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.setRotation(3);           // หมุนตำแหน่งการแสดงผลเป็นโหมด 3 
  tft.fillScreen(TFT_RED);      // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
  tft.setTextColor(TFT_BLACK);  // เลือกสีของตัวอักษรเป็นสีดำ
  tft.setTextSize(2);           // เลือกขนาดตัวอักษรเป็น 1
  tft.println("Hello world!");  // แสดงข้อความแล้วขึ้นบรรทัดใหม่
  tft.println("");              // แสดงข้อความว่างแล้วขึ้นบรรทัดใหม่ (เว้นบรรทัด)
  tft.println("WIO Terminal");  // แสดงข้อความแล้วขึ้นบรรทัดใหม่
}
void loop() 
{}
