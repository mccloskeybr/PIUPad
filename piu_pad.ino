#include <Keyboard.h>

char upLeftChar = 'q';
char upRightChar = 'e';
char downLeftChar = 'z';
char downRightChar = 'c';
char centerChar = 's';

int upLeftPin = 13;
int upRightPin = 12;
int downLeftPin = 11;
int downRightPin = 10;
int centerPin = 9;

int upLeftStatus = LOW;
int upRightStatus = LOW;
int downLeftStatus = LOW;
int downRightStatus = LOW;
int centerStatus = LOW;

// enable pins for reading and start keyboard
void setup() {
  pinMode(upLeftPin, INPUT_PULLUP);
  pinMode(upRightPin, INPUT_PULLUP);
  pinMode(downLeftPin, INPUT_PULLUP);
  pinMode(downRightPin, INPUT_PULLUP);
  pinMode(centerPin, INPUT_PULLUP);

  Keyboard.begin();
}

// press keys if pin is HIGH
void loop() {
  int temp;

  // up left
  temp = digitalRead(upLeftPin);
  if (temp != upLeftStatus) {
    upLeftStatus = temp;
    if (upLeftStatus == HIGH)
      Keyboard.press(upLeftChar);
    else
      Keyboard.release(upLeftChar);
  }

  // up right
  temp = digitalRead(upRightPin);
  if (temp != upRightStatus) {
    upRightStatus = temp;
    if (upRightStatus == HIGH)
      Keyboard.press(upRightChar);
    else
      Keyboard.release(upRightChar);
  }

  // down left
  temp = digitalRead(downLeftPin);
  if (temp != downLeftStatus) {
    downLeftStatus = temp;
    if (downLeftStatus == HIGH)
      Keyboard.press(downLeftChar);
    else
      Keyboard.release(downLeftChar);
  }

  // down right
  temp = digitalRead(downRightPin);
  if (temp != downRightStatus) {
    downRightStatus = temp;
    if (downRightStatus == HIGH)
      Keyboard.press(downRightChar);
    else
      Keyboard.release(downRightChar);
  }

  // center
  temp = digitalRead(centerPin);
  if (temp != centerStatus) {
    centerStatus = temp;
    if (centerStatus == HIGH)
      Keyboard.press(centerChar);
    else
      Keyboard.release(centerChar);
  }
}
