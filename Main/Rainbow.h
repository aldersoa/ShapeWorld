#include "Arduino.h"

class Rainbow {
  public:
    Rainbow(){};
    void runPattern();
  private:
};

void Rainbow::runPattern() {
  
  uint16_t beatA = beatsin16(30, 0, 255);
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_rainbow(leds, NUM_LEDS, (beatA+beatB)/2, 8);

  leds[0] = CRGB::Black;  
  leds[1] = CRGB::Black; 
  leds[2] = CRGB::Black; 


  btn.tick();
  FastLED.show();
}