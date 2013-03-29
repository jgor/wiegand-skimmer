/*
 * Copyright (c) 2013 jgor <jgor@indiecom.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
