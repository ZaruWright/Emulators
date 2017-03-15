
#include <emulators/chip8/events.hpp>

namespace emulators {
namespace chip8 {

    Events::Events() : _delayTimer(0x0000), _soundTimer(0x0000) {}

    void Events::setDelayTimer(unsigned char value)
    {
        _delayTimer = value;
    }

    void Events::setSoundTimer(unsigned char value)
    {
        _soundTimer = value;
    }

    unsigned char Events::getDelayTimer()
    {
        return _delayTimer;
    }

    unsigned char Events::getSoundTimer()
    {
        return _soundTimer;
    }

    void Events::update(unsigned int time)
    {
        if (_delayTimer > 0)
            _delayTimer -= time;

        if (_soundTimer > 0)
            _soundTimer -= time;
    }

} // namespace chip8
} // namespace emulators