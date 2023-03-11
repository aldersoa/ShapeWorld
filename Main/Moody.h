#include "Arduino.h"

uint8_t paletteIndex = 0;
uint8_t paletteChooser = 0;

DEFINE_GRADIENT_PALETTE (white) {
    0,  132,  90,  109,  // mauve taupe
    128,  62,  25,  41,  // dark purple
    200,  110,  117,  168,  // dark blue gray
    255,  255,  255,  255  // full white
};
DEFINE_GRADIENT_PALETTE (red) {
    0,  250,  0,  0,  // red
    128,  250,  45,  5,  // orange
    200,  250,  0,  0,  // red
    255,  250,  45,  5  // orange
};
DEFINE_GRADIENT_PALETTE (green) {
    0,  0,  255,  0,  // green
    128,  255,  255,  0,  // bright yellow
    200,  0,  255,  0,  // green
    255,  255,  255,  0  // bright yellow
};
DEFINE_GRADIENT_PALETTE (blue) {
    0,  114,  0,  255,  // royal purple
    128,  0,  0,  191,  // navy
    200,  114,  0,  255,  // royal purle
    255,  0,  0,  191  // navy
};
DEFINE_GRADIENT_PALETTE (chris) {
    0,  0,  231,  255,  // sky blue crayola
    128,  57,  163,  0,  // laurel green
    200,  10,  59,  255,  // oxford blue
    255,  255,  48,  122  // shimmering blush
};
 
// activate your palette
CRGBPalette16 myPal = white;


class Moody {
  public:
    Moody(){};
    void runPattern();
  private:
};

void Moody::runPattern() {
  
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);

  if (paletteChooser == 0) {
    myPal = white; 
  } else if (paletteChooser == 1) {
    myPal = red; 
  } else if (paletteChooser == 2) {
    myPal = green; 
  } else if (paletteChooser == 3) {
    myPal = blue; 
  } else if (paletteChooser == 4) {
    myPal = chris;
  }

  btn.attachDoubleClick([]() {
    if (myPal == chris) {
      paletteChooser = 0;
    }
    paletteChooser++;
  });

  EVERY_N_MILLISECONDS(50) {
    paletteIndex++;
  }

  leds[0] = CRGB::Black;  
  leds[1] = CRGB::Black; 
  leds[2] = CRGB::Black; 

  btn.tick();
  FastLED.show();
}