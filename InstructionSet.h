#pragma once
#include <string>
#include <vector>

#include "common.h"

using namespace std;

enum addressing_mode {
    IMPLIED,
    IMMEDIATE,
    ZEROPAGE,
    ZEROPAGEX,
    ABSOLUTE,
    ABSOLUTEX,
    ABSOLUTEY,
    INDIRECTX,
    INDIRECTY
};


struct Instruction {
    enum addressing_mode adrmode;
    string syntax;
    int hexa;
    int fetch_len;
    int cycles;
};

class InstructionSet {
private:
    vector<struct Instruction> instruction_set;

public:
    InstructionSet();
    void load();
    void list();
    string s_adrmode(enum addressing_mode adrmode);
};

/*
Source :
http://www.6502.org/tutorials/6502opcodes.html

MODE           SYNTAX       HEX LEN TIM
Immediate     ADC #$44      $69  2   2
Zero Page     ADC $44       $65  2   3
Zero Page,X   ADC $44,X     $75  2   4
Absolute      ADC $4400     $6D  3   4
Absolute,X    ADC $4400,X   $7D  3   4+
Absolute,Y    ADC $4400,Y   $79  3   4+
Indirect,X    ADC ($44,X)   $61  2   6
Indirect,Y    ADC ($44),Y   $71  2   5+

MODE           SYNTAX       HEX LEN TIM
Implied       NOP           $EA  1   2
*/