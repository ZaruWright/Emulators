#ifndef EMULATORS_CHIP8_MEMORY_HPP
#define EMULATORS_CHIP8_MEMORY_HPP

#include <string>
#include <fstream>

namespace emulators {
namespace chip8 {

/*!
 * Enumerator that represents the memory operations.
 */
enum MemoryOperations
{
    NONE,
    ADD,
    SUBTRACT,
    OR,
    AND,
    XOR,
    SHIFTRIGHT,
    SHIFTLEFT
};

/**
 * \ingroup chip8
 * \brief Memory from Chip8.
 *
 * This class allow to manage the chip memory memory, registers, main memory and stack.
 */
class Memory{
public:

    /**
    * Default constructor.
    */
    Memory();

    /**
    * Returns the value from a memory address.
    * @param address: memory address.
    */
    unsigned char getMemoryValue(unsigned short address);

    /**
    * Set a value to the value of a memory address.
    * @param address: memory address.
    * @param value: value to set.
    */
    void setMemoryValue(unsigned short address, unsigned char value);
    
    /**
    * Load the game into memory.
    * @param url: url of the game.
    */
    void loadProgram(std::string url);
    
    /**
    * Gives the functionality about return from a subroutine.
    */
    void returnFromASubroutine();
    
    /**
    * Jump to the address given. You can specify a number to add it.
    * @param address: address to jump.
    * @param add: add this number to the value from memory address
    */
    void jumpToAddress(unsigned short address, unsigned short add);
    
    /**
    * Return the value of the index register.
    * @param index: number of the register.
    */
    unsigned char getRegisterValue(unsigned short index) const;
    
    /**
    * Set a value to the register. Also you can specify a MemoryOperation that allows apply the binary operation given, by example if you 
    * specify the MemoryOpertaions::ADD value, the function will do something like 
    * \code{.cpp}
    * register[index] += value;
    * \endcode
    * If you don't specify anything, it will do the assignment opertaor.
    * @param index: index to get the register
    * @param value: value to set
    * @param operation: binary operation to set.
    */
    void setRegisterValue(unsigned short index, unsigned char value, MemoryOperations operation = MemoryOperations::NONE);
    
    /**
    * Calling a subroutine
    * @param address: address of the subroutine.
    */
    void callSubroutine(unsigned short address);
    
    /**
    * Increment program counter.
    */
    void incrementPC();
    
    /**
    * Decrease program counter.
    */
    void decreasePC();
    
    /**
    * Returns the program counter.
    */
    unsigned short getPC();
    
    /**
    * Returns the index register.
    */
    unsigned short getIndexRegister();
    
    /**
    * Set the index register.
    * @param value: value to set
    * @param operation: binary operation to set
    */
    void setIndexRegister(unsigned short value, MemoryOperations operation = MemoryOperations::NONE);

private:

    /*
    * Index
    */
    unsigned short _indexRegister;
    unsigned short _programCounter;
    unsigned short _stackPointer;

    /**
     * Memory
     */
    unsigned char _memory[4096];

    /**
     * Stack
     */
    unsigned short _stack[16];

    /**
     * Registers
     */
    unsigned char _registers[16];

}; // class Memory

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_MEMORY_HPP