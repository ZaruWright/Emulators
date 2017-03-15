
#include <emulators/chip8/input.hpp>

namespace emulators {
namespace chip8 {

    Input::Input() : _key{false} {}

    bool Input::getKey(unsigned char index)
    {
        return _key[index];
    }

    void Input::setKeys()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            _key[1] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            _key[2] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            _key[3] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            _key[12] = true;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            _key[4] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            _key[5] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            _key[6] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            _key[13] = true;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            _key[7] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            _key[8] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            _key[9] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            _key[14] = true;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            _key[10] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            _key[0] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            _key[11] = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
            _key[15] = true;
    }

    void Input::resetKeys()
    {
        for (unsigned int i = 0; i < 16; ++i)
            _key[i] = false;
    }

} // namespace chip8
} // namespace emulators