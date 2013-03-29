#include <SoftwareSerial.h>

SoftwareSerial mySerial(4, 5); // RX, TX

int rcvd = 0;

void setup() {                
  Serial.begin(9600);
  
  mySerial.begin(9600);
  mySerial.write(0x16); // screen on, no cursor, no blink
  mySerial.write(0x0C); // clear screen
  delay(5); // delay 5ms after clear, per spec
  mySerial.write(0x11); // backlight on
  mySerial.print("Waiting...                      ");
}

void loop() {
  if (Serial.available() > 0) {
    rcvd = Serial.read();
    mySerial.write(rcvd);
  }
}
