#include "Touch.h"
#define fingers 1

//#define Beetle
#ifdef Beetle
#define pot A2
#define apin 1
#else
#define pot A3    // Pro Micro 
#define apin 0
#endif

uint16_t xStart = 4200;              // Spot size
uint16_t xStop = 5200;
uint16_t yStart = 7700;
uint16_t yStop = 8200;

void setup() {
  randomSeed(analogRead(apin));
  Touch.begin();
}

void loop() {

  int startTime;
  int stopTime;

  int mode = analogRead(pot)/210;        // 4 Modes: 0-210, 210-420, 420-630, 630-840, 840-1023

  switch (mode) {
    case 1:
      startTime = 3100;
      stopTime = 3300;   
      Touch.moveFingerTo(1, random(xStart, xStop), random(yStart, yStop));  
      delay(random(20, 50));
      Touch.releaseFinger(1);              
      break;
    case 2:
      startTime = 2200;
      stopTime = 2500;   
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
