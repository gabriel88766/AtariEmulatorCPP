#ifndef TIA_HPP
#define TIA_HPP

#include "bus.hpp"

class Bus;

class Color{
public:
    unsigned char R, G, B;
};

class Tia{
private:
    Bus *bus;
public:
    ~Tia();
    void connectBus(Bus *bus);
    unsigned char readMemory(unsigned short address);
    void writeMemory(unsigned short address, unsigned char value);
};




#endif