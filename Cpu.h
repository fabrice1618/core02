#pragma once

#include "common.h"
#include "Stack.h"

enum cpu_states {
    FETCH,
    EXEC,
    IDLE
};

class Cpu
{
private:
    int alive = 0;
    adresse pc;
    bool running = false;
    Stack stack;
    int cpu_id;
    enum cpu_states cpu_state;

public:
    Cpu();
    void clock();
    void reset( adresse reset_vector );
    int get_alive();
    void debug();
};
