#ifndef EMULATORS_CHIP8_GRAPHICS_HPP
#define EMULATORS_CHIP8_GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <emulators/chip8/memory.hpp>

namespace emulators {
namespace chip8 {

/**
 * \ingroup chip8
 * \brief Graphics from Chip8.
 *
 * Manage the graphical part of the emulator. It's made with SFML.
 */
class Graphics
{
public:

    Graphics() = delete;

    /**
    * Init the graphics.
    * @param windowName: The name that appear to the top of the window.
    * @param windowWidth: widht of the window wanted.
    * @param windowHeight: height of the window wanted.
    */
    Graphics(std::string windowName, unsigned int windowWidth, unsigned int windowHeight);
    
    /**
    * Default destructor.
    */
    ~Graphics();

    /**
    * Clears the window.
    */
    void clearWindow();

    /**
    * Select the pixels that will be drawn on the next frame.
    * @param xPosition: x position
    * @param yPosition: y position
    * @param height: amount of pixels to draw
    * @param memory: pointer memory refence.
    */
    unsigned char selectPixels(unsigned int xPosition, unsigned int yPosition, unsigned int height, Memory*& memory);

    /**
    * Draw the selected pixels.
    */
    void draw();

    /**
    * Check if the window is close or is open.
    */
    bool windowIsOpen();
private:
    
    const unsigned int _chip8RealWidth;
    const unsigned int _chip8RealHeight;
    unsigned int _windowWidth;
    unsigned int _windowHeight;
    unsigned int _widthUnitSize;
    unsigned int _heightUnitSize;
    sf::RenderWindow _window;
    unsigned char* _pixels;

}; // class Graphics

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_GRAPHICS_HPP