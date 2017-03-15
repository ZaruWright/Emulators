#ifndef EMULATORS_CHIP8_OPCODES_HPP
#define EMULATORS_CHIP8_OPCODES_HPP

#include <functional>
#include <unordered_map>
#include <emulators/chip8/graphics.hpp>
#include <emulators/chip8/memory.hpp>
#include <emulators/chip8/input.hpp>
#include <emulators/chip8/events.hpp>

namespace emulators {
namespace chip8 {

/**
 * \ingroup chip8
 * \brief OpCodes supported by Chip8
 *
 * This class gives an implementation of the opcodes of chip8.
 */
class OpCodes{
public:

    OpCodes() = delete;

    /**
    * OpCode constructor.
    * @param graphics: graphics reference.
    * @param memory: memory refenrence.
    * @param input: input reference.
    * @param events: events reference.
    */
    OpCodes(Graphics* graphics, Memory* memory, Input* input, Events* events);

    /**
    * Execute the following opcode.
    * @param opcode: the opcode.
    */
    void execute(unsigned short opcode);

private:

    void opCode0(unsigned short opcode);
    void opCode00E0(unsigned short opcode);
    void opCode00EE(unsigned short opcode);

    void opCode1(unsigned short opcode);
    void opCode2(unsigned short opcode);
    void opCode3(unsigned short opcode);
    void opCode4(unsigned short opcode);
    void opCode5(unsigned short opcode);
    void opCode6(unsigned short opcode);
    void opCode7(unsigned short opcode);

    void opCode8(unsigned short opcode);
    void opCode8XY0(unsigned short opcode);
    void opCode8XY1(unsigned short opcode);
    void opCode8XY2(unsigned short opcode);
    void opCode8XY3(unsigned short opcode);
    void opCode8XY4(unsigned short opcode);
    void opCode8XY5(unsigned short opcode);
    void opCode8XY6(unsigned short opcode);
    void opCode8XY7(unsigned short opcode);
    void opCode8XYE(unsigned short opcode);

    void opCode9(unsigned short opcode);
    void opCodeA(unsigned short opcode);
    void opCodeB(unsigned short opcode);
    void opCodeC(unsigned short opcode);
    void opCodeD(unsigned short opcode);

    void opCodeE(unsigned short opcode);
    void opCodeEX9E(unsigned short opcode);
    void opCodeEXA1(unsigned short opcode);

    void opCodeF(unsigned short opcode);
    void opCodeFX07(unsigned short opcode);
    void opCodeFX0A(unsigned short opcode);
    void opCodeFX15(unsigned short opcode);
    void opCodeFX18(unsigned short opcode);
    void opCodeFX1E(unsigned short opcode);
    void opCodeFX29(unsigned short opcode);
    void opCodeFX33(unsigned short opcode);
    void opCodeFX55(unsigned short opcode);
    void opCodeFX65(unsigned short opcode);

    void (OpCodes::* _chip8table[16])(unsigned short);
    std::unordered_map<unsigned short, std::function<void(OpCodes&, unsigned short)>> _chip8tableOpCodes0;
    std::unordered_map<unsigned short, std::function<void(OpCodes&, unsigned short)>> _chip8tableOpCodes8;
    std::unordered_map<unsigned short, std::function<void(OpCodes&, unsigned short)>> _chip8tableOpCodesE;
    std::unordered_map<unsigned short, std::function<void(OpCodes&, unsigned short)>> _chip8tableOpCodesF;
    Graphics* _graphics;
    Memory* _memory;
    Input* _input;
    Events* _events;

}; // class Memory

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_OPCODES_HPP