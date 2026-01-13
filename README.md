### Arduino IDE
```
https://inex.co.th/store/software/Arduino1.8.16_Setup211210.exe
```
### Additional Boards Manager URLs
```
https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json
```
### Board Name
```
Seeed SAMD Boards by Seeed Studio
```
### Library Name
```
Grove-3-Axis-Digital-Accelerometer-2g-to-16g-LIS3DHTR by Seeed Studio
Seeed Arduino RTC by Seeed Studio
Seeed Arduino rpcWiFi by hongtai.liu for SeeedStudio
Seeed Arduino rpcBLE by Seeed Studio
BH1750 by Christopher Laws
DHT sensor library by Adafruit
Adafruit MLX90614
```
### Library URLs
```
https://github.com/Seeed-Studio/Seeed_Arduino_Histogram
https://github.com/DFRobot/DFRobot_MAX30102
```
### WIO Firmware Flashing
```
https://files.seeedstudio.com/wiki/Wio-Terminal/res/rtl8720_update_v2.uf2
https://github.com/Seeed-Studio/seeed-ambd-firmware/releases
https://github.com/Seeed-Studio/ambd_flash_tool
.\ambd_flash_tool.exe erase
.\ambd_flash_tool.exe flash -d <RTL8720-firmware-path>
```
## WIO Blynk Cloud
https://blynk.cloud/dashboard/login

New Template
<img width="1920" height="929" alt="2026-01-13_14-21-30" src="https://github.com/user-attachments/assets/ee8fa7c0-1e38-4c68-8ceb-f69c348cf4d0" />

ตั้งชื่อ Template เลือก Hardware เป็น Seeed Wio Terminal และเลือก Connection Type เป็น WiFi
<img width="965" height="555" alt="2026-01-13_14-23-39" src="https://github.com/user-attachments/assets/ca31242d-c0d6-4e08-a5eb-e8aa7d7edd24" />

คลิก Web Dashboard แล้วลาก Gauge และ Switch มาวางบน Dashboard
<img width="1920" height="929" alt="2026-01-13_14-31-53" src="https://github.com/user-attachments/assets/7ea83dbc-ea88-4a23-84d9-2c55ca9f07f0" />

คลิกที่รูปเฟืองของ Gauge
<img width="1920" height="929" alt="2026-01-13_14-45-55" src="https://github.com/user-attachments/assets/a5e6d83b-a0eb-4cce-aaf1-4f46a0867c7c" />

ตั้งชื่อ Gauge คลิก Create Datastream เลือก Virtual Pin ตั้งชื่อและเลือกสีของ Datastream เลือก PIN V0 ตั้งค่า MAX 1023 คลิก Create คลิก Save
<img width="1568" height="844" alt="2026-01-13_14-48-28" src="https://github.com/user-attachments/assets/6daa431f-2976-4d26-82e1-966d50c746bf" />

คลิกที่รูปเฟืองของ Switch
<img width="1920" height="929" alt="2026-01-13_14-49-29" src="https://github.com/user-attachments/assets/86a0d6a5-75ed-4781-ba07-516a67762315" />

ตั้งชื่อ Switch คลิก Create Datastream เลือก Virtual Pin
<img width="1568" height="844" alt="2026-01-13_14-55-11" src="https://github.com/user-attachments/assets/6541f3fb-3997-4882-b8c3-ee536886bb7c" />

ตั้งชื่อและเลือกสีของ Datastream เลือก PIN V1 ตั้งค่า MAX 1 คลิก Create
<img width="1569" height="844" alt="2026-01-13_14-56-17" src="https://github.com/user-attachments/assets/a30bca9c-d46d-4cca-a5ea-04fbe0365cd1" />

Enable Show on/off labels กำหนดข้อความ ON/OFF คลิก Save
<img width="1567" height="843" alt="2026-01-13_14-57-36" src="https://github.com/user-attachments/assets/307d28a7-320e-4fb8-8ed5-1619218ca4c2" />

Web Dashboard พร้อมใช้งาน
<img width="1920" height="929" alt="2026-01-13_15-01-13" src="https://github.com/user-attachments/assets/4e74888f-9bd3-4032-9280-70a62a846589" />

คลิก Datastreams คลิก Edit กำหนดสีให้ Datastream
<img width="1920" height="929" alt="2026-01-13_15-02-02" src="https://github.com/user-attachments/assets/b4baed3f-f1ff-4fba-a376-dcf1eb52c963" />

คลิก Add first Device
<img width="1920" height="929" alt="2026-01-13_15-02-43" src="https://github.com/user-attachments/assets/61c44316-9e73-42f4-8c88-2ca749b5baa3" />

ตั้งชื่อ Device คลิก Create<br>
<img width="575" height="319" alt="2026-01-13_15-04-21" src="https://github.com/user-attachments/assets/5b141bde-d72c-4d08-b020-69574eb04640" />

จะปรากฏ BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME และ BLYNK_AUTH_TOKEN คลิก Copy To Clipboard เพื่อนำไปใช้ใน Code ต่อ
<img width="1920" height="929" alt="2026-01-13_15-04-43" src="https://github.com/user-attachments/assets/e7551d78-8e6f-4593-b0f1-9a835043cf1f" />

BLYNK_TEMPLATE_ID และ BLYNK_TEMPLATE_NAME จะปรากฏอยู่ในหน้า Home ของ Template ที่เราสร้าง
<img width="1920" height="929" alt="2026-01-13_15-06-50" src="https://github.com/user-attachments/assets/7d6319fa-1a12-49d9-a4df-cc7ca2708741" />

BLYNK_AUTH_TOKEN จะปรากฏอยู่ในหน้า Device ของแต่ละอุปกรณ์
<img width="1920" height="929" alt="2026-01-13_15-08-06" src="https://github.com/user-attachments/assets/85399b05-9c53-4879-ad26-6a9b62995994" />
