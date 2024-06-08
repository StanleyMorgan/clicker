#include "Touch.h"
#define fingers 1

uint16_t xStart = 4200;              // Spot size
uint16_t xStop = 5200;
uint16_t yStart = 7500;
uint16_t yStop = 8000;

void setup() {
  randomSeed(analogRead(0));
  Touch.begin();
}

void loop() {

  int startTime;
  int stopTime;

  int mode = analogRead(A3)/210;        // 4 Modes: 0-210, 210-420, 420-630, 630-840, 840-1023

  switch (mode) {
    case 1:
      startTime = 3100;
      stopTime = 3300;   
      Touch.moveFingerTo(1, random(xStart, xStop), random(yStart, yStop));  
      delay(random(20, 50));
      Touch.releaseFinger(1);              
      break;
    case 2:
      startTime = 2100;
      stopTime = 2300;   
      Touch.moveFingerTo(1, random(xStart, xStop), random(yStart, yStop));  
      delay(random(20, 50));
      Touch.releaseFinger(1);      
      break;
    case 3:
      startTime = 1100;
      stopTime = 1300;   
      Touch.moveFingerTo(1, random(xStart, xStop), random(yStart, yStop));  
      delay(random(20, 50));
      Touch.releaseFinger(1);        
      break;
    case 4:
      startTime = 100;
      stopTime = 200;   
      Touch.moveFingerTo(1, random(xStart, xStop), random(yStart, yStop));  
      delay(random(20, 50));
      Touch.releaseFinger(1);           
      break;
    default:
      delay(random(100, 200));
  }

  delay(random(startTime, stopTime));
}  
