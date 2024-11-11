#include "bus.h"
#include <fstream>
#include <cstring>


void Bus::connectCPU(CPU *cpu){
    this->cpu = cpu;
    this->cpu->connectBus(this); 
}

void Bus::connectCartridge(Cartridge *cartridge){
    this->cartridge = cartridge;
    this->cartridge->connectBus(this);
}

unsigned char Bus::readAddress(unsigned short address){
    address &= 0x1FFF; //13 pins
    if(address >= 0x1000){
        //cartridge area
        address &= 0xFFF
        return cartridge->readMemory(address);
    }else{
        address &= 0x3FF;
        if(address >= 0x200){
            address &= 0xFF;
            if(address >= 0x80){
                //RIOT ADDRESS
                address &= 0x1F;
            }else{
                //TIA ADDRESS
                address &= 0x3F;
            }
        }else{
            address &= 0xFF;
            if(address >= 0x80){
                //RIOT RAM
                
            }else{
                //TIA ADDRESS
                address &= 0x3F;
            }
        }
        return 0;
    }
    
}

void Bus::writeAddress(unsigned short address, unsigned char value){
    address &= 0x1FFF; //13 pins
    if(address >= 0x1000){
        //cartridge area
        address &= 0xFFF
        cartridge->readMemory(address);
    }else{
        address &= 0x3FF;
        if(address >= 0x200){
            address &= 0xFF;
            if(address >= 0x80){
                //RIOT ADDRESS
                address &= 0x1F;
            }else{
                //TIA ADDRESS
                address &= 0x3F;
            }
        }else{
            address &= 0xFF;
            if(address >= 0x80){
                //RIOT RAM
                
            }else{
                //TIA ADDRESS
                address &= 0x3F;
            }
        }
    }
}