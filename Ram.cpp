#include <iostream>
#include <ctime>

#include "Ram.h"

using namespace std;

Ram* Ram::getInstance()
{
    static Ram* instance = nullptr;

    if (instance == nullptr) {
        instance = new Ram();
    }

    return instance;
}

void Ram::write(adresse adr, octet valeur)
{
    m_ram[adr] = valeur;
}

octet Ram::read(adresse adr)
{
    return m_ram[adr]; 
}
