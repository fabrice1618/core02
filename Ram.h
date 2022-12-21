#pragma once
#include <string>

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
    void read_file(adresse adr, std::string filename);
    void dump_ram( adresse start, int len );

private:
    Ram();  // Constructeur caché
    void init();
};
