void __delay_sound(uint16_t ms){
  unsigned int i;
  for(i=0; i<ms; i++){
    delayMicroseconds(10);
  }
}

void sound(uint16_t freq, uint32_t time){
  uint32_t dt=0, m=0;
  uint32_t tempTime;
  pinMode(WIO_BUZZER, OUTPUT);
  digitalWrite(WIO_BUZZER, LOW);
  tempTime = time * 50;
  dt = 50000/freq;
  time = (tempTime)/dt;
  for(m-0; m<time; m++){
    digitalWrite(WIO_BUZZER, HIGH);
    __delay_sound(dt);
    digitalWrite(WIO_BUZZER, LOW);
    __delay_sound(dt);
  }
}

void setup() {
}

void loop() {
  sound(1200, 200);
  delay(2000);
}
