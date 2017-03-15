#!/bin/bash
# Replace the wrong CMakeList
cp CMakeListsSfmlGraphics.txt ~/.conan/data/sfml/2.4.0/diego_stamigni/stable/source/SFML-2.4.0/src/SFML/Graphics/CMakeLists.txt

# Compile SFML
cd ~/.conan/data/sfml/2.4.0/diego_stamigni/stable/source/SFML-2.4.0/
mkdir _build && cd _build
cmake ..
make all

# Erase old libraries
rm -rf ~/.conan/data/sfml/2.4.0/diego_stamigni/stable/package/f5a6882590d137de693642227ed35e8e26da3dac/lib/*

# Replace new libraries
cp ~/.conan/data/sfml/2.4.0/diego_stamigni/stable/source/SFML-2.4.0/_build/lib/* ~/.conan/data/sfml/2.4.0/diego_stamigni/stable/package/f5a6882590d137de693642227ed35e8e26da3dac/lib
