//
// Created by 김태윤 on 2019-07-06.
//

#include "Motor.hpp"


void Motor::accelerate(int s) {
    int sign = s > 0 ? 1 : -1;
    int speed = static_cast<int>(map(abs(s), 0, 100, 50, 100));
    esc.writeMicroseconds(1500 + speed * sign);
}

int Motor::getSpeed() {
    return esc.readMicroseconds();
}

void Motor::attach(int pin) {
    esc.attach(pin);
    delay(1000);
    esc.write(180);  // set “TX” to full speed
    delay(1000);     // Change this to delay until you hear the ESC beep once
    esc.write(90);   // set “TX” to idle after Li-Po (first beep) is selected from set-up sequence
}
