#include "Keyboard.h"
#include <Wire.h>

//Ad: https://qiita.com/MergeCells/items/17bdc1c1fb35949195b5


#define UpKey 8
#define DownKey 9
#define LeftKey 10
#define RightKey 11
#define EnterKey 12
#define EscKey 13
#define CoinKey 7


void setup() {
  Keyboard.begin();
  Wire.begin();
  Serial.begin(9600);
  
  pinMode(UpKey, INPUT_PULLUP);
  pinMode(DownKey, INPUT_PULLUP);
  pinMode(LeftKey, INPUT_PULLUP);
  pinMode(RightKey, INPUT_PULLUP);
  pinMode(EnterKey, INPUT_PULLUP);
  pinMode(EscKey, INPUT_PULLUP);
  pinMode(CoinKey, INPUT_PULLUP);
}


void loop() {
    //  KeyFunction
    if(digitalRead(UpKey) == LOW) KeyFunction(UpKey, KEY_UP_ARROW);
    if(digitalRead(DownKey) == LOW) KeyFunction(DownKey, KEY_DOWN_ARROW);
    if(digitalRead(LeftKey) == LOW) KeyFunction(LeftKey, KEY_LEFT_ARROW);
    if(digitalRead(RightKey) == LOW) KeyFunction(RightKey, KEY_RIGHT_ARROW);
    if(digitalRead(EnterKey) == LOW) KeyFunction(EnterKey, KEY_RETURN);
    if(digitalRead(EscKey) == LOW) KeyFunction(EscKey, KEY_ESC);
    if(digitalRead(CoinKey) == LOW) KeyFunction(CoinKey, KEY_INSERT); 
    delay(100);
}


void KeyFunction(char Key, char KeyType){
    Keyboard.press(KeyType);
    delay(100);
    Keyboard.releaseAll();
    while(digitalRead(Key) == LOW);
}
