#pragma once

#include <vector>

#include "Cpu.h"

class Systeme
{
private:
    std::vector<Cpu*> cpu_list;

public:
    Systeme();
    ~Systeme();
    void add_cpu();
    void list_cpu();

};
