#include <Arduino.h>
#include <FastLED.h>
#include <Control_Surface.h>

USBMIDI_Interface midi;

#define NUM_LEDS 176
CRGB leds[NUM_LEDS];

#define DATA_PIN 3
#define BRIGHTNESS 255

// Custom MIDI callback that prints incoming messages.
struct MyMIDI_Callbacks : MIDI_Callbacks {

  // Callback for channel messages (notes, control change, pitch bend, etc.).
  void onChannelMessage(MIDI_Interface &, ChannelMessage cm) override {
    // Print the message
    Serial << F("Channel message: ")                                        //
           << hex << cm.header << ' ' << cm.data1 << ' ' << cm.data2 << dec //
           << F(" on cable ") << cm.cable.getOneBased() << endl;
  }
} callback;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);        // For printing the messages
  midi.begin();                // Initialize the MIDI interface
  midi.setCallbacks(callback); // Attach the custom callback
}

void loop() {
  midi.update(); // Continuously handle MIDI input
}


