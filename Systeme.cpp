#include <iostream>

#include "Systeme.h"
#include "common.h"


using namespace std;


// Définition
Systeme::Systeme()
{
    //ram = Ram::getInstance();
}

Systeme::~Systeme()
{
    cout << "~Systeme()" << endl;
}

void Systeme::add_cpu()
{
    Cpu* cpu;

    cout << "add_cpu()" << endl;
    
    cpu = new Cpu;
    cpu_list.push_back(cpu);
}

void Systeme::list_cpu()
{
    Cpu* cpu;

    cout << "Liste CPU" << endl;

    for (int i = 0; i < cpu_list.size(); i++) {
        cpu = cpu_list[i];
        cpu->debug();
    }
    
}
