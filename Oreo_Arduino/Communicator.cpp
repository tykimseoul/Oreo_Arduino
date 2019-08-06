
#include "Communicator.hpp"

namespace Oreo {

size_t InstructionReceiver::m_readPos = 0;
size_t InstructionReceiver::m_processPos = 0;
byte *InstructionReceiver::m_buf;

void InstructionReceiver::InitializeReceiver(byte address) {
  Wire.begin(address);
  Wire.onReceive(InstructionReceiver::m_InterruptHandler);
  m_buf = (byte *)calloc(sizeof(byte) * 300, 0);
}

void InstructionReceiver::m_InterruptHandler(int howMany) {

  while (1 < Wire.available()) { // loop through all but the last
    byte temp = Wire.read();     // receive byte as a character
    m_buf[m_readPos++] = temp;   // print the character
  }
}

Instruction InstructionReceiver::GetInstruction() {

  uint16_t data = 0;
  if (m_readPos > m_processPos) {
    byte type = m_buf[m_processPos];
    data = (8 << m_buf[m_processPos + 1]) | m_buf[m_processPos + 2];

    Mode mode;

    switch (type) {
    case 0:
      mode = Mode::Motor;
      break;
    case 1:
      mode = Mode::Steering;
      break;
    case 2:
      mode = Mode::Light;
      break;
    default:
      mode = Mode::None;
      break;
    }

    Instruction instruction = {mode, data};
    return instruction;
  } else {
    return {Mode::None, data};
  }
}
} // namespace Oreo