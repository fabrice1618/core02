#include <iostream>

#include "Cpu.h"
#include "Ram.h"

using namespace std;

// Définition
Cpu::Cpu()
{
    static int cpu_cnt=0;

    running = false;

    cpu_id = cpu_cnt++;
    
}

// Running cpu_state machine :)
void Cpu::clock()
{
    /*
    Ram* ram = Ram::getInstance();
    octet opcode;

    if (cpu_state == FETCH) {
        opcode = ram->read(pc);

    } else if (cpu_state == EXEC) {

    } else if (cpu_state == IDLE) {

    }*/
    
    cout << "Cpu::clock()" << endl;
}

void Cpu::reset( adresse reset_vector )
{
    cout << "Cpu::reset(" << (int)reset_vector << ")" << endl;
    pc = reset_vector;
    cpu_state = FETCH;
    running = true;
}

int Cpu::get_alive()
{
    cout << "Cpu::get_alive()=>" << (int)alive << endl;

    return(alive);
}

void Cpu::debug()
{
    cout << "cpu_id=" << (int)cpu_id << endl;
    cout << "running=" << (int)running << endl;
    cout << "PC=" << (int)pc << endl;
    cout << "alive=" << (int)alive << endl;

}