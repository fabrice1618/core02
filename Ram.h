#pragma once

#include "common.h"

#define RAMSIZE 65536

class Ram
{
private:
    octet m_ram[RAMSIZE];

public:
    static Ram* getInstance();
    void write(adresse adr, octet valeur);
    octet read(adresse adr);

private:
    Ram() {};  // Constructeur caché
};
