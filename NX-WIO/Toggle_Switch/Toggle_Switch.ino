void setup() 
{
  pinMode(BCM0, INPUT);
  pinMode(BCM1, OUTPUT);
}
void loop() 
{
  if(!digitalRead(BCM0))
  {
    digitalWrite(BCM1,!digitalRead(BCM1));  // Toggle LED
    delay(200);
  }
    
}
