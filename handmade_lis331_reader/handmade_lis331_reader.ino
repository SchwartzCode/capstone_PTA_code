#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  
  Wire.requestFrom(12, 6);    // request 6 bytes from slave device #0

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
 
  Serial.println("nothin");


  delay(500);
}
