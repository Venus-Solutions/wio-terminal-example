#include "rpcBLEDevice.h"
#include <BLE2902.h>
#include <TFT_eSPI.h>
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI();
BLEServer *pServer = NULL;
BLECharacteristic *pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t count = 0;
#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

class MyServerCallbacks: public BLEServerCallbacks{
  void onConnect(BLEServer *pServer){
    deviceConnected = true;
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("Status: connected ", 10, 5);
  }
  void onDisconnect(BLEServer *pServer){
    deviceConnected = false;
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("Status: disconnect ", 10, 5);
  }
};

class MyCallbacks: public BLECharacteristicCallbacks{
  void onWrite(BLECharacteristic *pCharacteristic){
    std::string rxValue = pCharacteristic->getValue();
    if(rxValue.length() > 0){
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      for(int i=0; i < 15; i++){
        tft.drawString(" ", 20 + i*15, 90);
      }
      for(int i=0; i < rxValue.length(); i++){
        tft.drawString((String)rxValue[i], 20 + i*15, 90);
      }
    }
  }
};

void setup() {
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  BLEDevice::init("UART Services");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pTxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_TX,
    BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_READ
  );
  pTxCharacteristic->setAccessPermissions(GATT_PERM_READ);
  pTxCharacteristic->addDescriptor(new BLE2902());
  BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_RX,
    BLECharacteristic::PROPERTY_WRITE
  );
  pRxCharacteristic->setAccessPermissions(GATT_PERM_READ | GATT_PERM_WRITE);
  pRxCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();
  pServer->getAdvertising()->start();
  tft.drawString("Status: disconnect", 10, 5);
  tft.drawString("Message: ", 20, 70);
}

void loop() {
  if(!deviceConnected && oldDeviceConnected){
    delay(500);
    pServer->startAdvertising();
    oldDeviceConnected = deviceConnected;
  }
  if(deviceConnected && !oldDeviceConnected){
    oldDeviceConnected = deviceConnected;
  }
  if(digitalRead(WIO_5S_PRESS) == LOW){
    count++;
    pTxCharacteristic->setValue(count);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString("Count: 0x" + String(count, HEX), 20, 130);
    delay(200);
  }
}
