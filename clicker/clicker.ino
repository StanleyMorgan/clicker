#include "Touch.h"
#define fingers 9 

unsigned long previousMillis = 0;
unsigned long interval;

void setup() {
  randomSeed(analogRead(0));
  Touch.begin();
}

void loop() {
  
  uint16_t xStart = 100;              // Spot size
  uint16_t xDelta = 240;              // 240 PC, 500 Android
  uint16_t xStop = xStart + xDelta;
  uint16_t yStart = 5000;
  uint16_t yDelta = 240;
  uint16_t yStop = yStart + yDelta;
  uint16_t xStep = 250;
  uint16_t yStep = 500;
  
  unsigned long currentMillis = millis();

  interval = 40 + 3*analogRead(A3);
  
  if (currentMillis - previousMillis >= interval) {
    for (uint8_t i=1; i < fingers; i++){
      Touch.moveFingerTo(i, xStep*i + random(xStart, xStop), yStep*(i%2) + random(yStart, yStop));    
      Touch.releaseFinger(i);
      delay(5);     
    }
     
    previousMillis = currentMillis;  
  }
}
