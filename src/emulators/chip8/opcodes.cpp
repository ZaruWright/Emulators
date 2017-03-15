
#include <emulators/chip8/opcodes.hpp>

namespace emulators {
namespace chip8 {

  OpCodes::OpCodes(Graphics* graphics, Memory* memory, Input* input, Events* events) : _chip8table{&OpCodes::opCode0, &OpCodes::opCode1, &OpCodes::opCode2, &OpCodes::opCode3,
                   &OpCodes::opCode4, &OpCodes::opCode5, &OpCodes::opCode6, &OpCodes::opCode7,
                   &OpCodes::opCode8, &OpCodes::opCode9, &OpCodes::opCodeA, &OpCodes::opCodeB,
                   &OpCodes::opCodeC, &OpCodes::opCodeD, &OpCodes::opCodeE, &OpCodes::opCodeF},
                   _chip8tableOpCodes0(), _chip8tableOpCodes8(), _chip8tableOpCodesE(), _chip8tableOpCodesF(),
                   _graphics(graphics), _memory(memory), _input(input), _events(events)
  {
    _chip8tableOpCodes0.insert({0x0, &OpCodes::opCode00E0});
    _chip8tableOpCodes0.insert({0xE, &OpCodes::opCode00EE});

    _chip8tableOpCodes8.insert({0x0, &OpCodes::opCode8XY0});
    _chip8tableOpCodes8.insert({0x1, &OpCodes::opCode8XY1});
    _chip8tableOpCodes8.insert({0x2, &OpCodes::opCode8XY2});
    _chip8tableOpCodes8.insert({0x3, &OpCodes::opCode8XY3});
    _chip8tableOpCodes8.insert({0x4, &OpCodes::opCode8XY4});
    _chip8tableOpCodes8.insert({0x5, &OpCodes::opCode8XY5});
    _chip8tableOpCodes8.insert({0x6, &OpCodes::opCode8XY6});
    _chip8tableOpCodes8.insert({0x7, &OpCodes::opCode8XY7});
    _chip8tableOpCodes8.insert({0xE, &OpCodes::opCode8XYE});

    _chip8tableOpCodesE.insert({0x1, &OpCodes::opCodeEXA1});
    _chip8tableOpCodesE.insert({0xE, &OpCodes::opCodeEX9E});

    _chip8tableOpCodesF.insert({0x07, &OpCodes::opCodeFX07});
    _chip8tableOpCodesF.insert({0x0A, &OpCodes::opCodeFX0A});
    _chip8tableOpCodesF.insert({0x15, &OpCodes::opCodeFX15});
    _chip8tableOpCodesF.insert({0x18, &OpCodes::opCodeFX18});
    _chip8tableOpCodesF.insert({0x1E, &OpCodes::opCodeFX1E});
    _chip8tableOpCodesF.insert({0x29, &OpCodes::opCodeFX29});
    _chip8tableOpCodesF.insert({0x33, &OpCodes::opCodeFX33});
    _chip8tableOpCodesF.insert({0x55, &OpCodes::opCodeFX55});
    _chip8tableOpCodesF.insert({0x65, &OpCodes::opCodeFX65});
  }
                        

  void OpCodes::execute(unsigned short opcode)
  {
    (*this.*_chip8table[(opcode & 0xF000) >> 12])(opcode);
  }

  // #####################
  //   OpCode0
  // #####################

  void OpCodes::opCode0(unsigned short opcode)
  {
    _chip8tableOpCodes0[(opcode & 0x000F)](*this, opcode);
  }

  void OpCodes::opCode00E0(unsigned short opcode)
  {
    _graphics->clearWindow();
  }

  void OpCodes::opCode00EE(unsigned short opcode)
  {
    _memory->returnFromASubroutine();
  }

  // #####################
  //   OpCode1
  // #####################

  void OpCodes::opCode1(unsigned short opcode)
  {
    _memory->jumpToAddress(opcode & 0x0FFF, 0);
  }

  // #####################
  //   OpCode2
  // #####################

  void OpCodes::opCode2(unsigned short opcode)
  {
    _memory->callSubroutine(opcode & 0x0FFF);
  }

