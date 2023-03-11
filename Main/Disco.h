#include "Arduino.h"

class Disco {
  public:
    Disco(){};
    void runPattern();
  private:
};

void Disco::runPattern() {

  uint16_t sinBeat   = beatsin16(20, 3, NUM_LEDS, 0, 0);
  uint16_t sinBeat2  = beatsin16(20, 3, NUM_LEDS, 0, 21845);
  uint16_t sinBeat3  = beatsin16(20, 3, NUM_LEDS, 0, 43690);

  leds[sinBeat]   = CRGB::Cyan;
  leds[sinBeat2]  = CRGB::Purple;
  leds[sinBeat3]  = CRGB::Blue;
  
  fadeToBlackBy(leds, NUM_LEDS, 10);

  leds[0] = CRGB::Black;  
  leds[1] = CRGB::Black; 
  leds[2] = CRGB::Black; 

  btn.tick();
  FastLED.show();
}