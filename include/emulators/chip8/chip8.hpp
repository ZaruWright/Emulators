#ifndef EMULATORS_CHIP8_CHIP8_HPP
#define EMULATORS_CHIP8_CHIP8_HPP

#include <emulators/chip8/graphics.hpp>
#include <emulators/chip8/memory.hpp>
#include <emulators/chip8/input.hpp>
#include <emulators/chip8/events.hpp>
#include <emulators/chip8/opcodes.hpp>
#include <string>

namespace emulators {
namespace chip8 {

/**
 * \ingroup chip8
 * \brief Chip8 system.
 *
 * This class allow to create a Chip8 interpreter which you can play games with a url game given.
 */
class Chip8
{
public:

    /**
    * Chip8 constructor, create a chip8 emulator
    */
    Chip8();

    /**
    * Chip8 destructor.
    */
    ~Chip8();

    /**
    * Run chip8 emulator.
    * @param url: url of your chip8 game on your PC.
    */
    void play(std::string url);

private:

    void emulateCycle();

    // Curents vars
    unsigned short _currentOpCode;

    // Chip8 cores
    Graphics* _graphics;
    Memory* _memory;
    Input* _input;
    Events* _events;
    OpCodes* _opcodes;

}; // class Chip8

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_CHIP8_HPP