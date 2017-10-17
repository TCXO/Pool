#include <Wire.h>

char b=0;

void setup() {
  Wire.begin(8);// Slave ID #8
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
}

void loop() {
 if (Serial.available() > 0) {
  b = Serial.read();
 }
}

void requestEvent() {
//  Wire.write(b++);
//  b = Serial.read();
  if (b != '\0') Wire.write(b);
  Serial.println(b);
}