  // #####################
  //   OpCode3
  // #####################

  void OpCodes::opCode3(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x0F00) >> 8) == (opcode & 0x00FF))
        _memory->incrementPC();
  }

  // #####################
  //   OpCode4
  // #####################

  void OpCodes::opCode4(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x0F00) >> 8) != (opcode & 0x00FF))
        _memory->incrementPC();
  }

  // #####################
  //   OpCode5
  // #####################

  void OpCodes::opCode5(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x0F00) >> 8) == _memory->getRegisterValue((opcode & 0x00F0) >> 4))
        _memory->incrementPC();
  }

  // #####################
  //   OpCode6
  // #####################

  void OpCodes::opCode6(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, opcode & 0x00FF);
  }

  // #####################
  //   OpCode7
  // #####################

  void OpCodes::opCode7(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, opcode & 0x00FF, MemoryOperations::ADD);
  }
  
  // #####################
  //   OpCode8
  // #####################

  void OpCodes::opCode8(unsigned short opcode)
  {
    _chip8tableOpCodes8[(opcode & 0x000F)](*this, opcode);
  }

  void OpCodes::opCode8XY0(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4));
  }

  void OpCodes::opCode8XY1(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4), MemoryOperations::OR);
  }

  void OpCodes::opCode8XY2(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4), MemoryOperations::AND);
  }

  void OpCodes::opCode8XY3(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4), MemoryOperations::XOR);
  }

  void OpCodes::opCode8XY4(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x00F0) >> 4) > (0xFF - _memory->getRegisterValue((opcode & 0x0F00) >> 8)))
        _memory->setRegisterValue(0xF, 1);
    else
        _memory->setRegisterValue(0xF, 0);

    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4), MemoryOperations::ADD);
  }

  void OpCodes::opCode8XY5(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x00F0) >> 4) > _memory->getRegisterValue((opcode & 0x0F00) >> 8))
        _memory->setRegisterValue(0xF, 0);
    else
        _memory->setRegisterValue(0xF, 1);

    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4), MemoryOperations::SUBTRACT);
  }

  void OpCodes::opCode8XY6(unsigned short opcode)
  {
    _memory->setRegisterValue(0xF, _memory->getRegisterValue((opcode & 0x0F00) >> 8) & 0x1);
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, 1, MemoryOperations::SHIFTRIGHT);
  }

  void OpCodes::opCode8XY7(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x0F00) >> 8) > _memory->getRegisterValue((opcode & 0x00F0) >> 4))
        _memory->setRegisterValue(0xF, 0);
    else
        _memory->setRegisterValue(0xF, 1);

    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _memory->getRegisterValue((opcode & 0x00F0) >> 4) - _memory->getRegisterValue((opcode & 0x0F00) >> 8));
  }

  void OpCodes::opCode8XYE(unsigned short opcode)
  {
    _memory->setRegisterValue(0xF, _memory->getRegisterValue((opcode & 0x0F00) >> 8) >> 7);
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, 1, MemoryOperations::SHIFTLEFT);
  }

  // #####################
  //   OpCode9
  // #####################

  void OpCodes::opCode9(unsigned short opcode)
  {
    if (_memory->getRegisterValue((opcode & 0x0F00) >> 8) != _memory->getRegisterValue((opcode & 0x00F0) >> 4))
        _memory->incrementPC();
  }

  // #####################
  //   OpCodeA
  // #####################

  void OpCodes::opCodeA(unsigned short opcode)
  {
    _memory->setIndexRegister(opcode & 0x0FFF);
  }

  // #####################
  //   OpCodeB
  // #####################

  void OpCodes::opCodeB(unsigned short opcode)
  {
    _memory->jumpToAddress(opcode & 0x0FFF, _memory->getRegisterValue(0));
  }

  // #####################
  //   OpCodeC
  // #####################

  void OpCodes::opCodeC(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, (std::rand()%0xFF) & (opcode & 0x00FF));
  }

  // #####################
  //   OpCodeD
  // #####################

  void OpCodes::opCodeD(unsigned short opcode)
  {
    _memory->setRegisterValue(0xF, _graphics->selectPixels(_memory->getRegisterValue((0x0F00 & opcode) >> 8), 
                                                           _memory->getRegisterValue((0x00F0 & opcode) >> 4),
                                                           0x000F & opcode,
                                                           _memory));
  }

  // #####################
  //   OpCodeE
  // #####################

  void OpCodes::opCodeE(unsigned short opcode)
  {
    _chip8tableOpCodesE[(opcode & 0x000F)](*this, opcode);
  }

  void OpCodes::opCodeEX9E(unsigned short opcode)
  {
    if (_input->getKey(_memory->getRegisterValue((opcode & 0x0F00) >> 8)))
        _memory->incrementPC();
  }

  void OpCodes::opCodeEXA1(unsigned short opcode)
  {
    if (!_input->getKey(_memory->getRegisterValue((opcode & 0x0F00) >> 8)))
        _memory->incrementPC();
  }

  // #####################
  //   OpCodeF
  // #####################

  void OpCodes::opCodeF(unsigned short opcode)
  {
    _chip8tableOpCodesF[(opcode & 0x00FF)](*this, opcode);
  }

  void OpCodes::opCodeFX07(unsigned short opcode)
  {
    _memory->setRegisterValue((opcode & 0x0F00) >> 8, _events->getDelayTimer());
  }

  void OpCodes::opCodeFX0A(unsigned short opcode)
  {
    bool keyPress = false;

    for(unsigned int i = 0; i < 16; ++i)
    {
        if(_input->getKey(i))
        {
            _memory->setRegisterValue((opcode & 0x0F00) >> 8, i);
            keyPress = true;
        }
    }

    // If we didn't received a keypress, skip this cycle and try again.
    if (!keyPress)
        _memory->decreasePC();
  }

  void OpCodes::opCodeFX15(unsigned short opcode)
  {
    _events->setDelayTimer(_memory->getRegisterValue((opcode & 0x0F00) >> 8));
  }

  void OpCodes::opCodeFX18(unsigned short opcode)
  {
    _events->setSoundTimer(_memory->getRegisterValue((opcode & 0x0F00) >> 8));
  }

  void OpCodes::opCodeFX1E(unsigned short opcode)
  {
    if(_memory->getIndexRegister() + _memory->getRegisterValue((opcode & 0x0F00) >> 8) > 0xFFF)
        _memory->setRegisterValue(0xF, 1);
    else
        _memory->setRegisterValue(0xF, 0);

    _memory->setIndexRegister(_memory->getRegisterValue((opcode & 0x0F00) >> 8), MemoryOperations::ADD);
  }

  void OpCodes::opCodeFX29(unsigned short opcode)
  {
    _memory->setIndexRegister(_memory->getRegisterValue((opcode & 0x0F00) >> 8) * 0x5);
  }

  void OpCodes::opCodeFX33(unsigned short opcode)
  {
    _memory->setMemoryValue(_memory->getIndexRegister(), _memory->getRegisterValue((opcode & 0x0F00) >> 8) / 100);
    _memory->setMemoryValue(_memory->getIndexRegister()+1, (_memory->getRegisterValue((opcode & 0x0F00) >> 8) / 10) % 10);
    _memory->setMemoryValue(_memory->getIndexRegister()+2, (_memory->getRegisterValue((opcode & 0x0F00) >> 8) % 100)% 10);
  }

  void OpCodes::opCodeFX55(unsigned short opcode)
  {
    for (unsigned int i = 0; i < (unsigned int) ((opcode & 0x0F00) >> 8); ++i)
        _memory->setMemoryValue(_memory->getIndexRegister() + i, _memory->getRegisterValue(i));

    _memory->setIndexRegister(((opcode & 0x0F00) >> 8) + 1, MemoryOperations::ADD);
  }

  void OpCodes::opCodeFX65(unsigned short opcode)
  {
    for (unsigned int i = 0; i < (unsigned int) ((opcode & 0x0F00) >> 8); ++i)
        _memory->setRegisterValue(i, _memory->getMemoryValue(_memory->getIndexRegister() + i));

    _memory->setIndexRegister(((opcode & 0x0F00) >> 8) + 1, MemoryOperations::ADD);
  }

} // namespace chip8
} // namespace emulators