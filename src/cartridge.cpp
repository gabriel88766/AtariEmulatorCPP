#include "cartridge.hpp"
#include <fstream>

Cartridge::~Cartridge(){
    delete[] rom;
}

void Cartridge::connectBus(Bus *bus){
    this->bus = bus;
}

void Cartridge::read(const char *filename){
    std::ifstream input(filename, std::ios::binary);
    rom = new unsigned char[0x1000]; //only 4K roms for now
    input.read((char *)rom, 0x1000);
}

unsigned char Cartridge::readMemory(unsigned short address){
    return rom[address];
}

void Cartridge::writeMemory(unsigned short address, unsigned char value){
    //do nothing.
}