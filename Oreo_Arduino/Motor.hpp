#pragma once

#include "Arduino.h"
#include <Servo.h>

namespace Oreo {

class Motor {
public:
  Motor(int mainMotorPin, int steerMotorPin)
      : m_pin(mainMotorPin), m_servoPin(steerMotorPin) {
    m_motor.attach(m_pin);
    m_steerMotor.attach(m_servoPin);
  }

  void SetSpeed(int speed) {
    int sign = speed > 0 ? 1 : -1;
    int temp = static_cast<int>(map(abs(speed), 0, 100, 50, 100));
    m_motor.writeMicroseconds(90 + temp * sign);
  }

  void SetServo(int value) { m_steerMotor.write(value); }

private:
  int m_pin;
  int m_servoPin;
  Servo m_motor;
  Servo m_steerMotor;
};
} // namespace Oreo
