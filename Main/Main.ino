#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS 68
#define LED_PIN 2
#define BTN_PIN 3
#define MIC_PIN 4
#define SAMPLE_TIME 50


CRGB leds[NUM_LEDS];

uint8_t patternCounter = 0;
bool isRunning = false;
int sensorValue = 0;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;

OneButton btn = OneButton(BTN_PIN, true, true);

#include "Bounce.h"
#include "Rainbow.h"
#include "Disco.h"
#include "Caterpillar.h"
#include "Moody.h"


void setup() {
  
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  
  FastLED.setBrightness(30); // takes ints 0 - 250
 
  Serial.begin(9600);

  btn.attachClick(nextPattern);
}


void loop() {  

  switch (patternCounter) {
    case 0:
      Serial.println("bounce");
      runBounce();
      break;
    case 1:
      Serial.println("rainbow");
      runRainbow();
      break;  
    case 2:
      Serial.println("disco");
      runDisco();
      break;
    case 3:
      Serial.println("caterpillar");
      runCaterpillar();
      break;
    case 4:
      Serial.println("moody");
      runMoody();
      break;
  }

  leds[0] = CRGB::Black;  
  leds[1] = CRGB::Black;  
  leds[2] = CRGB::Black; 

  FastLED.show();
  btn.tick();
}

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 5;
}

void runBounce(){
  isRunning = true;
  Bounce bounce = Bounce();
  while(isRunning) bounce.runPattern();
}

void runRainbow(){
  isRunning = true;
  Rainbow rainbow = Rainbow();
  while(isRunning) rainbow.runPattern();
}

void runDisco(){
  isRunning = true;
  Disco disco = Disco();
  while(isRunning) disco.runPattern();
}

void runCaterpillar(){
  isRunning = true;
  Caterpillar caterpillar = Caterpillar();
  while(isRunning) caterpillar.runPattern();
}

void runMoody(){
  isRunning = true;
  Moody moody = Moody();
  while(isRunning) moody.runPattern();
}