#pragma once

#include "common.h"
#include "Stack.h"

class Cpu
{
private:
    int alive = 0;
    adresse pc;
    bool running = false;
    Stack stack;
    int cpu_id;


public:
    Cpu();
    void clock();
    void reset( adresse reset_vector );
    int get_alive();
    void debug();
};
