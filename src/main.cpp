#include <Arduino.h>
#include <FastLED.h>
#include <Control_Surface.h>

USBMIDI_Interface midi;

#define NUM_LEDS 176
CRGB leds[NUM_LEDS];

#define DATA_PIN 3
#define BRIGHTNESS 255

void setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(100);
    leds[i] = CRGB::Black;
  }
}


