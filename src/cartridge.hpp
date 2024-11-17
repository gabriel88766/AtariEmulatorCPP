#ifndef CARTRIDGE_HPP
#define CARTRIDGE_HPP

#include "bus.hpp"

class Bus;

class Cartridge{
private:
    Bus *bus;
    unsigned char *rom;
public:
    ~Cartridge();
    void connectBus(Bus *bus);
    void read(const char *filename);
    unsigned char readMemory(unsigned short address);
    void writeMemory(unsigned short address, unsigned char value);
};




#endif