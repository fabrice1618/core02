#pragma once

#include "common.h"

#define STACK_SIZE 256

enum stack_status {
    OK,
    EMPTY,
    FULL,
    OVERFLOW,
    UNDERFLOW
};

class Stack
{
private:
    octet stack[STACK_SIZE];
    adresse_page sp;
    enum stack_status status;

public:
    Stack();
//    ~Stack();
    octet pull();
    void push(octet val);
    enum stack_status get_status();
    void debug();
    void dump();
};
