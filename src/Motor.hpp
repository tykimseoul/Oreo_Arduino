//
// Created by 김태윤 on 2019-07-06.
//

#include "../lib/Servo/src/Servo.h"
#include "../../../.platformio/packages/framework-arduinoavr/cores/arduino/USBAPI.h"

class Motor {
private:
    Servo esc;
public:
    void attach(int pin);
    void accelerate(int s);
    int getSpeed();

};
