void setup() {
  Serial.begin(115200);  //initial the Serial
}

void loop() {
    if (Serial.available())
  {

    byte cmd = Serial.read();

    if (cmd == 0x01) {
      Serial.println("A");
      //digitalWrite(2, HIGH);
    }
    else if (cmd == 0x00) {
      Serial.println("B");
      //digitalWrite(2, LOW);
    }
  }
}
