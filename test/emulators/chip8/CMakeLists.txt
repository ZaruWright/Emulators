add_executable(chip8-test main.cpp)

target_include_directories(chip8-test PRIVATE "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(chip8-test PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()

target_link_libraries(chip8-test PRIVATE emulators-chip8 CONAN_PKG::sfml)

add_test(chip8-test chip8-test)
