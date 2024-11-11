#ifndef BUS_H
#define BUS_H
//NES BUS
#include "6507.h"
#include "cartridge.h"

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