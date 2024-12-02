#include "SevSeg.h"
SevSeg sevseg;

int countdown = 60;            
unsigned long previousMillis = 0;
const unsigned long interval = 1000; 


const int buttonPin = A0;     
bool timerStarted = false;      
bool buttonPreviouslyPressed = false; 
int previousCountdown = -1; 

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = 0; 
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {

if (!timerStarted) {
    if (analogRead(buttonPin) > 300) {
      timerStarted = true;
    }
  } else {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (countdown > 0) {
        countdown--; 
      } else {
        countdown = 60; 
        timerStarted = false;

      }
    }
  }

  sevseg.setNumber(countdown, 0); 
  sevseg.refreshDisplay();      
}
