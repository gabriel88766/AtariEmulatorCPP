#include "tia.hpp"
#include <fstream>


Color colors[128] = {
    {0x00, 0x00, 0x00}, //0x00
    {0x44, 0x44, 0x00}, //0x01
    {0x70, 0x28, 0x00}, //0x02
    {0x84, 0x18, 0x00}, //0x03
    {0x88, 0x00, 0x00}, //0x04
    {0x78, 0x00, 0x5C}, //0x05
    {0x48, 0x00, 0x78}, //0x06
    {0x14, 0x00, 0x84}, //0x07
    {0x00, 0x00, 0x88}, //0x08
    {0x00, 0x18, 0x7C}, //0x09
    {0x00, 0x2C, 0x5C}, //0x0A
    {0x00, 0x40, 0x2C}, //0x0B
    {0x00, 0x3C, 0x00}, //0x0C
    {0x14, 0x38, 0x00}, //0x0D
    {0x2C, 0x30, 0x00}, //0x0E
    {0x44, 0x28, 0x00}, //0x0F
    /* ........ */
    {0x00, 0x00, 0x00}, //0x10
    {0x44, 0x44, 0x00}, //0x11
    {0x00, 0x00, 0x00}, //0x12
    {0x44, 0x44, 0x00}, //0x13
    {0x00, 0x00, 0x00}, //0x14
    {0x44, 0x44, 0x00}, //0x15
    {0x00, 0x00, 0x00}, //0x16
    {0x44, 0x44, 0x00}, //0x17
    {0x00, 0x00, 0x00}, //0x18
    {0x44, 0x44, 0x00}, //0x19
    {0x00, 0x00, 0x00}, //0x1A
    {0x44, 0x44, 0x00}, //0x1B
    {0x00, 0x00, 0x00}, //0x1C
    {0x44, 0x44, 0x00}, //0x1D
    {0x00, 0x00, 0x00}, //0x1E
    {0x44, 0x44, 0x00}, //0x1F
    {0x00, 0x00, 0x00}, //0x20
    {0x44, 0x44, 0x00}, //0x21
    {0x00, 0x00, 0x00}, //0x22
    {0x44, 0x44, 0x00}, //0x23
    {0x00, 0x00, 0x00}, //0x24
    {0x44, 0x44, 0x00}, //0x25
    {0x00, 0x00, 0x00}, //0x26
    {0x44, 0x44, 0x00}, //0x27
    {0x00, 0x00, 0x00}, //0x28
    {0x44, 0x44, 0x00}, //0x29
    {0x00, 0x00, 0x00}, //0x2A
    {0x44, 0x44, 0x00}, //0x2B
    {0x00, 0x00, 0x00}, //0x2C
    {0x44, 0x44, 0x00}, //0x2D
    {0x00, 0x00, 0x00}, //0x2E
    {0x44, 0x44, 0x00}, //0x2F
    {0x00, 0x00, 0x00}, //0x30
    {0x44, 0x44, 0x00}, //0x31
    {0x00, 0x00, 0x00}, //0x32
    {0x44, 0x44, 0x00}, //0x33
    {0x00, 0x00, 0x00}, //0x34
    {0x44, 0x44, 0x00}, //0x35
    {0x00, 0x00, 0x00}, //0x36
    {0x44, 0x44, 0x00}, //0x37
    {0x00, 0x00, 0x00}, //0x38
    {0x44, 0x44, 0x00}, //0x39
    {0x00, 0x00, 0x00}, //0x3A
    {0x44, 0x44, 0x00}, //0x3B
    {0x00, 0x00, 0x00}, //0x3C
    {0x44, 0x44, 0x00}, //0x3D
    {0x00, 0x00, 0x00}, //0x3E
    {0x44, 0x44, 0x00}, //0x3F
    {0x00, 0x00, 0x00}, //0x40
    {0x44, 0x44, 0x00}, //0x01
    {0x00, 0x00, 0x00}, //0x02
    {0x44, 0x44, 0x00}, //0x03
    {0x00, 0x00, 0x00}, //0x04
    {0x44, 0x44, 0x00}, //0x05
    {0x00, 0x00, 0x00}, //0x06
    {0x44, 0x44, 0x00}, //0x07
    {0x00, 0x00, 0x00}, //0x08
    {0x44, 0x44, 0x00}, //0x09
    {0x00, 0x00, 0x00}, //0x0A
    {0x44, 0x44, 0x00}, //0x0B
    {0x00, 0x00, 0x00}, //0x0C
    {0x44, 0x44, 0x00}, //0x0D
    {0x00, 0x00, 0x00}, //0x0E
    {0x44, 0x44, 0x00}, //0x0F
    {0x00, 0x00, 0x00}, //0x00
    {0x44, 0x44, 0x00}, //0x01
    {0x00, 0x00, 0x00}, //0x02
    {0x44, 0x44, 0x00}, //0x03
    {0x00, 0x00, 0x00}, //0x04
    {0x44, 0x44, 0x00}, //0x05
    {0x00, 0x00, 0x00}, //0x06
    {0x44, 0x44, 0x00}, //0x07
    {0x00, 0x00, 0x00}, //0x08
    {0x44, 0x44, 0x00}, //0x09
    {0x00, 0x00, 0x00}, //0x0A
    {0x44, 0x44, 0x00}, //0x0B
    {0x00, 0x00, 0x00}, //0x0C
    {0x44, 0x44, 0x00}, //0x0D
    {0x00, 0x00, 0x00}, //0x0E
    {0x44, 0x44, 0x00}, //0x0F
    {0x00, 0x00, 0x00}, //0x00
    {0x44, 0x44, 0x00}, //0x01
    {0x00, 0x00, 0x00}, //0x02
    {0x44, 0x44, 0x00}, //0x03
    {0x00, 0x00, 0x00}, //0x04
    {0x44, 0x44, 0x00}, //0x05
    {0x00, 0x00, 0x00}, //0x06
    {0x44, 0x44, 0x00}, //0x07
    {0x00, 0x00, 0x00}, //0x08
    {0x44, 0x44, 0x00}, //0x09
    {0x00, 0x00, 0x00}, //0x0A
    {0x44, 0x44, 0x00}, //0x0B
    {0x00, 0x00, 0x00}, //0x0C
    {0x44, 0x44, 0x00}, //0x0D
    {0x00, 0x00, 0x00}, //0x0E
    {0x44, 0x44, 0x00}, //0x0F
    {0x00, 0x00, 0x00}, //0x00
    {0x44, 0x44, 0x00}, //0x01
    {0x00, 0x00, 0x00}, //0x02
    {0x44, 0x44, 0x00}, //0x03
    {0x00, 0x00, 0x00}, //0x04
    {0x44, 0x44, 0x00}, //0x05
    {0x00, 0x00, 0x00}, //0x06
    {0x44, 0x44, 0x00}, //0x07
    {0x00, 0x00, 0x00}, //0x08
    {0x44, 0x44, 0x00}, //0x09
    {0x00, 0x00, 0x00}, //0x0A
    {0x44, 0x44, 0x00}, //0x0B
    {0x00, 0x00, 0x00}, //0x0C
    {0x44, 0x44, 0x00}, //0x0D
    {0x00, 0x00, 0x00}, //0x0E
    {0x44, 0x44, 0x00}, //0x0F
};

Tia::~Tia(){

}

void Tia::connectBus(Bus *bus){
    this->bus = bus;
}

unsigned char Tia::readMemory(unsigned short address){
    return 0;
}

void Tia::writeMemory(unsigned short address, unsigned char value){
    //do nothing.
}