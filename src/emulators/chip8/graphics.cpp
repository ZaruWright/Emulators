
#include <emulators/chip8/graphics.hpp>
#include <iostream>

namespace emulators {
namespace chip8 {

Graphics::Graphics(std::string windowName, unsigned int windowWidth, unsigned int windowHeight) : 
            _chip8RealWidth(64),
            _chip8RealHeight(32),
            _windowWidth(windowWidth), 
            _windowHeight(windowHeight),
            _widthUnitSize(_windowWidth/_chip8RealWidth),
            _heightUnitSize(_windowHeight/_chip8RealHeight), 
            _window(sf::VideoMode(_windowWidth,_windowHeight), windowName),
            _pixels(new unsigned char[_chip8RealWidth * _chip8RealHeight])
            {
                for (unsigned int i = 0; i < _chip8RealWidth * _chip8RealHeight; ++i)
                    _pixels[i] = 0x0;
            }

Graphics::~Graphics()
{
    delete [] _pixels;
}

void Graphics::clearWindow()
{
    for (unsigned int i = 0; i < _chip8RealWidth * _chip8RealHeight; ++i)
        _pixels[i] = 0x0;
    
    _window.clear();
}

unsigned char Graphics::selectPixels(unsigned int xPosition, unsigned int yPosition, unsigned int height, Memory*& memory)
{
    unsigned char carryFlag = 0;
    unsigned short pixel;
    unsigned short indexAddress;

    for (unsigned int y = 0; y < height; ++y)
    {
        indexAddress = memory->getIndexRegister() + y;
        pixel = memory->getMemoryValue(indexAddress);

        for (unsigned int x = 0; x < 8; ++x)
        {
            unsigned short selectedBit = (0x80 >> x);
            if ((pixel & selectedBit) != 0)
            {
                if (_pixels[((y + yPosition) * _chip8RealWidth) + xPosition + x] == 1)
                    carryFlag = 1;
                _pixels[((y + yPosition) * _chip8RealWidth) + xPosition + x] ^= 1;
            }
        }
    }

    return carryFlag;
}

void Graphics::draw()
{
    for (unsigned int height = 0; height < _chip8RealHeight; ++height)
    {
        for (unsigned int width = 0; width < _chip8RealWidth; ++width)
        {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(_widthUnitSize,_heightUnitSize));
            rectangle.setPosition(width*_widthUnitSize, height*_heightUnitSize);

            if (_pixels[(height*_chip8RealWidth)+width] == 0)
                rectangle.setFillColor( sf::Color::Black );
            else
            {
                rectangle.setFillColor( sf::Color::White );
            }
            _window.draw(rectangle);
        }
    }
    _window.display();
}

bool Graphics::windowIsOpen()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            _window.close();
    }

    return _window.isOpen();
}

} // namespace chip8
} // namespace emulators