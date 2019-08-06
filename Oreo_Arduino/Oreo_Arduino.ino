#include "Communicator.hpp"
#include "Motor.hpp"

using namespace Oreo;

const byte address = 0x08;
void setup() {
  // put your setup code here, to run once:
  InstructionReceiver::InitializeReceiver(address);
  Motor(3, 5);
}

void loop() {
  // put your main code here, to run repeatedly:
  Instruction instruction = InstructionReceiver::GetInstruction();
}
