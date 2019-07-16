#include "Arduino.h"
#include "Motor.hpp"
#include "SteeringWheel.hpp"
#include "Lights.hpp"
#include <Servo.h>
#include <FastLED.h>

#define MOTOR_PIN 9
#define STEERING_PIN 7

Motor motor;
SteeringWheel steeringWheel;
Lights lights;

void setup() {
    lights.attach();
    motor.attach(MOTOR_PIN);
    steeringWheel.attach(STEERING_PIN);
    Serial.begin(9600);
}


void loop() {
    motor.accelerate(100);
    steeringWheel.steer(180);
    lights.on();
}
