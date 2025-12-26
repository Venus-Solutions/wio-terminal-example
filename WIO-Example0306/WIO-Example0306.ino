#include"TFT_eSPI.h"        // ผนวกไลบรารีของชิปควบคุมจอแสดงผล LCD
TFT_eSPI tft;               // สร้างออบเจ็กต์ชื่อ tft จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() 
{
  tft.begin();              // เริ่มต้นการทำงานของจอแสดงผล LCD
  tft.setRotation(3);       // หมุนตำแหน่งการแสดงผลเป็นโหมด 3 
  tft.fillScreen(TFT_RED);  // กำหนดให้แสดงสีแดงเต็มหน้าจอแสดงผล
  tft.drawFastHLine(0,120,320,TFT_BLACK);   // วาดเส้นตรงจากจุดเริ่มต้น (0,120) ยาว 320 พิกเซล
}
void loop() 
{}
