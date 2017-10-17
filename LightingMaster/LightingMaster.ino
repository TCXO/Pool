#include <Wire.h>

byte b=0;
char c;

void setup() {
  Wire.begin(8);// Slave ID #8
  Wire.onRequest(requestEvent);
}

void loop() {
  
}

void requestEvent() {
  
     if (Serial.available() > 0) {  // データをIDEから受信したら処理開始
          c = Serial.read() ;       // データを１バイト読込む
          Serial.write(c) ;         // そのままデータを送り返す
Wire.write(c);
     }
//  Wire.write(b++);
}
