# Emulators
Repository to learn about emulators

## Dependencies

 - **[CMake > 2.8](https://cmake.org/)** as buildsystem.
 - **[conan.io](https://www.conan.io/)** as package manager.
 - **A C++14 compiler** GCC 5.1 or clang 3.8 if possible. VS2015 may work.
 - **[Doxygen](http://www.stack.nl/~dimitri/doxygen)** to make the documentation.

## Emulators
### Chip8
Well, I'm started this project because in the future I'll want to be able to do a Game Boy Color emulator, and I read
that Chip8 was a good project to start to think on emulators.

The operation is simple, you execute the program with an argument that is the url of the game, like this:
<code>
    ./chip8executable urlOfGame
</code>

## License

Emulators is license under the MIT license. See LICENSE for details.
