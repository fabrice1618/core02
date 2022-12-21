#include <iostream>

#include "Systeme.h"
#include "Stack.h"
#include "Ram.h"
#include "Cpu.h"
#include "InstructionSet.h"

using namespace std;

void test_cpu()
{
    Cpu cpu;

    cpu.debug();
    cpu.reset(0x1234);
    cpu.debug();
    cpu.clock();
}

int test_stack()
{
    Stack stack;
    octet val;

    cout << "Test stack" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "push: " << (int)i << " " << (int)i*11 << endl;
        stack.push(i*11);
    }

    for (int i = 0; i < 10; i++) {
        val = stack.pull();
        cout << "pull: " << (int)i << " "  << (int)val << endl;
    }

    return 0;
}

void test_ram()
{
    Ram* ram = Ram::getInstance();

    cout << "Writing...." << endl;
    for (int i = 0; i < 10; i++) {
        ram->write(i, i*11);
    }

    for (int i = 0; i < 10; i++) {
        cout << i << ':' << (int)ram->read(i) << endl;
    }
}

void test_ram2()
{
    Ram* ram = Ram::getInstance();

    ram->read_file(0x12, "hello.hex");
    ram->dump_ram(0, 48);

}

void test_systeme()
{
    Systeme systeme;

    cout << "Test systeme" << endl;
    systeme.add_cpu();
    systeme.add_cpu();
    systeme.add_cpu();

    systeme.list_cpu();
}

void test_opcode()
{
    InstructionSet inst_set;

    inst_set.load();
    inst_set.list();

}

int main()
{
    //test_stack();
    //test_ram();
    test_ram2();
    //test_cpu();
    //test_systeme();
//    test_opcode();
}