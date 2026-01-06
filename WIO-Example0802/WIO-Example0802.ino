#include "TFT_eSPI.h"
#include "RTC_SAMD51.h"
#include "DateTime.h"
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;

void alarmMatch(uint32_t flag){
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Alarm Match!", 100, 80);
  while(1);
}

void setup(){
  rtc.begin();
  tft.begin();
  tft.setRotation(3); 
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  now = DateTime(F(__DATE__), F(__TIME__));
  rtc.adjust(now);
  DateTime alarm = DateTime(now.year(),
    now.month(),
    now.day(),
    now.hour(),
    now.minute(),
    now.second() + 15);
  rtc.setAlarm(0, alarm);
  rtc.enableAlarm(0, rtc.MATCH_HHMMSS);
  rtc.attachInterrupt(alarmMatch);
}

void loop(){
  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  sprintf(s, "%02d/%02d/%02d", day, month, year);
  tft.drawString(s, 100, 80);
  sprintf(s, "%02d:%02d:%02d", hour, min, sec);
  tft.drawString(s, 100, 100);
  delay(1000);
}
