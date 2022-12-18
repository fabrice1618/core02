#include <iostream>

#include "Cpu.h"

using namespace std;

// Définition
Cpu::Cpu()
{
    static int cpu_cnt=0;

    running = false;

    cpu_id = cpu_cnt++;
    
}

void Cpu::clock()
{
    cout << "Cpu::clock()" << endl;
}

void Cpu::reset( adresse reset_vector )
{
    cout << "Cpu::reset(" << (int)reset_vector << ")" << endl;
    pc = reset_vector;
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