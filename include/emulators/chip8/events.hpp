#ifndef EMULATORS_CHIP8_EVENTS_HPP
#define EMULATORS_CHIP8_EVENTS_HPP

namespace emulators {
namespace chip8 {

/**
 * \ingroup chip8
 * \brief Events from Chip8.
 *
 * Allow to manage the chip8 events, in particular, delay timer and sound timer. 
 */
class Events{
public:
    /**
    * Default Constructor
    */
    Events();

    /**
    * Set a value to the delay timer.
    * @param value: value to set.
    */
    void setDelayTimer(unsigned char value);
    
    /**
    * Set a value to the sound timer.
    * @param value: value to set.
    */
    void setSoundTimer(unsigned char value);

    /**
    * Get the value from delay timer.
    */
    unsigned char getDelayTimer();
    
    /**
    * Get value from sound timer
    */
    unsigned char getSoundTimer();

    /**
    * Update events values.
    * @param time: amount of time that has passed
    */
    void update(unsigned int time);

private:

    /**
     * Events
     */
    unsigned char _delayTimer;
    unsigned char _soundTimer;
}; // class Events

} // namespace chip8
} // namespace emulators

#endif // EMULATORS_CHIP8_EVENTS_HPP