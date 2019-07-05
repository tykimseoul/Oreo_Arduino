#include "Arduino.h"
#include "Motor.hpp"
#include <Servo.h>

Motor motor;


void setup() {
    motor.attach(9);

    Serial.begin(9600);
}


void loop() {
    motor.accelerate(100);
}
