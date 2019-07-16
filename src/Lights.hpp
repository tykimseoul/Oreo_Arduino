//
// Created by 김태윤 on 2019-07-16.
//
#include "../lib/FastLED_3.2.0/FastLED.h"
#include "../../../.platformio/packages/toolchain-atmelavr/avr/include/stdint.h"

class Lights {
private:
public:
    void attach();
    void on();
    void off();
};