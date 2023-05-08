#include "stack.h"

Stack::Stack()
{

}

void Stack::push(std::string key, std::string value)
{
    Cell *c = new Cell;
    c->data.first = key;
    c->data.second = value;
    c->next=begin;
    begin=c;
}

bool Stack::isEmpty()
{
    return begin == nullptr;
}

void Stack::pop()
{
    Cell *a;
    if (begin != nullptr)
    {
        a = begin;
        begin = begin->next;
        delete a;
    }
}
