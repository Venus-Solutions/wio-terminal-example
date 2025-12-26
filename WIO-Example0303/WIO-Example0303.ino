#include"TFT_eSPI.h"                  // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;                         // สร้างออปเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
#define LCD_BACKLIGHT (72Ul)          // นิยามขาควบคุมไฟส่องหลังของจอแสดงผล LCD ของ WIO Terminal
void setup() 
{
  tft.begin();                        // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.fillScreen(TFT_RED);            // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
}
void loop() 
{
  digitalWrite(LCD_BACKLIGHT, HIGH);  // เปิดไฟส่องหลัง
  delay(1000);                        // หน่วงเวลา 1 วินาที
  digitalWrite(LCD_BACKLIGHT, LOW);   // ปิดไฟส่องหลัง
  delay(1000);                        // หน่วงเวลา 1 วินาที
}
