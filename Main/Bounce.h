#include "Arduino.h"

class Bounce {
  public:
    Bounce(){
      // Blank constructor  
    };
    void runPattern();
  private:
};

void Bounce::runPattern() {

  uint16_t posBeat  = beatsin16(30, 0, NUM_LEDS + 3, 0, 0);
  uint16_t posBeat2 = beatsin16(60, 0, NUM_LEDS + 3, 0, 0);

  uint16_t posBeat3 = beatsin16(30, 0, NUM_LEDS + 3, 0, 32767);
  uint16_t posBeat4 = beatsin16(60, 0, NUM_LEDS + 3, 0, 32767);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(10, 0, 255, 50, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 5);

  leds[0] = CRGB::Black;  
  leds[1] = CRGB::Black; 
  leds[2] = CRGB::Black; 

  btn.tick();
  FastLED.show();
}