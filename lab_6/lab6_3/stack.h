#ifndef STACK_H
#define STACK_H
#include<iostream>

class Stack
{
public:
    struct Cell
    {
        std::pair<std::string, std::string> data;
        Cell *next;
        Cell(std::string key, std::string value)
        {
            data.first = key;
            data.second = value;
            next = nullptr;
        }
        Cell():next(nullptr)
        {}
    };
    Stack();
    Cell *begin = nullptr;
    void push(std::string, std::string);
    bool isEmpty();
    void pop();
};

#endif // STACK_H
