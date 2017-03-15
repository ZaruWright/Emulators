
#include <emulators/chip8/memory.hpp>

namespace emulators {
namespace chip8 {

    Memory::Memory() : _indexRegister(0x000), _programCounter(0x200), _stackPointer(0x000), _memory{0}, _stack{0}, _registers{0} 
    {
        unsigned char chip8_fontset[80] =
        { 
          0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
          0x20, 0x60, 0x20, 0x20, 0x70, // 1
          0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
          0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
          0x90, 0x90, 0xF0, 0x10, 0x10, // 4
          0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
          0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
          0xF0, 0x10, 0x20, 0x40, 0x40, // 7
          0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
          0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
          0xF0, 0x90, 0xF0, 0x90, 0x90, // A
          0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
          0xF0, 0x80, 0x80, 0x80, 0xF0, // C
          0xE0, 0x90, 0x90, 0x90, 0xE0, // D
          0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
          0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

        // Load fontset
        for(int i = 0; i < 80; ++i)
            _memory[i] = chip8_fontset[i];
    }

    unsigned char Memory::getMemoryValue(unsigned short address)
    {
        return _memory[address];
    }

    void Memory::setMemoryValue(unsigned short address, unsigned char value)
    {
        _memory[address] = value;
    }

    void Memory::loadProgram(std::string url)
    {
        std::ifstream file(url);

        char* aux;
        aux = new char;
        unsigned short programCounterAux = _programCounter;
        while (!file.eof())
        {
            file.read(aux, 1);
            _memory[programCounterAux] = *aux;
            ++programCounterAux;
        }

        delete[] aux;
        file.close();
    }

    unsigned char Memory::getRegisterValue(unsigned short index) const
    {
        return _registers[index];
    }

    void Memory::setRegisterValue(unsigned short index, unsigned char value, MemoryOperations operation)
    {
        switch (operation)
        {
            case MemoryOperations::NONE :
                _registers[index] = value;
            break;

            case MemoryOperations::ADD :
                _registers[index] += value;
            break;

            case MemoryOperations::SUBTRACT :
                _registers[index] -= value;
            break;

            case MemoryOperations::OR :
                _registers[index] |= value;
            break;

            case MemoryOperations::AND :
                _registers[index] &= value;
            break;

            case MemoryOperations::XOR :
                _registers[index] ^= value;
            break;

            case MemoryOperations::SHIFTRIGHT :
                _registers[index] >>= value;
            break;

            case MemoryOperations::SHIFTLEFT :
                _registers[index] <<= value;
            break;
        }
    }

    void Memory::returnFromASubroutine()
    {
        --_stackPointer;
        _programCounter = _stack[_stackPointer];
    }

    void Memory::jumpToAddress(unsigned short address, unsigned short add)
    {
        _programCounter = address + add;
        _programCounter -= 2;
    }

    void Memory::callSubroutine(unsigned short address)
    {
        _stack[_stackPointer] = _programCounter;
        ++_stackPointer;
        _programCounter = address - 2;
    }

    void Memory::incrementPC()
    {
        _programCounter += 2;
    }

    void Memory::decreasePC()
    {
        _programCounter -= 2;
    }

    unsigned short Memory::getPC()
    {
        return _programCounter;
    }

    unsigned short Memory::getIndexRegister()
    {
        return _indexRegister;
    }

    void Memory::setIndexRegister(unsigned short value, MemoryOperations operation)
    {
        if (operation == MemoryOperations::NONE)
            _indexRegister = value;
        if (operation == MemoryOperations::ADD)
            _indexRegister += value;
    }

} // namespace chip8
} // namespace emulators