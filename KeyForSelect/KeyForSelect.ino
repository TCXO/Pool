#include "Keyboard.h"

//Ad: https://qiita.com/MergeCells/items/17bdc1c1fb35949195b5

#define UpKey 2
#define UpLed 3
#define DownKey 4
#define DownLed 5
#define LeftKey 6
#define LeftLed 7
#define RightKey 8
#define RightLed 9
#define EnterKey 10
#define EnterLed 11
#define EscKey 12
#define CoinKey 13

void setup() {
  Keyboard.begin();
  pinMode(UpKey, INPUT_PULLUP);
  pinMode(UpLed, OUTPUT);
  pinMode(DownKey, INPUT_PULLUP);
  pinMode(DownLed, OUTPUT);
  pinMode(LeftKey, INPUT_PULLUP);
  pinMode(LeftLed, OUTPUT);
  pinMode(RightKey, INPUT_PULLUP);
  pinMode(RightLed, OUTPUT);
  pinMode(EnterKey, INPUT_PULLUP);
  pinMode(EnterLed, OUTPUT);
  pinMode(EscKey, INPUT_PULLUP);
  pinMode(CoinKey, INPUT_PULLUP);
}

void loop() {
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

