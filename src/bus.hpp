#ifndef BUS_HPP
#define BUS_HPP
//NES BUS
#include "6507.hpp"
#include "cartridge.hpp"

class CPU;
class Cartridge;

class Bus{
private:
    CPU *cpu;
    Cartridge *cartridge;
    // unsigned char memory[0x800];
public:
    Bus(){}
    void connectCPU(CPU *cpu);
    void connectCartridge(Cartridge *cartridge);
    unsigned char readAddress(unsigned short address);
    void writeAddress(unsigned short address, unsigned char value);
};

#endif