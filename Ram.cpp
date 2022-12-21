#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

#include "Ram.h"
#include "common.h"

using namespace std;


Ram* Ram::getInstance()
{
    static Ram* instance = nullptr;

    if (instance == nullptr) {
        instance = new Ram();
    }

    return instance;
}

Ram::Ram() 
{
    init();
}

void Ram::write(adresse adr, octet valeur)
{
    m_ram[adr] = valeur;
}

octet Ram::read(adresse adr)
{
    return m_ram[adr]; 
}

void Ram::init()
{
    for (int i = 0; i < RAMSIZE; i++) {
        m_ram[i] = 0xCC;
    }

}

octet convert_quartet( char quartet )
{
    if ( quartet >= '0' && quartet <= '9' )
        return quartet - '0';
    else if ( quartet >= 'A' && quartet <= 'F' )
        return quartet - 'A' + 10;
    else
        return 0;
}

void Ram::read_file(adresse adr, string filename)
{
    ifstream file(filename);
    string content;
    octet val1, val2;
    adresse ptr_adr = adr;

    cout << "Lecture du fichier " << filename << endl;
    while(file >> content) {
        cout << ">" << content << endl;

        for (int i = 0; i < content.length(); i += 2) {
            if (i < content.length() - 1 ) {
                val1 = convert_quartet( content.at(i) ) << 4;
                val2 = convert_quartet( content.at(i + 1) );

                write(ptr_adr++, val1 + val2);
            }
        }

    }
}

string hex1(octet val)
{
    char caractere[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int q1, q2;
    string hexa = "00";

    q1 = (val & 0xF0) >> 4;
    q2 = val & 0x0F;
    hexa.at(0) = caractere[q1];
    hexa.at(1) = caractere[q2];

    return(hexa);
}

string hex2(adresse val)
{
    char caractere[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int q1, q2, q3, q4;
    string hexa = "0000";

    q1 = (val & 0xF000) >> 12;
    q2 = (val & 0x0F00) >> 8;
    q3 = (val & 0x00F0) >> 4;
    q4 = val & 0x000F;

    hexa.at(0) = caractere[q1];
    hexa.at(1) = caractere[q2];
    hexa.at(2) = caractere[q3];
    hexa.at(3) = caractere[q4];

    return(hexa);
}

void Ram::dump_ram( adresse start, int len )
{
    adresse debut, fin;

    debut = (start / 16) * 16;
    fin = ((( debut + len ) / 16 * 16) + 16) % RAMSIZE;
    cout << "Dump RAM debut=" << debut << " fin=" << fin << endl;

    for (int pos = debut; pos < fin; pos += 16) {
        cout << hex2(pos) << ' ';
        for (int i = 0; i < 16; i++) {
            cout << hex1(m_ram[pos + i]);
            if (i != 15)
                cout << ' ';
        }
        cout << endl;
    }

    cout << endl;
}
