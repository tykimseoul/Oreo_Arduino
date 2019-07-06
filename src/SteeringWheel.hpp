//
// Created by 김태윤 on 2019-07-06.
//

#include <Servo.h>

class SteeringWheel {
private:
    Servo servo;
public:
    void attach(int pin);
    void steer(int angle);
    int getSteerAngle();

};