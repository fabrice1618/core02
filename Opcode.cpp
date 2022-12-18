#include <iostream>
#include <vector>

#include "Opcode.h"

using namespace std;

// Définition
Opcode::Opcode()
{
    
}

void Opcode::load_instruction_set()
{
    struct InstructionSet opcode[256] = { 
        {IMPLIED, "LIV", 0x0F, 1, 2}, 
        {IMPLIED, "KIL", 0x1F, 1, 1},
        {IMPLIED, "NOP", 0xEA, 1, 2}, 
        {IMPLIED, "end", 0, 0, 0} 
    };

    // Lire le jeu d'instructions jusqu'à "end"
    for (int i = 0; i < 256; i++) {
        if ( opcode[i].syntax.compare(string("end")) == 0 ) {
            break;
        }
        instruction_set.push_back(opcode[i]);
    }

}

void Opcode::list_instruction_set()
{
    struct InstructionSet op;

    for (int i = 0; i < instruction_set.size(); i++) {
        op = instruction_set[i];
        cout << "{" << s_adrmode(op.adrmode) << "," << op.syntax << "," << op.hexa << "," << op.fetch_len << "," << op.cycles << "}" << endl;
    }
    
}

string Opcode::s_adrmode(enum addressing_mode adrmode)
{
    switch (adrmode)
    {
    case IMPLIED:
        return "IMPLIED";
        break;
    case IMMEDIATE:
        return "IMMEDIATE";
        break;
    case ZEROPAGE:
        return "ZEROPAGE";
        break;
    case ZEROPAGEX:
        return "ZEROPAGEX";
        break;
    case ABSOLUTE:
        return "ABSOLUTE";
        break;
    case ABSOLUTEX:
        return "ABSOLUTEX";
        break;
    case ABSOLUTEY:
        return "ABSOLUTEY";
        break;
    case INDIRECTX:
        return "INDIRECTX";
        break;
    case INDIRECTY:
        return "INDIRECTY";
        break;
    
    default:
        return "???";
        break;
    }
}
