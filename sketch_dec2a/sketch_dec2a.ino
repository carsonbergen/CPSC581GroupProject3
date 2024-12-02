void setup() 
{
  uint32_t baud = 9600;
  Serial.begin(baud);
  // softSerial.begin(baud);
  Serial.print("SETUP!! @");
  Serial.println(baud);
}
 
void loop() 
{
    while(Serial.available() > 0) 
    {
      char a = Serial.read();
      if(a == "")
        continue;
      if(a != "r" && a != "n" && (a < 32))
        continue;
      Serial.print(a);
    }
    
    while(Serial.available() > 0)
    {
      char a = Serial.read();
      Serial.write(a);
      Serial.write(a);
    }
}