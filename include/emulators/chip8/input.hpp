#ifndef EMULATORS_CHIP8_INPUT_HPP
#define EMULATORS_CHIP8_INPUT_HPP

#include <SFML/Window/Keyboard.hpp>

namespace emulators {
namespace chip8 {

/**
 * \ingroup chip8
 * \brief Input from Chip8.
 *
 * This class allow to control the input of the app. The control are the follows:
 *
 * Keypad                   Keyboard
 * +-+-+-+-+                +-+-+-+-+
 * |1|2|3|C|                |1|2|3|4|
 * +-+-+-+-+                +-+-+-+-+
 * |4|5|6|D|                |Q|W|E|R|
 * +-+-+-+-+       =>       +-+-+-+-+
 * |7|8|9|E|                |A|S|D|F|
 * +-+-+-+-+                +-+-+-+-+
 * |A|0|B|F|                |Z|X|C|V|
 * +-+-+-+-+                +-+-+-+-+
 *
 *
 */
class Input{
public:

    /**
    * Default constructor.
    */
    Input();

    /**
    * Returns if a key is pressed or not.
    * @param index: index of the key.
    */
    bool getKey(unsigned char index);

    /**
    * Check if a key was pressed. Normally you use this on your update function.
    */
    void setKeys();

    /**
    * Reset all keys to not pressed value.
    */
    void resetKeys();

private:

/**
 * Input
 */
bool _key[16];

}; // class Input

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_INPUT_HPP