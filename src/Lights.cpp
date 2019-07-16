//
// Created by 김태윤 on 2019-07-16.
//

#include "Lights.hpp"

#define LEFT_HEADLIGHT_PIN 3
#define RIGHT_HEADLIGHT_PIN 4
#define LEFT_TAILLIGHT_PIN 5
#define RIGHT_TAILLIGHT_PIN 6
#define NUM_LEDS 4

CRGB lh_leds[NUM_LEDS];
CRGB rh_leds[NUM_LEDS];
CRGB lt_leds[NUM_LEDS];
CRGB rt_leds[NUM_LEDS];

void Lights::attach() {
    FastLED.addLeds<NEOPIXEL, LEFT_HEADLIGHT_PIN>(lh_leds, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, RIGHT_HEADLIGHT_PIN>(rh_leds, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, LEFT_TAILLIGHT_PIN>(lt_leds, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, RIGHT_TAILLIGHT_PIN>(rt_leds, NUM_LEDS);
}

void Lights::on() {
    fill_solid(lh_leds, NUM_LEDS, CRGB::White);
    fill_solid(rh_leds, NUM_LEDS, CRGB::White);
    fill_solid(lt_leds, NUM_LEDS, CRGB::Red);
    fill_solid(rt_leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
}

void Lights::off() {
    fill_solid(lh_leds, NUM_LEDS, CRGB::Black);
    fill_solid(rh_leds, NUM_LEDS, CRGB::Black);
    fill_solid(lt_leds, NUM_LEDS, CRGB::Black);
    fill_solid(rt_leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
}
