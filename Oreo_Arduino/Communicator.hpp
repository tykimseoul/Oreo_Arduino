#pragma once

#include "Arduino.h"
#include <SPI.h>
#include <Wire.h>

namespace Oreo {

enum class Mode {
  None,
  Motor,
  Steering,
  Light,
};

struct Instruction {
  Mode Todo;
  uint16_t Data;
};

class InstructionReceiver {
public:
  static void InitializeReceiver(byte address);

  static Instruction GetInstruction();

private:
  static void m_InterruptHandler(int howMany);
  static size_t m_readPos;
  static size_t m_processPos;
  static byte *m_buf;
};

// class Communicator {
// public:
//   static Communicator() {
//     SPCR |= _BV(SPE);   // Enable SPI
//     SPCR &= ~_BV(MSTR); // Set as slave
//     SPCR |= _BV(SPIE);  // Enable the interrupt
//     SPI.setClockDivider(SPI_CLOCK_DIV16);
//   }

// private:
//   static ISR(SPI_STC_vect) {
//     byte temp = SPDR;
//     if (m_readpos < sizeof(c)) {
//       m_buf[m_readPos++] = temp;
//     } else {
//       readPos = 0;
//       m_buf[m_readPos++] = temp;
//     }
//   }

//   static Instruction ProcessInstruction() {
//     byte type = m_buf[m_processPos] uint16_t data =
//         (8 << m_buf[m_processPos + 1]) | m_buf[m_processPos + 2];

//     Mode mode;

//     switch (type) {
//     case 0:
//       mode = Mode::Motor;
//       break;
//     case 1:
//       mode = Mode::Steering;
//       break;
//     case 2:
//       mode = Mode::Light;
//       break;
//     default:
//       break;
//     }

//     Instruction instruction = {mode, data};
//     return instruction;
//   }

//   static bool m_hasData;
//   static size_t m_readPos;
//   static size_t m_processPos;
//   static byte m_buf[300];
// };

} // namespace Oreo
