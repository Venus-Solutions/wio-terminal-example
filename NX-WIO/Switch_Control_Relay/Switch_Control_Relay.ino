void setup() 
{
  pinMode(BCM1, INPUT);
  pinMode(BCM2, INPUT);
  pinMode(BCM3, INPUT);
  pinMode(BCM4, INPUT);

  pinMode(BCM5, OUTPUT);
  pinMode(BCM6, OUTPUT);
  pinMode(BCM7, OUTPUT);
  pinMode(BCM8, OUTPUT);
}
void loop() 
{
  if(!digitalRead(BCM1))
  {
    digitalWrite(BCM5,!digitalRead(BCM5));  // Toggle LED1
    delay(200);
  }
  if(!digitalRead(BCM2))
  {
    digitalWrite(BCM6,!digitalRead(BCM6));  // Toggle LED2
    delay(200);
  }
  if(!digitalRead(BCM3))
  {
    digitalWrite(BCM7,!digitalRead(BCM7));  // Toggle LED3
    delay(200);
  }
  if(!digitalRead(BCM4))
  {
    digitalWrite(BCM8,!digitalRead(BCM8));  // Toggle LED4
    delay(200);
  }
  
}
