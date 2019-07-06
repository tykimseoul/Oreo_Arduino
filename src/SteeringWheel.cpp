//
// Created by 김태윤 on 2019-07-06.
//

#include "SteeringWheel.hpp"

void SteeringWheel::steer(int angle) {
    servo.write(angle);
}

int SteeringWheel::getSteerAngle() {
    return servo.read();
}

void SteeringWheel::attach(int pin) {
    servo.attach(pin);
}
