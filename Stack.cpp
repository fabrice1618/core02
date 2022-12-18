//int stack[100], n=100, top=-1; //define the array and variables
#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack()
{
    sp = 0;
    status = EMPTY;
}

void Stack::push(octet val) 
{
    if (status == FULL) {
        cout << "Stack Overflow" << endl;
        status = OVERFLOW;
    }
   else {
      stack[sp] = val; //add value to stack at the stack pointer
      if (status == EMPTY)
        status = OK;
      if (sp == STACK_SIZE-1) {
        status = FULL;
      }
      sp++; 
   }
}

octet Stack::pull() 
{
    octet val;

    if (status == EMPTY) {
        cout << "Stack Underflow" << endl;
        status = UNDERFLOW;
        return 0;
    } else {
        sp--;
        val = stack[sp];

        if (sp == 0) {
            status = EMPTY;
        }

        if (status == FULL)
            status = OK;

        return( val );
    }
}

enum stack_status Stack::get_status()
{
    return status;
}

void Stack::debug()
{
    cout << "Stack: SP=" << (int)sp << " status=" << (int)status << endl;

}

void Stack::dump()
{
    octet val;

    cout << "dump =>" << endl;

    for (int i = 0; i < sp; i++) {
        val = stack[sp];
        cout << (int)i << ' ' << (int)stack[i] << endl;
    }
}