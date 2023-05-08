#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Vector.cpp"
#include <cstddef>
#include"stack.h"
#include<QtWidgets>

class HashTable
{
public:
    HashTable();
    HashTable(size_t);
    void add(std::string, std::string);
    std::string find(std::string key);
    QString print();
    void remove(std::string key);
    Vector<Stack> hashTable;
    size_t capacity_,size_;

};



#endif // HASHTABLE_H
