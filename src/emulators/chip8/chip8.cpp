#include <emulators/chip8/chip8.hpp>


namespace emulators {
namespace chip8 {

Chip8::Chip8() : _graphics(new Graphics("Chip8 Emulator", 1024, 512)),
                 _memory(new Memory()),
                 _input(new Input()),
                 _events(new Events()),
                 _opcodes(new OpCodes(_graphics, _memory, _input, _events)) {}

Chip8::~Chip8()
{
    delete _graphics;
    delete _memory;
    delete _input;
    delete _events;
    delete _opcodes;
}

void  Chip8::play(std::string url)
{
    _memory->loadProgram(url);

    while (_graphics->windowIsOpen())
    {
        // Keyboard input
        _input->resetKeys();
        _input->setKeys();

        // Update timers
        _events->update(1);

        // Emulate a cycle
        emulateCycle();

        // Draw graphics
        _graphics->draw();
    }
}

void Chip8::emulateCycle()
{
    unsigned short firstByte = _memory->getMemoryValue(_memory->getPC()) % 256;
    unsigned short secondByte = _memory->getMemoryValue(_memory->getPC()+1) % 256;
    unsigned short opcode = (firstByte << 8) | secondByte;

    _opcodes->execute(opcode);

    _memory->incrementPC();
}

} // namespace chip8
} // namespace emulators