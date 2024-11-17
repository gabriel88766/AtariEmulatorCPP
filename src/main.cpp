#include <iostream>
#include "6507.hpp"
#include "bus.hpp"
#include "cartridge.hpp"

int main()
{
    Bus bus;
    CPU cpu;
    Cartridge cart;
    cart.connectBus(&bus);
    bus.connectCartridge(&cart);
    cpu.connectBus(&bus);
    bus.connectCPU(&cpu);
    cart.read("ROM/enduro.a26");
    while (true){
        cpu.nextInstruction();
    }
    
}