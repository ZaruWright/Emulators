add_library(emulators-chip8 chip8.cpp graphics.cpp events.cpp input.cpp memory.cpp opcodes.cpp)

target_include_directories(emulators-chip8 PUBLIC "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(emulators-chip8 PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()
