#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Vector.cpp"
#include <cstddef>

class HashTable
{
public:
    HashTable();
    HashTable(size_t);
    void add(std::string, std::string);
    size_t find(std::string key);
    Vector<std::pair<std::string, std::string>> hashTable;
    size_t capacity_,size_;
};

#endif // HASHTABLE_H
