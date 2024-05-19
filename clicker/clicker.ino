#include "Touch.h"

#define fingers 3 

unsigned long previousMillis = 0;     // will store last time LED was updated
unsigned long interval;               // interval at which to blink (milliseconds)

void setup() {
  
  randomSeed(analogRead(0));
  Touch.begin();
}

void loop() {
  uint16_t xStart = 500;
  uint16_t xDelta = 2200;  
  uint16_t xStop = xStart + xDelta;

  uint16_t yStart = 5000;
  uint16_t yStop = 5500;
  
  unsigned long currentMillis = millis();
//  interval = 50000 / 10 + analogRead(A3);
  interval = 5*(10 + analogRead(A3));  
  
  if (currentMillis - previousMillis >= interval) {
    for (uint8_t i=0; i <= fingers; i++){
      Touch.moveFingerTo(i+1, xDelta*i + random(xStart, xStop), random(yStart, yStop));    
      Touch.releaseFinger(i+1);
      delay(10);     
    }
     
    previousMillis = currentMillis;  
  }
}
