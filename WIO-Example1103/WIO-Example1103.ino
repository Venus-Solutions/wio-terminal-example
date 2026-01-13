/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID     "YOUR BLYNK TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME   "YOUR BLYNK TEMPLATE NAME"
#define BLYNK_AUTH_TOKEN      "YOUR BLYNK AUTH TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <TFT_eSPI.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR SSID";
char pass[] = "YOUR PASSWORD";

TFT_eSPI tft;
BlynkTimer timer_Sensor;
BlynkTimer timer_Button;
int statusLed = 0;

// This function is called every time the Virtual Pin 1 state changes
BLYNK_WRITE(V1)
{
  // Set incoming value from pin V1 to a variable
  int st = param.asInt();
  Serial.print("Got a value: ");
  Serial.println(st);
  if(st == 0){
    statusLed = 0;
  }
  else{
    statusLed = 1;
  }

  // Update state
  // Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
//BLYNK_CONNECTED()
//{
//  // Change Web Link Button message to "Congratulations!"
//  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
//  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
//  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
//}

void scanButton(){
  if(digitalRead(WIO_5S_PRESS) == LOW){
    statusLed =! statusLed;
  }
  if(statusLed == 1){
    tft.fillCircle(160, 140, 30, TFT_GREEN);
  }
  else{
    tft.fillCircle(160, 140, 30, TFT_DARKGREY);
  }
}

void sendLight(){
  int light = analogRead(WIO_LIGHT);
  String str = "Light: " + String(light);
  tft.drawString(str + String(" "), 80, 60);
  Blynk.virtualWrite(V0, light);
  Blynk.virtualWrite(V1, statusLed);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(100);
  pinMode(WIO_LIGHT, INPUT);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("Wait...", 80, 120);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer_Sensor.setInterval(1000L, sendLight);
  timer_Button.setInterval(500L, scanButton);
  tft.fillScreen(TFT_BLACK);

  //OTA
}

void loop()
{
  Blynk.run();
  timer_Sensor.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

  timer_Button.run();
}
